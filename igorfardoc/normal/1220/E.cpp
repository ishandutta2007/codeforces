#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m, s;
vvi g, g1;
vi w;
set<pair<int, int>> br;
vi tin, fup;
int timer = 0;
vector<bool> used;
vector<ll> compsz;
vvi comp;
vi cmp;
vector<bool> there;
ll mx = 0;

void dfs(int v, int p) {
	used[v] = true;
	fup[v] = tin[v] = timer++;
	for(int u : g[v]) {
		if(u == p) continue;
		if(used[u]) {
			fup[v] = min(fup[v], tin[u]);
		} else {
			dfs(u, v);
			if(fup[u] > tin[v]) {
				br.insert({min(v, u), max(v, u)});
			}
			fup[v] = min(fup[v], fup[u]);
		}
	}
}

void dfs1(int v) {
	comp[comp.size() - 1].push_back(v);
	cmp[v] = comp.size() - 1;
	used[v] = true;
	for(int u : g[v]) {
		if(used[u] || br.find({min(v, u), max(v, u)}) != br.end()) continue;
		dfs1(u);
	}
}

void dfs2(int v, int p) {
	there[v] = false;
	if(comp[v].size() > 1) {
		there[v] = true;
	}
	for(int u : g1[v]) {
		if(u == p) continue;
		dfs2(u, v);
		if(there[u]) {
			there[v] = true;
		}
	}
}

ll dfs3(int v, int p) {
	ll ans = 0;
	for(int u : g1[v]) {
		if(u == p) continue;
		ll here = dfs3(u, v);
		ans = max(ans, here);
	}
	ans += compsz[v];
	if(!there[v]) {
		mx = max(mx, ans);
	}
	return ans;
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
    cin >> n >> m;
    g.resize(n);
    w.resize(n);
    for(int i = 0; i < n; i++) {
    	cin >> w[i];
    }
    for(int i = 0; i < m; i++) {
    	int v, u;
    	cin >> v >> u;
    	--v;
    	--u;
    	g[v].push_back(u);
    	g[u].push_back(v);
    }
    cin >> s;
    --s;
    tin.resize(n);
    fup.resize(n);
    used.assign(n, false);
    dfs(0, -1);
    used.assign(n, false);
    cmp.resize(n);
    for(int i = 0; i < n; i++) {
    	if(used[i]) continue;
    	comp.push_back({});
    	ll here = 0;
    	dfs1(i);
    	for(const auto& el : comp[comp.size() - 1]) {
    		here += w[el];
    	}
    	compsz.push_back(here);
    }
    g1.resize(comp.size());
    for(int i = 0; i < n; i++) {
    	for(int u : g[i]) {
    		if(cmp[i] != cmp[u]) {
    			g1[cmp[i]].push_back(cmp[u]);
    		}
    	}
    }
    there.resize(g1.size());
    dfs2(cmp[s], -1);
    dfs3(cmp[s], -1);
    for(int i = 0; i < g1.size(); i++) {
    	if(there[i]) {
    		mx += compsz[i];
    	}
    }
    cout << mx;
}