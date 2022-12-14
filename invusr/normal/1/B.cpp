#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxNL = 30;

int n;
char s[MaxNL];

inline void solve()
{
	int row, col;
	if (sscanf(s, "R%dC%d", &row, &col) == 2)
	{
		int cur = 26, sum = 0, len = 1;
		while (sum + cur < col)
			sum += cur, cur *= 26, ++len;
		col -= sum;

		for (int i = len; i; --i)
		{
			cur /= 26;
			for (char c = 'A'; c <= 'Z'; ++c)
			{
				if (cur < col)
					col -= cur;
				else
				{
					putchar(c);
					break;
				}
			}
		}
		printf("%d\n", row);
	}
	else
	{
		int x = row = 0, y = 0;
		while (s[x] < '0' || s[x] > '9')
			++x, ++y;
		while (s[y] > '\0')
			row = row * 10 + s[y++] - '0';

		col = 0;
		for (int i = 0; i < x; ++i)
			col = col * 26 + s[i] - 'A';
		int cur = 1;
		for (int i = 1; i < x; ++i)
			cur *= 26, col += cur;
		printf("R%dC%d\n", row, col + 1);
	}
}

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		solve();
	}

	return 0;
}