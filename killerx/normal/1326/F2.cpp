#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;

const int mxn = 18;

int n;
bool adj[mxn][mxn];
ll dp[1 << mxn][mxn];
std::vector <ll> f[mxn + 1];
std::vector <ll> ans;
int cnt[mxn + 1];

void FMT(std::vector <ll> &f) {
	rep(i, n)
		rep(j, f.size())
			if (j >> i & 1)
				f[j] += f[j ^ 1 << i];
}

void solve(int k, int sum, int las, const std::vector <ll> &dp, const std::vector <ll> &dp1) {
	if (sum == n) {
		ll coef = 0;
		rep(i, 1 << n) {
			if ((n - __builtin_popcount(i)) & 1) coef -= dp1[i];
			else coef += dp1[i];
		}
		rep(i, 1 << (n - 1)) ans[i] += dp[i] * coef;
		return ;
	}
	for (int x = las; x + sum <= n; ++ x) if (x + sum == n || x + sum + x <= n) {
		std::vector <ll> ndp(1 << (sum + x - 1));
		rep(mask, dp.size()) if (dp[mask]) {
			rep(i, sum) if ((mask >> i & 1) == 0) {
				int nmask = mask >> i << (i + x);
				nmask |= mask & ((1 << i) - 1);
				nmask |= ((1 << (x - 1)) - 1) << (i + 1);
				ndp[nmask] += dp[mask];
			}
			int nmask = mask << x;
			nmask |= (1 << (x - 1)) - 1;
			ndp[nmask] += dp[mask];
		}
		rep(i, ndp.size()) ndp[i] /= cnt[x] + 1;
		std::vector <ll> ndp1(1 << n);
		rep(i, 1 << n) ndp1[i] = dp1[i] * f[x][i];
		++ cnt[x];
		solve(k + 1, sum + x, x, ndp, ndp1);
		-- cnt[x];
	}
}

void write(ll x) {
	if (x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}

void write(ll x, char ch) {
	write(x);
	putchar(ch);
}

int main() {
	scanf("%d", &n);
	rep(i, n) {
		char s[mxn + 5];
		scanf("%s", s);
		rep(j, n) adj[i][j] = s[j] == '1';
	}
	rep(i, n) dp[1 << i][i] = 1;
	rep(mask, 1 << n) rep(i, n) if (dp[mask][i])
		rep(j, n) if (!(mask >> j & 1) && adj[i][j])
			dp[mask | 1 << j][j] += dp[mask][i];
	rep(i, n + 1) f[i].resize(1 << n);
	rep(mask, 1 << n) rep(i, n) f[__builtin_popcount(mask)][mask] += dp[mask][i];
	rep(i, n + 1) FMT(f[i]);
	ans.resize(1 << (n - 1));
	solve(0, 0, 1, {1}, std::vector <ll> (1 << n, 1));
	for (int i = n - 1; ~i; -- i)
		for (int j = ans.size() - 1; ~j; -- j)
			if (j >> i & 1)
				ans[j ^ 1 << i] -= ans[j];
	rep(i, 1 << (n - 1)) write(ans[i], i + 1 == (1 << (n - 1)) ? '\n' : ' ');;
	return 0;
}