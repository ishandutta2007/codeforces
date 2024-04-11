#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 1e9 + 7 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct dsu {
	vi p, col;
	vi s[maxn];
	int cnt[maxn][2];
	ll ans = 0;
	int n, good;
	dsu(int _n) : n(_n) {
		good = 1;
		memset(cnt, 0, sizeof cnt);
		p.resize(n+1);
		col.resize(n+1);
		for(int i = 1; i <= n; i++) {
			p[i] = i;
			cnt[i][0] = 1;
			s[i] = {i};
		}
	}
	int par(int i) {
		return p[i] == i ? i : p[i] = par(p[i]);
	}
	int cans(int i) {
		return min(cnt[i][0], cnt[i][1]);
	}
	void unite(int i, int j, int k) {
		int t = col[i]^col[j]^k;
		i = par(i), j = par(j);
		if(i == j) {
			good &= t == 0;
			return;
		}
	    //cout << i << " " << j << " " << k << " " << cans(i) << " " << cans(j) << "\n";
		ans -= cans(i), ans -= cans(j);
		if(s[i].size() < s[j].size()) swap(i, j);
		for(auto &a : s[j]) {
			cnt[i][col[a] ^= t]++;
			s[i].pb(a);
		}
		p[j] = i;
		ans += cans(i);
		//cout << i << " " << cnt[i][0] <<" " << cnt[i][1] << '\n';
		//cout << ans << '\n';
	}
	void append(int i, vi &ans) {
		int a = cnt[i][0]>cnt[i][1];
		for(auto x : s[i]) if(col[x]==a) ans.pb(x);
	}
};
int n, m;
vector<array<int, 3>> edges;
pair<ll, vi> solve() {
	dsu d(n);
	for(auto &i : edges) {
		d.unite(i[0], i[1], i[2]);
		if(!d.good) return {1ll<<60, vi()};
	}
	vi res;
	for(int i = 1; i <= n; i++) if(d.par(i)==i) d.append(i, res);
	return {d.ans, res};
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	char c;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		c = c=='B';
		edges.pb({f, t, c});
	}
	auto ans = solve();
	for(auto &i : edges) i[2]^=1;
	ans = min(ans, solve());
	if(ans.first == 1ll<<60) return cout << -1, 0;
	cout << ans.first << '\n';
	for(auto &i : ans.second) cout << i << " ";
}