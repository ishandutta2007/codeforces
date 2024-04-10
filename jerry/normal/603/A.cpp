#include <bits/stdc++.h>
using namespace std;

int dp[100005][3], b[2][3], n, a;
char x[100005];

int main()
{
	scanf("%d%s", &n, x);
	for (int i = 0;i < n;i++) x[i] -= '0';
	for (int i = n-1;i >= 0;i--)
	{
		for (int j = 0;j < 3;j++)
			if (j) dp[i][j] = max(b[!x[i]][j], b[x[i]][j-1]);
			else dp[i][j] = b[!x[i]][j];
		for (int j = 0;j < 3;j++)
			a = max(a, b[x[i]][j] = max(b[x[i]][j], ++dp[i][j]));
	}
	printf("%d\n", a);
	return 0;
}