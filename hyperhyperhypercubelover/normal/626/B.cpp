#include <cstdio>

char d[202][202][202];
char t[202];

int main()
{
	int n, m, l;
	int i, j, k, x;
	scanf("%*d%s", t);
	n = m = l = 0;
	for (i = 0; t[i]; i++)
	{
		if (t[i] == 'B') n++;
		if (t[i] == 'G') m++;
		if (t[i] == 'R') l++;
	}
	d[1][0][0] = 1;
	d[0][1][0] = 2;
	d[0][0][1] = 4;
	for (x = 0; x <= 200;x++) for (i = 0; i <= 200; i++) for (j = 0; j <= 200; j++)
	{
		k = x - i - j;
		if (k < 0 || k>200) continue;
		if (i >= 2) d[i][j][k] |= d[i - 1][j][k];
		if (j >= 2) d[i][j][k] |= d[i][j - 1][k];
		if (k >= 2) d[i][j][k] |= d[i][j][k - 1];
		if (i && j) d[i][j][k] |= d[i - 1][j - 1][k + 1];
		if (i && k) d[i][j][k] |= d[i - 1][j + 1][k - 1];
		if (j && k) d[i][j][k] |= d[i + 1][j - 1][k - 1];
	}
	if (d[n][m][l] & 1) putchar('B');
	if (d[n][m][l] & 2) putchar('G');
	if (d[n][m][l] & 4) putchar('R');
}