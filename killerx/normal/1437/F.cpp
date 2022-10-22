#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 998244353;

int n, a[5005], f[5005][5005], s[5005][5005];

int P(int n, int m) {
	int ans = 1;
	rep(i, m) ans = 1LL * ans * (n - i) % mod;
	return ans;
}

int main() {
	cin >> n;
	rep(i, n) cin >> a[i];
	sort(a, a + n);
	rep(i, n) {
		int cnt = upper_bound(a, a + n, a[i] / 2) - a;
		rep(j, cnt + 1) {
//			rep(ni, cnt) {
//				rep(nj, j) if (f[ni][nj]) {
//					(f[i][j] += 1LL * f[ni][nj] * P(cnt - nj - 1, j - nj - 1) % mod) %= mod;
//				}
//			}
			if (cnt) {
//				rep(nj, j) if (s[cnt - 1][nj]) {
//					(f[i][j] += 1LL * s[cnt - 1][nj] * P(cnt - nj - 1, j - nj - 1) % mod) %= mod;
//				}
				if (j) {
					(f[i][j] += 1LL * f[i][j - 1] * (cnt - j + 1) % mod) %= mod;
					(f[i][j] += s[cnt - 1][j - 1]) %= mod;
				}
			}
		}
		int e = 1;
		rep(j, cnt + 1) {
			(f[i][j] += e) %= mod;
			s[i][j] = ((i ? s[i - 1][j] : 0) + f[i][j]) % mod;
			e = 1LL * e * (cnt - j) % mod;
		}
	}
	printf("%d\n", f[n - 1][n - 1]);
	return 0;
}