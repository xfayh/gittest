// testtime.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct tm tmL { 0 };
	tmL.tm_year = 2019-1900;
	tmL.tm_mon = 1-1;
	tmL.tm_mday = 9;
	tmL.tm_hour = 11-1;
	tmL.tm_min = 30-1;
	tmL.tm_sec = 20;

	struct tm tmR { 0 };
	tmR.tm_year = 2019 - 1900;
	tmR.tm_mon = 1-1;
	tmR.tm_mday = 10;
	tmR.tm_hour = 12-1;
	tmR.tm_min = 31-1;
	tmR.tm_sec = 21;
	time_t nSecL = mktime(&tmL);
	time_t nSecR = mktime(&tmR);
	time_t nSec = nSecR - nSecL;


	int nTimes = 0;
	while (nTimes++ <= 240)
	{
		//struct tm *pTmBegin = NULL;
		//time_t timestamp = time(NULL) + 3;//加3s
		//pTmBegin = localtime(&timestamp);
		/*int frame = 0;
		int second = pTmBegin->tm_sec;
		int minute = pTmBegin->tm_min;
		int hour = pTmBegin->tm_hour;
		int day = pTmBegin->tm_mday;
		int month = pTmBegin->tm_mon + 1;
		int year = pTmBegin->tm_year + 1900;
		int yearUnits = year % 100;
		int yearTens = year / 100;*/


		struct tm oTmBegin;
		time_t timestamp = time(NULL) + 3;//加3s
		errno_t err = localtime_s(&oTmBegin, &timestamp);
		if (err == 0)
		{
			int frame = 0;
			int second = oTmBegin.tm_sec;
			int minute = oTmBegin.tm_min;
			int hour = oTmBegin.tm_hour;
			int day = oTmBegin.tm_mday;
			int month = oTmBegin.tm_mon + 1;
			int year = oTmBegin.tm_year + 1900;
			int yearUnits = year % 100;
			int yearTens = year / 100;
			printf("%.4d-%.2d-%.2d %.2d:%.2d:%.2d:%.2d\r\n", yearTens * 100 + yearUnits, month, day, hour, minute, second, frame);
		}
	
		Sleep(980);
	}


	system("pause");
}

