#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

#define ld long double
#define eps 1e-9

int n, lim, ini;
ld p[205];
int a[205];
int id[205];
ld dp[2][205][205];

bool cmp(int x, int y) {
	return a[x] == a[y] ? x < y : a[x] > a[y];
}

int main() {
	n = read(), lim = read(), ini = read();
	rep(i, n) p[i] = read() / 100.0;
	rep(i, n) a[i] = read();
	rep(i, n) id[i] = i;
	sort(id, id + n, cmp);
	int p1 = 0, p2 = 1;
	dp[0][0][ini] = 1;
	rep(ii, n) {int i = id[ii];
		rep(j, n + 1) rep(k, 205) {
			ld rem = dp[p1][j][k];
			dp[p2][j][k] += rem * (1 - p[i]);
			if (k + a[i] >= 0) dp[p2][j + 1][min(k + a[i], 200)] += rem * p[i];
		}
		p1 ^= 1, p2 ^= 1;
		memset(dp[p2], 0, sizeof dp[p2]);
	}
	ld ans = 0;
	rep(j, n + 1) if (j >= lim) rep(k, 205) ans += dp[p1][j][k];
	printf("%.9Lf\n", ans);
	return 0;
}