#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;/*
int a[100000],c[100000],b[100000],at[100000],k[100000];
void die() { printf("Impossible"); getchar(); getchar(); exit(0); }
int main()
{
	int n,i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)scanf("%d", a + i), a[i] = n - a[i], c[a[i]]++;
	int cnt = 1;
	for (i = 1; i <= n; i++) {
		if (c[i] % i)die();
		if(c[i])at[i] = cnt++;
	}
	for (i = 0; i < n; i++) {
		b[i] = at[a[i]];
		k[a[i]]++;
		if (k[a[i]] % a[i] == 0) {
			if(k[a[i]]!=c[a[i]])at[a[i]] = cnt++;
		}
	}
	printf("Possible\n");
	for (i = 0; i < n; i++)printf("%d ", b[i]);
	getchar(); getchar();
}
*/
ll mod = 998244353;
ll dp[2001][2001];
int main() {
	int n, m, k,i,j;
	scanf("%d%d%d", &n, &m, &k);
	dp[0][0] = m;
	for (i = 1; i < n; i++) {
		dp[i][0] = dp[i - 1][0];
		for (j = 1; j < n; j++) {
			dp[i][j] = (dp[i - 1][j - 1] * (m - 1) + dp[i - 1][j])%mod;
		}
	}
	printf("%lld", dp[n - 1][k]);
	getchar(); getchar();
}