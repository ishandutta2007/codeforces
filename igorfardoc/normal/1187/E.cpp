#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
ll ans = 0;
vvi g;
int n;
vector<ll> d;
vector<int> sz;

void dfs1(int v, int p) {
	ll d1 = 0;
	int sz1 = 1;
	for(int u : g[v]) {
		if(u == p) continue;
		dfs1(u, v);
		d1 += d[u];
		sz1 += sz[u];
	}
	d1 += sz1;
	d[v] = d1;
	sz[v] = sz1;
}

void dfs(int v, int p, ll up) {
	ll sum1 = 0;
	for(int u : g[v]) {
		if(u == p) continue;
		sum1 += d[u];
	}
	ans = max(ans, sum1 + up + n);
	for(int u : g[v]) {
		if(u == p) continue;
		dfs(u, v, up + (n - sz[u]) + (sum1 - d[u]));
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n - 1; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    d.resize(n);
    sz.resize(n);
    dfs1(0, -1);
    dfs(0, -1, 0);
    cout << ans;
}