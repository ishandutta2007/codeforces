#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = (1e9 + 7);
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
int n, m;
vvi g, gt;
vi topo, vis, comp;

void dfst(int v) {
	vis[v] = 1;
	for (auto i : g[v])
		if (!vis[i])
			dfst(i);
	topo.pb(v);
}
void dfsc(int v, int c) {
	comp[v] = c;
	for(auto i : gt[v])
		if(!comp[i])
			dfsc(i, c);
}
pair<vi, vi> can(int v) {
	vi a[2];
	queue<int> q;
	q.push(v);
	vis.assign(n+1, 0);
	a[0].pb(v);
	vis[v] = 1;
//	cout << v << ":\n";
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(auto i : g[u]) {
			if(vis[i]) continue;
			q.push(i);
//			cout << u << " -> " << v << "\n";
			a[0].pb(i);
			vis[i] = 1;
		}
	}
	sort(all(a[0]));
	int j = 0;
	for(int i = 1; i <= n; i++){
		if(j>=a[0].size()||a[0][j]!=i)
			a[1].pb(i);
		else if(j<a[0].size()&&i>=a[0][j])
			j++;
	}
//	cout << ";\n";
	return {a[0], a[1]};
}
void solve() {
	cin >> n >> m;
	g.assign(n + 1, { });
	gt.assign(n + 1, { });
	vis.assign(n + 1, 0);
	comp.assign(n + 1, 0);
	topo.clear();
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		gt[t].pb(f);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfst(i);
	int c = 0;
	vi roots;
	reverse(all(topo));
	for (int i = 0; i < n; i++) {
		if (!comp[topo[i]])
			dfsc(topo[i], ++c), roots.pb(topo[i]);
	}
	if(c==1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	pair<vi, vi> x = can(roots[0]);
	if(x.first.empty()||x.second.empty()) {
		x = can(roots[1]);
	}
	cout << x.first.size() << " " << x.second.size() << "\n";
	for(auto i : x.first) cout << i<< " ";cout << "\n";
	for(auto i : x.second) cout << i<< " ";cout << "\n";
//	cout << "===\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
}