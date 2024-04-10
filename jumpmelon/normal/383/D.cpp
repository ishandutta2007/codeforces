#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000, MAXX = 10010, P = 1000000007;
int A[MAXN + 10], Dp[MAXN + 10][(MAXX << 1) + 10];

int main()
{
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	memset(Dp, 0, sizeof(Dp));
	Dp[n][MAXX] = 1;
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = 0; j < (MAXX << 1); j++)
		{
			if(j - A[i] >= 0)
				(Dp[i][j] += Dp[i + 1][j - A[i]]) %= P;
			if(j + A[i] < (MAXX << 1))
				(Dp[i][j] += Dp[i + 1][j + A[i]]) %= P;
		}
		(ans += Dp[i][MAXX]) %= P;
		(++Dp[i][MAXX]) %= P;
	}
	printf("%d\n", ans);
	return 0;
}