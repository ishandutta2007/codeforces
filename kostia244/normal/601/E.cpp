#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxw = 1e3 + 3, maxq = 3e4 + 100, mod = 1e9 + 7;
int updi[maxq], updv[maxq], sz = 0;
int dp[15500][maxw], n, k, q;
int ans[maxq], on[maxq + 5030], w[maxq + 5030], v[maxq + 5030], items = 1;
vi t[4 * maxq];
int add(int a) {
	if (a < 0)
		a += mod;
	return a;
}
template<typename ... T>
int add(int a, T ... args) {
	if (a < 0)
		a += mod;
	a += add(args...);
	if (a >= mod)
		a -= mod;
	return a;
}
int mul(int a) {
	return a;
}
template<typename ... T>
int mul(int a, T ... args) {
	return (a * 1ll * mul(args...)) % mod;
}

void add(int v, int l, int r, int ql, int qr, int i) {
	if (l > qr || ql > r)
		return;
	if (ql <= l && r <= qr) {
		t[v].pb(i);
		return;
	}
	int mid = (l + r) >> 1;
	add(v << 1, l, mid, ql, qr, i);
	add(v << 1 | 1, mid + 1, r, ql, qr, i);
}
vi cur;
void dfs(int pos, int l, int r) {
	for (int K = 1; sz&&K <= k; K++) {
		dp[sz][K] = dp[sz - 1][K];
	}
	for (auto i : t[pos]) {
		for (int K = k+1; K-->w[i];) {
			dp[sz][K] = max(dp[sz][K], dp[sz][K-w[i]]+v[i]);
		}
	}
	if (l == r) {
		if(ans[l]) {
			ll x = 0, c = 1, t = 1e7 + 19;
			for(int i = 1; i <= k; i++) {
				x = (x+c*dp[sz][i])%mod;
				c = (c*t)%mod;
			}
			cout << x << "\n";
		}
	} else {
		int mid = (l + r) >> 1;
		sz++;
		dfs(pos << 1, l, mid);
		dfs(pos << 1 | 1, mid + 1, r);
		sz--;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(on, -1, sizeof on);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> v[items] >> w[items];
		on[items++] = 0;
	}
	int t, x;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> v[items] >> w[items];
			on[items++] = i;
		} else if (t == 2) {
			cin >> x;
			add(1, 0, q, on[x], i, x);
			on[x] = -1;
		} else {
			ans[i] = 1;
		}
	}
	for (int i = 1; i <= maxq; i++)
		if (on[i] != -1)
			add(1, 0, q, on[i], q, i);
	dfs(1, 0, q);
}