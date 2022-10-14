#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops,no-stack-protector")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 3e5 + 10, mlg = 17, mod = 1e9 + 7;
ll n, q, d[maxn][2];
vpi g[maxn];
void dfs(int v, int p, int c) {
	for(auto t : g[v]) {
		int i = t.first, w = t.second;
		if(i==p) continue;
		d[i][c] = d[v][c] + w;
		dfs(i, v, c);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> q;
	for(int f, t, c,  i=1; i < n; i++) {
		cin >> f >> t >> c;
		g[f].pb({t, c});
		g[t].pb({f, c});
	}
	dfs(1, 1, 0);
	dfs(n, n, 1);
	vpi t;
	multiset<ll> s;
	set<int> add;
	ll seg = 0;

	for(int i = 1; i <= n; i++) t.pb({d[i][0], i});
	sort(rall(t));
	ll dist = 0;
	for(auto T : t) {
		int i = T.second;
		for(auto j : g[i]) {
			int t = j.first;
			if(add.count(t)) {
				s.erase(s.find(d[t][1]));
			}
		}
		if(!s.empty()) {
			seg = max(seg, T.first+*s.rbegin());
		}
		for(auto j : g[i]) {
			int t = j.first;
			if(add.count(t)) {
				s.insert(d[t][1]);
			}
		}
		add.insert(i);
		s.insert(d[i][1]);
	}
	for(int x, i = 0; i < q; i++) {
		cin >> x;
		cout << min(d[n][0], seg+x) << '\n';
	}
	return 0;
}