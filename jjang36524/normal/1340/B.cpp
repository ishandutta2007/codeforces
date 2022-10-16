#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <set>
using namespace std;
int N, K, T;
int dp[2001][2001];
int ma[2001][2001];
int arr[2001];
int num[10] = { 119,36,93,109,46,107,123,37,127,111 };
char ar[10];
int dd(int n, int kk)
{
	dp[n][kk] = 0;
	if (n == N && kk == 0)
		return 1;
	if (n == N)
		return 0;
	int hi = 0;
	int k;
		for (k = 0; k < 10; k++)
		{
			int poss = arr[n]|num[k];
			poss = (poss == num[k]);
			if (!poss)
				continue;
			int l;
			int p = 0;
			for (l = 0; l < 7; l++)
			{
				if ((num[k] & (1 << l)) && !(arr[n] & (1 << l)))
					p++;
			}
			if (p <= kk)
			{
				if (dp[n + 1][kk - p] == 0)
					continue;
				if (dp[n + 1][kk - p] == 1)
				{
					dp[n][kk] = 1;
					hi = k;
				}
				else if (dd(n + 1, kk - p))
				{
					dp[n][kk] = 1;
					hi = k;
				}
			}
		}
		ma[n][kk] = hi;
	return dp[n][kk];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	memset(dp, -1, sizeof(dp));
	cin >> N >> K;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> ar;
		int j;
		int ap = 0;
		for (j = 0; j < 7; j++)
		{
			ap += (ar[j] - '0') * (1 << j);
		}
		
		arr[i] = ap;
	}
	dd(0, K);
	if (dp[0][K] == 0)
	{
		cout << -1;
		return 0;
	}
	pair<int, int>nop = { 0,K };
	for (i = 0; i < N; i++)
	{
		cout << ma[nop.first][nop.second];
		
		int p = 0, l;
		for (l = 0; l < 7; l++)
		{
			if ((num[ma[nop.first][nop.second]] & (1 << l)) && !(arr[i] & (1 << l)))
				p++;
		}
		nop.second -= p;
		nop.first++;
	}
}