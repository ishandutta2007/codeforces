#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<19, mod = 1e9 + 7;
int n, m;
array<int, 2> link[maxn];
vector<int> g[maxn];
vector<pair<vector<int>, int>> V;
vector<int> rid, ans;

void add_edge(int u, int v) {
	g[u].push_back(v);
	g[v].push_back(u);
}

vector<int> sz, mc;
vector<int> comp;
bitset<maxn> used;

void dfs(int v, int p) {
	sz[v] = 1;
	mc[v] = 0;
	for(int i : g[v]) if(!used[i] && i != p) {
		dfs(i, v);
		sz[v] += sz[i];
		mc[v] = max(mc[v], sz[i]);
	}
	comp.push_back(v);
}

int find(int v) {
	comp.clear();
	dfs(v, v);
	for(auto &i : comp)
		mc[i] = max(mc[i], (int)comp.size() - sz[i]);
	for(auto &i : comp) if(2*mc[i] <= comp.size()) return i;
	cout << "failure\n";
	exit(69);
}

void decomp(int v, int dep) {
	int c = find(v);
	ans[rid[c]] = dep;
	used[c] = 1;
	for(auto &i : g[c]) if(!used[i]) decomp(i, dep+1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++)
		link[i] = {(i+1)%n, -1};
	vector<array<int, 2>> seg(m);
	for(auto &[x, y] : seg) {
		cin >> x >> y;
		if((n+y-x)%n > n/2) swap(x, y);
	}
	sort(all(seg), [&](auto a, auto b) {
		int x = a[1]-a[0], y = b[1]-b[0];
		if(x < 0) x += n;
		if(y < 0) y += n;
		return x < y;
	});
	int Sz = 0;
	for(auto i : seg) {
		int a = i[0]-1, b = i[1]-1;
		//cout << a << " " << b << endl;
		int oa = a;
		vector<int> v{-a};
		while(a != b) {
			//cout << a << ", "<<endl;
			if(link[a][1] != -1) add_edge(Sz, link[a][1]);
			assert(link[a][0] != -1);
			int t = link[a][0];
			link[a] = {-1, -1};
			a = t;
			v.push_back(-t);
		}
		//cout << endl;
		sort(all(v));
		V.push_back({v, Sz});
		link[oa] = {b, Sz++};
	}
	vector<int> v;
	for(int i = 0; i < n; i++) if(link[i][0] != -1) {
		if(link[i][1] != -1) add_edge(Sz, link[i][1]);
		v.push_back(-i);
	}
	sort(all(v));
	V.push_back({v, Sz});
	sort(all(V), greater());
	rid.resize(m+1);
	ans.resize(m+1);
	sz.resize(m+1);
	mc.resize(m+1);
	for(int i = 0; i <= m; i++) rid[V[i].second] = i;
	decomp(Sz, 1);
	for(int i = 0; i <= m; i++) cout << ans[i] << ' ';cout << '\n';
	//for(auto i : V) {
	//	for(auto j : i.first) cout << j << " "; cout << endl;
	//}
	//for(int i = 0; i <= m; i++)
	//	for(auto &j : g[i]) if(j > i) cout << i << " " << j << endl;
}