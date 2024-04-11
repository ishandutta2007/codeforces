#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<19, mod = 1e9 + 7;
array<int, 2> tree[maxn*2];
int n, tmm = 1;
void init() {
	for(int i = 0; i < maxn*2; i++) tree[i] = {0, 0};
}
void setv(int l, int r, int _v) {
	array<int, 2> v = {tmm++, _v};
	for(l += n, r += n; l < r; l>>=1, r>>=1) {
		if(l&1) tree[l++] = v;
		if(r&1) tree[--r] = v;
	}
}
int get(int i) {
	array<int, 2> val = {0, 0};
	for(i += n; i; i>>=1) val = max(val, tree[i]);
	return val[1];
}
vector<int> g[maxn];
int tin[maxn], tout[maxn], sz[maxn], p[maxn], head[maxn], T = 0;
void dfs_sz(int v) {
	sz[v] = 1;
	for(auto &i : g[v]) {
		g[i].erase(find(all(g[i]), v));
		p[i] = v;
		dfs_sz(i);
		sz[v] += sz[i];
		if(sz[g[v][0]] < sz[i]) swap(g[v][0], i);
	}
}
void dfs(int v) {
	tin[v] = T++;
	for(auto &i : g[v]) {
		head[i] = g[v][0] == i ? head[v] : i;
		dfs(i);
	}
	tout[v] = T;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t), g[t].push_back(f);
	}
	dfs_sz(1);
	head[1] = 1;
	dfs(1);
	int t, v, q;cin >> q;
	while(q--) {cin >> t >> v;
		//cout << t << " " << v << " :\n";
		if(t == 1) {
			setv(tin[v], tout[v], 1);
		} else if(t == 2) {
			while(v) {
				//cout << tin[head[v]] << " " << tin[v] << "]\n";
				setv(tin[head[v]], tin[v]+1, 0);
				v = p[head[v]];
			}
		} else cout << get(tin[v]) << '\n';
	}
}