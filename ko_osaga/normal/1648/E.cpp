#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;
const int mod = 998244353;
const int MAXN = 400005;

struct edg{
	int s, e, x, idx;
	bool operator<(const edg &e)const{
		return x < e.x;
	}
};

struct nodes{
	vector<int> nodes;
	set<int> adj;
	int sizes;
};

vector<vector<int>> gph;

struct disj2{
	int pa[MAXN];
	void init(int n){
		iota(pa, pa + n, 0);
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		pa[q] = p; return 1;
	}
}disj2;

struct solver{
	int par[18][MAXN], pae[18][MAXN], dep[MAXN];
	vector<pi> gph[MAXN];

	void init(int n){
		for(int i = 0; i < n; i++){
			gph[i].clear();
		}
	}
	void add_edge(int s, int e, int x){
		gph[s].emplace_back(x, e);
		gph[e].emplace_back(x, s);
	}

	void dfs(int x, int p){
		for(auto &y : gph[x]){
			if(y.second != p){
				par[0][y.second] = x;
				pae[0][y.second] = y.first;
				dep[y.second] = dep[x] + 1;
				dfs(y.second, x);
			}
		}
	}
	void prec(int n){
		dfs(0, -1);
		for(int i = 1; i < 18; i++){
			for(int j = 0; j < n; j++){
				par[i][j] = par[i-1][par[i-1][j]];
				pae[i][j] = max(pae[i-1][j], pae[i-1][par[i-1][j]]);
			}
		}
	}

	int query(int s, int e){
		if(dep[s] > dep[e]) swap(s, e);
		int ret = -1e9;
		int dx = dep[e] - dep[s];
		for(int i = 0; dx; i++){
			if(dx & 1){
				ret = max(ret, pae[i][e]);
				e = par[i][e];
			}
			dx >>= 1;
		}
		for(int i = 17; i >= 0; i--){
			if(par[i][s] != par[i][e]){
				ret = max({ret, pae[i][s], pae[i][e]});
				s = par[i][s];
				e = par[i][e];
			}
		}
		if(s != e) ret = max({ret, pae[0][s], pae[0][e]});
		return ret;
	}
}solver;

void addEdge(int s, int e, int x){
	if(disj2.uni(s, e)){
		solver.add_edge(s, e, x);
	}
}

struct disj{
	int pa[MAXN];
	nodes nd[MAXN];
	int revCompIdx[MAXN];
	void init(int n){
		iota(pa, pa + n, 0);
		for(int i = 0; i < n; i++){
			nd[i].sizes = sz(gph[i]) + 1;
			nd[i].nodes.clear();
			nd[i].adj.clear();
			nd[i].nodes.push_back(i);
			revCompIdx[i] = 0;
		}
	}
	int find(int x){
		return pa[x] = (pa[x] == x ? x : find(pa[x]));
	}
	void uni(int p, int q, int w){
		p = find(p);
		q = find(q);
		if(nd[p].sizes < nd[q].sizes) swap(p, q);
		
		// make edges
		for(auto &v : nd[q].nodes){
			vector<int> ridx;
			for(auto &j : gph[v]){
				if(find(j) != p) continue;
				ridx.push_back(revCompIdx[j]);
			}
			ridx.push_back(-1);
			ridx.push_back(sz(nd[p].nodes));
			sort(all(ridx));
			for(int i = 1; i < sz(ridx); i++){
				if(ridx[i - 1] + 1 < ridx[i]){
					int s = ridx[i - 1] + 1;
					int e = ridx[i] - 1;
					addEdge(nd[p].nodes[s], v, w);
					auto it = nd[p].adj.lower_bound(s);
					while(it != nd[p].adj.end() && *it < e){
						addEdge(nd[p].nodes[*it], nd[p].nodes[*it + 1], w);
						it = nd[p].adj.erase(it);
					}
				}
			}
		}

		// merge
		pa[q] = p;
		nd[p].sizes += nd[q].sizes;
		for(auto &x : nd[q].nodes){
			revCompIdx[x] = sz(nd[p].nodes);
			nd[p].nodes.push_back(x);
			nd[p].adj.insert(revCompIdx[x] - 1);
		}
	}
}disj;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc; cin >> tc;
	while(tc--){
		int n, m; cin >> n >> m;
		gph.clear();
		gph.resize(n);
		vector<edg> v;
		for(int i = 0; i < m; i++){
			int s, e, x; cin >> s >> e >> x;
			s--; e--;
			v.push_back({s, e, x, i});
			gph[s].push_back(e);
			gph[e].push_back(s);
		}
		sort(all(v));
		disj.init(n);
		disj2.init(n);
		solver.init(n);
		for(auto &e : v){
			if(disj.find(e.s) == disj.find(e.e)) continue;
			disj.uni(e.s, e.e, e.x);
		}
		sort(all(v), [&](const edg &a, const edg &b){
			return a.idx < b.idx;
		});
		solver.prec(n);
		for(auto &e : v){
			cout << solver.query(e.s, e.e) << " ";
		}
		cout << "\n";
	}
}