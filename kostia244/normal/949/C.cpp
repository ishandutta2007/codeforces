#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int maxn = 2e5 + 33;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
struct dsu {
	vi r, p;
	void init(int n) {
		r.resize(n, 1);
		p.resize(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
	}
	int par(int i) {
		if (i == p[i])
			return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if (i == j)
			return;
		if (r[i] < r[j])
			swap(i, j);
		r[i] += r[j];
		p[j] = i;
	}
};
vector<vi> g, gt, tr;
dsu d;
vi topo;
bitset<maxn> vis;
void ord(int v) {
	vis[v] = 1;
	for (auto i : gt[v]) {
		if(!vis[i]){
			ord(i);}
	}
	topo.pb(v);
}
void paint(int v) {
	vis[v] = 1;
	for(auto i : g[v])
		if(!vis[i]) {
			d.unite(v, i);
			paint(i);
		}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, h;
	vi a;
	cin >> n >> m >> h;
	g.resize(n);
	gt.resize(n);
	tr.resize(n);
	a.resize(n);
	d.init(n);
	for (auto &i : a)
		cin >> i;
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t, f--, t--;
		int d = (h + a[f] - a[t]) % h;
//		cout << f << " " << t << d << "\n";
		if (d == h-1){
//			cout << t << " " << f << "\n";
			g[f].pb(t);
			gt[t].pb(f);
		}
		if (d == 1){
//			cout << f << " " << t << "\n";
			g[t].pb(f);
			gt[f].pb(t);
		}
	}
	for(int i = 0; i <n; i++)
		if(!vis[i]) {
			ord(i);
		}
	reverse(all(topo));
	vis = 0;

	for(int i = 0; i <n; i++)
		if(!vis[topo[i]]) {
//			cout << topo[i] << "root\n";
			paint(topo[i]);
		}
	vi out(n);
	for(int i = 0; i < n; i++)
		for(auto j : g[i]) {
			if(d.par(i)!=d.par(j)) {
//				cout << i << " " << j << "\n";
				out[d.par(i)]++;
			}
		}
	int ans = 1e8, t = -1;
	for(int i = 0; i < n; i++)
		if(d.par(i)==i&&!out[i]&&ans>d.r[i]) ans = d.r[i], t = i;
	vi rr;
	for(int i = 0; i < n; i++) if(d.par(i)==t) rr.pb(i);
	cout << ans << "\n";
	for(auto i : rr) cout << i+1 << " ";

}