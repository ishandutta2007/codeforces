#include <cstdio>

char a[222];

int main()
{
	int x, y, r = 0;
	int i, j, k, n;
	scanf("%d%s", &n, a);
	for (i = 0; i < n; i++) for (j = i; j < n; j++)
	{
		x = y = 0;
		for (k = i; k <= j; k++)
		{
			if (a[k] == 'U') x--;
			if (a[k] == 'D') x++;
			if (a[k] == 'L') y--;
			if (a[k] == 'R') y++;
		}
		if (x == 0 && y == 0) r++;
	}
	printf("%d", r);
}