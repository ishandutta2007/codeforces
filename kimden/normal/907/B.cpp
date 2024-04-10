// summan
// ConsoleApplication2.cpp:      .
//#define _CRT_SECURE_NO_WARNINGS
//#include "stdafx.h"
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <stack>
#include <list>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
	char h[9][9];
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			char kk;
			scanf("%c", &kk);
			while (kk==' ' || kk == '\n') scanf("%c", &kk);
			h[i][j] = kk;
		}
	}
	int x, y;
	cin >> x >> y;

	int a = x % 3; if (a == 0) a = 3;
	int b = y % 3; if (b == 0) b = 3;

	int n1, n2, m1, m2;
	n1 = (a - 1) * 3;
	n2 = a * 3;
	m1 = (b - 1) * 3;
	m2 = b * 3;

	int l = 0;
	for (int i = n1; i < n2; i++)
	{
		for (int j = m1; j < m2; j++)
		{
			if (h[i][j] == '.')
			{
				h[i][j] = '!';
			}
			else l++;
		}
	}

	if (l == 9)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (h[i][j] == '.')
				{
					h[i][j] = '!';
				}
			}
		}
	}


	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << (h[i][j]);
			if (j == 2 || j == 5) cout << " ";
			if (j == 8) cout << endl;
			if ((i == 2 && j == 8) || (i == 5 && j == 8) || (i == 8 && j == 8)) cout << endl;
		}
	}
//	system("pause"); //   ,   MS Visual Studio
	return 0;
}