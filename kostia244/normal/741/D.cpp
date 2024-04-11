#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using ll = long long;
using namespace std;
const int maxn = 1<<19;
int n;
vector<int> g[maxn];
int h[maxn], sz[maxn], col[maxn], ans[maxn];
void pre(int v) {
	sz[v] = 1;
	for(auto &i : g[v]) {
		h[i] = h[v] + 1;
		pre(i);
		sz[v] += sz[i];
		if(sz[i] > sz[g[v][0]]) swap(g[v][0], i);
	}
}
int cnt[1<<22], *res = 0;
template<int rem = 7>
void update(int v, int C) {
	//cout << v << " " << col[v] << " | "<< (*res) << " :\n";
	if(rem != 2) {
	(*res) = max((*res), cnt[col[v]] + h[v] - C);
	//cout << (*res) << "H\n";
	for(int i = 0; i < 22; i++) {
		(*res) = max((*res), cnt[col[v]^(1<<i)] + h[v] - C);
	}
	}
	if(rem)
	cnt[col[v]] = max(cnt[col[v]], h[v]);
	//cout << (*res) << endl;
}
template<int rem>
void add(int v, int C = 0) {
	//if(rem) cout << "Cleaning " << v << endl;
	//else cout << "Adding " << v << endl;
	if(rem == 1) cnt[col[v]] = -(1<<20);
	else update<rem>(v, C);
	for(auto &i : g[v]) add<rem>(i, C);
}
void dfs(int v, int clr = 0) {
	//cout << "We are in " << v << " ( " << clr << " )\n";
	for(auto &i : g[v])
		if(i != g[v][0])
			dfs(i, 1), ans[v] = max(ans[v], ans[i]);
	for(auto &i : g[v]) {
		if(i == g[v][0]) {
			dfs(i, 0);
			ans[v] = max(ans[v], ans[i]);
			res = &ans[v];
			update(v, 2*h[v]);
		} else {
			add<0>(i, 2*h[v]);
			add<2>(i, 2*h[v]);
		}
	}
	if(g[v].empty()) {
		res = &ans[v];
		update(v, 2*h[v]);
	}
	if(clr) add<1>(v);
}

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int p;
	char c;
	for(int i = 2; i <= n; i++) {
		cin >> p >> c;
		col[i] = col[p] ^ (1<<(c-'a'));
		g[p].push_back(i);
	}
	memset(cnt, -0x3f, sizeof cnt);
	pre(1);
	dfs(1);
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
}
//?VK
//??V
//K?