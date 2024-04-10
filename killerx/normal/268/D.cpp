#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++ i)
const int mod = 1e9 + 9;
int qp(int x, int n) {
	return !n ? 1 : 1LL * qp(1LL * x * x % mod, n >> 1) * (n & 1 ? x : 1) % mod;
}

int dp1[2][35];
int dp2[2][35][35];
int dp3[2][35][35][35];
int dp4[2][35][35][35][35];

int main() {
//	cerr << sizeof(dp) / 1024.0 / 1024.0 << endl;
	int n, h;
	cin >> n >> h;
	int ans = 0;
	int p, q;
	p = 0, q = 1;
	dp1[0][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		rep(h1, h) {
			int nw = dp1[p][h1];
			if (!nw) continue;
			(dp1[q][0] += nw) %= mod;
			(dp1[q][h1 + 1] += 3LL * nw % mod) %= mod;
		}
		swap(p, q);
		memset(dp1[q], 0, sizeof dp1[q]);
	}
	rep(h1, h) (ans += 4LL * dp1[p][h1] % mod) %= mod;
	p = 0, q = 1;
	dp2[0][0][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		rep(h1, h) rep(h2, h) {
			int nw = dp2[p][h1][h2];
			if (!nw) continue;
			(dp2[q][0][h2 + 1] += nw) %= mod;
			(dp2[q][h1 + 1][0] += nw) %= mod;
			(dp2[q][h1 + 1][h2 + 1] += 2LL * nw % mod) %= mod;
		}
		swap(p, q);
		memset(dp2[q], 0, sizeof dp2[q]);
	}
	rep(h1, h) rep(h2, h) (ans += mod - 6LL * dp2[p][h1][h2] % mod) %= mod;
	p = 0, q = 1;
	dp3[0][0][0][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		rep(h1, h) rep(h2, h) rep(h3, h) {
			int nw = dp3[p][h1][h2][h3];
			if (!nw) continue;
			(dp3[q][0][h2 + 1][h3 + 1] += nw) %= mod;
			(dp3[q][h1 + 1][0][h3 + 1] += nw) %= mod;
			(dp3[q][h1 + 1][h2 + 1][0] += nw) %= mod;
			(dp3[q][h1 + 1][h2 + 1][h3 + 1] += nw) %= mod;
		}
		swap(p, q);
		memset(dp3[q], 0, sizeof dp3[q]);
	}
	rep(h1, h) rep(h2, h) rep(h3, h) (ans += 4LL * dp3[p][h1][h2][h3] % mod) %= mod;
	p = 0, q = 1;
	dp4[0][0][0][0][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		rep(h1, h) rep(h2, h) rep(h3, h) rep(h4, h) {
			int nw = dp4[p][h1][h2][h3][h4];
			if (!nw) continue;
			(dp4[q][0][h2 + 1][h3 + 1][h4 + 1] += nw) %= mod;
			(dp4[q][h1 + 1][0][h3 + 1][h4 + 1] += nw) %= mod;
			(dp4[q][h1 + 1][h2 + 1][0][h4 + 1] += nw) %= mod;
			(dp4[q][h1 + 1][h2 + 1][h3 + 1][0] += nw) %= mod;
		}
		swap(p, q);
		memset(dp4[q], 0, sizeof dp4[q]);
	}
	rep(h1, h) rep(h2, h) rep(h3, h) rep(h4, h) (ans += mod - dp4[p][h1][h2][h3][h4]) %= mod;
	printf("%d\n", ans);
	return 0;
}