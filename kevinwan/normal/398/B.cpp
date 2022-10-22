#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
double dp[2001][2001];
int n, m;
bool f[2001], s[2001];
double solve(int a, int b) {
	if (a > n || b > n)return 0;
	if (dp[a][b] != 0)return dp[a][b];
	if (a == n && b == n)return 0;
	return dp[a][b]=((n - a)*b*solve(a + 1, b) + (n - b)*a*solve(a, b + 1) + (n - b)*(n - a)*solve(a + 1, b + 1) + n * n) / (n*n - a * b);
}
int main() {
	int i,a,b;
	scanf("%d%d", &n, &m);
	for (i = 0; i < m; i++)scanf("%d%d", &a, &b), f[a] = 1, s[b] = 1;
	a = b = 0;
	for (i = 1; i <= n; i++)a += f[i],b+=s[i];
	printf("%lf", solve(a, b));
}