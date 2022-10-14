#pragma GCC optimize("unroll-loops")
#pragma comment(linker, "/STACK:26777216")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 6969701591;
const int maxn = 2e5 + 33;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vvi g;
vi sz;
set<pair<int, int>> ans;

void bp(vi& a) {
	bitset<5050> msk(1);
	for(auto i : a)
		msk|=msk<<i;
	int i = msk._Find_next(0);
	while(i < n-1) {
		ans.insert({i, n-i-1});
		ans.insert({n-i-1, i});
		i = msk._Find_next(i);
	}
}

void dfs(int v, int p) {
	sz[v] = 1;
	vi a;
	for(auto i : g[v]) {
		if(i == p) continue;
		dfs(i, v);
		sz[v] += sz[i];
		a.pb(sz[i]);
	}
	a.pb(n-sz[v]);
	bp(a);
}
int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n;
	g.resize(n+1);
	sz.resize(n+1);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfs(1, 1);
	cout << ans.size() << "\n";
	for(auto i : ans)
		cout << i.first << " " << i.second << "\n";
}