#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
#include<bits/stdc++.h>
#define int ll
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxw = 3e3 + 30, maxq = 6e3 + 100, mod = 1e9 + 7;
int updi[maxq], updv[maxq], sz = 0;
int dp[15500][maxw], n, k, q;
int ans[maxq], on[maxq + 5030], w[maxq + 5030], v[maxq + 5030], items = 1;
vi t[4 * maxq];
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
ll RES = 0, KK;
vector<int> ar[3003];
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
		if(l < 1 || l > n) return;
		ll cur = 0;
		for(int i = 0; i <= KK; i++) {
			RES = max(RES, cur + dp[sz][KK-i]);
			if(i < ar[l].size()) cur += ar[l][i];
		}
	} else {
		int mid = (l + r) >> 1;
		sz++;
		dfs(pos << 1, l, mid);
		dfs(pos << 1 | 1, mid + 1, r);
		sz--;
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(on, -1, sizeof on);
	cin >> n >> k;KK = k;
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		ar[i].resize(t);
		ll sm = 0;
		for(auto &j : ar[i]) cin >> j, sm += j;
		if(ar[i].size() <= KK) {
		v[items] = sm;
		w[items] = ar[i].size();
		add(1, 0, n+3, 0, i-1, items);
		add(1, 0, n+3, i+1, n+3, items);
		items++;
		}
	}
	dfs(1, 0, n+3);
	cout << RES << '\n';
}