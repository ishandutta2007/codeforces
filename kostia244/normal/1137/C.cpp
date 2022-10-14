#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
const int maxn = 5e6 + 33;
using vi = vector<int>;
int n, m, d;
vi g[maxn/50], gt[maxn];

int cn = 0, comp[maxn], u[maxn/50], a[maxn];
vi ts;
#define G gt
void topo(int v) {
	comp[v] = cn;
	for(auto &i : g[v/d]) if(comp[d*i + ((v+1)%d)]<0) topo(d*i + ((v+1)%d));
	ts.pb(v);
}
void find(int v) {
	//cout << v << " " << comp[v] << '\n';
	comp[v] = cn;
	for(auto &i : gt[v/d]) if(comp[d*i + ((d+v-1)%d)]<0) find(d*i + ((d+v-1)%d));
}
void scc() {
	memset(comp, -1, sizeof comp);
	for(int i = 0; i < d*n; i++)
		if(comp[i]<0) topo(i);
	reverse(all(ts));
	
	memset(comp, -1, sizeof comp);
	memset(u, -1, sizeof u);
	for(auto i : ts) {
		if(comp[i]>=0) continue;
		find(i);
		cn++;
	}
	for(int v = 0; v < d*n; v++) gt[v].clear();
	for(int v = 0; v < d*n; v++) {
		for(auto i : g[v/d]) {
			G[comp[v]].pb(comp[d*i + ((v+1)%d)]);
			//cout << v << " " << i << " : " << comp[v] << " " << comp[i] << '\n';
		}
	}
	for(int i = 0; i < cn; i++) {
		sort(all(G[i]));
		G[i].erase(unique(all(G[i])), G[i].end());
	}
}
int go(int v) {
	if(comp[v] >= 0) return comp[v];
	comp[v] = a[v];
	//cout << v << " " << a[v] << '\n';
	for(auto &i : G[v]) if(i != v) comp[v] = max(go(i) + a[v], comp[v]);
	return comp[v];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> d;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;--f, --t;
		g[f].pb(t);
		gt[t].pb(f);
		
	}
	
	char t;
	set<int> z;
	scc();
	for(int i = 0; i < n*d; i++) {
		if(i%d == 0) z.clear();
		cin >> t, t-='0';
		if(t) if(z.insert(comp[i]).second) a[comp[i]]++;
	}
	int rt = comp[0];
	memset(comp, -1, sizeof comp);
	cout << go(rt);
}