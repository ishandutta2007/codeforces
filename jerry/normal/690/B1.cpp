#include <bits/stdc++.h>
using namespace std;

char buf[64][64];
int n;

void fail()
{
	printf("No\n");
	exit(0);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%s", buf[i]);
	int u = 0;
	for (;u < n;u++)
	{
		bool has = false;
		for (int i = 0;i < n;i++) if (buf[u][i] != '0') has = true;
		if (has) break;
	}
	if (u == n) fail();
	int d = n-1;
	for (;d >= 0;d--)
	{
		bool has = false;
		for (int i = 0;i < n;i++) if (buf[d][i] != '0') has = true;
		if (has) break;
	}
	int l = 0;
	for (;l < n;l++)
	{
		bool has = false;
		for (int i = 0;i < n;i++) if (buf[i][l] != '0') has = true;
		if (has) break;
	}
	int r = n-1;
	for (;r >= 0;r--)
	{
		bool has = false;
		for (int i = 0;i < n;i++) if (buf[i][r] != '0') has = true;
		if (has) break;
	}
	if (u == d || l == r) fail();
	for (int i = 0;i < n;i++) for (int j = 0;j < n;j++)
		if (u <= i && i <= d && l <= j && j <= r)
		{
			int num = 0;
			if (i == u) num++;
			if (i == d) num++;
			if (j == l) num++;
			if (j == r) num++;
			if (num == 2 && buf[i][j] != '1') fail();
			if (num == 1 && buf[i][j] != '2') fail();
			if (num == 0 && buf[i][j] != '4') fail();
		} else if (buf[i][j] != '0') fail();
	printf("Yes\n");
	return 0;
}