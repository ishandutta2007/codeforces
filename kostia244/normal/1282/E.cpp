//#pragma GCC optimize("trapv")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
//using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const int maxn = 3e5 + 33, mlg = 18, mod = 1e9 + 7;\
vector<vi> g, gt;
vi p;
bitset<maxn> vis;
void dfs(int v = 1) {
	p.pb(v);
	vis[v] = 1;
	for(auto i : g[v]) {
		if(!vis[i]) dfs(i);
	}
}
void dec(set<pi> &z, vi &deg, int x) {
	z.erase({deg[x], x});
	z.insert({--deg[x], x});
}
void solve() {
	int n, a, b, c;
	p.clear();
	g.clear();
	gt.clear();
	vis = 0;
	cin >> n;
	g.resize(n+1);
	gt.resize(n+1);
	vi deg(n+1);
	map<pi, int> cnt;
	vi t(3);
	map<vi, int> id;
	for(int i = 2; i < n; i++) {
		cin >> t[0] >> t[1] >> t[2];
		sort(all(t));
		id[t] = i-1;
		a = t[0], b = t[1], c = t[2];
		deg[a]++;
		deg[b]++;
		deg[c]++;
		cnt[{a, b}]++;
		cnt[{b, c}]++;
		cnt[{a, c}]++;
	}
	for(auto i : cnt) {
		if(i.second==1){
			g[i.first.first].pb(i.first.second);
			g[i.first.second].pb(i.first.first);
		}
		gt[i.first.first].pb(i.first.second);
		gt[i.first.second].pb(i.first.first);
	}
	dfs();
	set<pi> z;
	for(int i = 1; i <= n; i++)
		z.insert({deg[i], i});
	bitset<maxn> usd;
	vi ans;
	while(z.size()>2) {
		int i = z.begin()->second;
		z.erase(z.begin());
		vi x {i};
		usd[i] = 1;
		for(auto to : gt[i]) {
			if(usd[to]) continue;
			dec(z, deg, to);
			x.pb(to);
		}
		sort(all(x));
		ans.pb(id[x]);
	}
	for(auto i : p) cout << i << " "; cout << "\n";
	for(auto i : ans) cout << i << " "; cout << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) solve();
}