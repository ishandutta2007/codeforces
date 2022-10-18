#include <bits/stdc++.h>
using namespace std;

#define FOR(i, b, e) for(int i = (b); i < (e); i++)
#define SZ(x) ((int)x.size())

using vi = vector<int>;
constexpr int mod = 998'244'353;
constexpr int N = 5010;

int fact[N], ifact[N], dp[N], cnt[N];

int pov(int base, int exp = mod - 2) {
	int ret = 1;
	for(; exp; exp >>= 1) {
		if(exp & 1) ret = 1ll * ret * base % mod;
		base = 1ll * base * base % mod;
	}
	return ret;
}

int binom(int n, int k) {
	if(k < 0 || k > n) return 0;
	return 1ll * fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

void solve() {
	int n, m = -1, last = -1;
	cin >> n;
	FOR(i, 0, n + 1) dp[i] = cnt[i] = 0;
	FOR(i, 0, n) {
		int a;
		cin >> a;
		if(a != last) m++;
		cnt[m]++;
		last = a;
	}
	int x = 0;
	dp[0] = 1;
	for(int akt = m; akt >= 0; akt--) {
		int k = cnt[akt];
		for(int s = n / 2; s >= 0; s--) {
			int z = s * 2 - x - 1 + (s == n / 2) + (s == 0);
			dp[s + 1] = (dp[s + 1] + 1ll * dp[s] * binom(z, k - 1)) % mod;
			dp[s] = 1ll * dp[s] * binom(z, k) % mod;
		}
		x += k;
	}
	cout << dp[n / 2] << '\n';
}

void prep() {
	fact[0] = 1;
	FOR(i, 1, N) fact[i] = 1ll * fact[i - 1] * i % mod;
	FOR(i, 0, N) ifact[i] = pov(fact[i]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	prep();
	int tt; cin >> tt;
	FOR(te, 0, tt) solve();
	return 0;
}