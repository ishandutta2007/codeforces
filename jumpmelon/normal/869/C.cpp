#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long big;

const int MAXN = 5000, P = 998244353;
int Dp[MAXN + 10][MAXN + 10];

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	fill(Dp[0], Dp[0] + MAXN + 1, 1);
	for(int i = 1; i <= MAXN; i++)
	{
		Dp[i][0] = Dp[i - 1][0];
		for(int j = 1; j <= MAXN; j++)
			Dp[i][j] = (Dp[i - 1][j] + (big)Dp[i - 1][j - 1] * j % P) % P;
	}
	printf("%lld\n", (big)Dp[a][b] * Dp[a][c] % P * Dp[b][c] % P);
	return 0;
}