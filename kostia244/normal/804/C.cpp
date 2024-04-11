#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 5e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, m, ccol[maxn], chi[maxn];
vi g[maxn];
vi cols[maxn];
vi h;
int mx = 1;

void dfs(int v, int p, int c = 1) {
//	cout << v << ": ";
	oset t;
	for(auto i : cols[v]) {
//		cout << i << " ";
		if(ccol[i]!=-1) t.insert(ccol[i]);
	}
	int x = 1;
	for(auto i : cols[v]) {
		if(ccol[i]==-1) {
			while(t.find(x)!=t.end()) x++;
			t.insert(ccol[i]=x);
		}
	}
//	cout << "\n";
	for(auto i : g[v]) {
		if(i==p) continue;
		dfs(i, v, c);
	}
	mx = max(mx, c-1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(ccol, -1, sizeof ccol);
	cin >> n >> m;
	vi p;
	for(int s, i = 1; i <= n; i++) {
		cin >> s;
		for(int t, j = 0; j < s; j++) {
			cin >> t;
			cols[i].pb(t);
		}
		p.pb(i);
	}
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	int r = 1;
	for(int i = 2; i <= n; i++) {
		if(g[i].size()>g[r].size()) r = i;
	}
	dfs(r, r);
	for(int i = 1; i <= m; i++) {
		if(ccol[i]==-1) ccol[i] = 1;
		mx = max(mx, ccol[i]);
	}
	cout << mx << "\n";
	for(int i = 1; i <= m; i++)
		cout << ccol[i] << " ";
	return 0;
}