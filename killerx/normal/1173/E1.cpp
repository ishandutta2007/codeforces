#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
#define pb push_back
#define mp make_pair
using ll = long long;
using vi = vector <int>;
using pii = pair <int, int>;
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (auto it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == 45) f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - 48;
	return f ? x : -x;
}

int qp(int x, int n) {return !n ? 1 : 1LL * qp(1LL * x * x % mod, n >> 1) * (n & 1 ? x : 1) % mod;}
int inv(int x) {return qp(x, mod - 2);}
int n, m;
int a[55], w[55];
int dp[55][55][55][55];
int main() {
	n = read(), m = read();
	rep(i, n) a[i] = read();
	int sum = 0, like = 0;
	rep(i, n) w[i] = read(), sum += w[i], like += w[i] * a[i];
	rep(i, n) dp[0][0][i][0] = 1;
	rep(i, m) rep(j, i + 1) {
		int nwsum = sum + j - (i - j);
		int invnwsum = inv(nwsum);
		rep(k, n) rep(l, i + 1) {
			if (!dp[i][j][k][l]) continue;
			int nwlike = like + j;
			rep(sel, 2) {
				int nj = j + sel;
				int ful = sel ? nwlike : nwsum - nwlike;
				int nwk = l * (a[k] ? 1 : -1) + w[k];
				if (nwk <= 0) continue;
				if (sel == a[k]) ful -= nwk;
				(dp[i + 1][nj][k][l] += 1LL * dp[i][j][k][l] * ful % mod * invnwsum % mod) %= mod;
				if (sel == a[k]) (dp[i + 1][nj][k][l + 1] += 1LL * dp[i][j][k][l] * nwk % mod * invnwsum % mod) %= mod;
			}
		}
	}
	rep(i, n) {
		int ans = 0;
		rep(j, m + 1) rep(l, m + 1) {
			(ans += 1LL * (l * (a[i] ? 1 : -1) + w[i]) * dp[m][j][i][l] % mod) %= mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}