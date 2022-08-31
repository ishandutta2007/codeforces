#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 200005;

struct edg{
	int s, e, x;
	bool operator<(const edg &e)const{
		return x > e.x;
	}
};

struct qry{
	int lim, vtx, idx;
	bool operator<(const qry &q)const{
		return lim > q.lim;
	}
};

#define data fuck
#define uni sex

struct node{
	int maxE, maxT;
	set<int> cands;
}data[MAXN];

int pa[MAXN];

int find(int x){
	return pa[x] = (pa[x] == x ? x : find(pa[x]));
}

int n, q, a[MAXN];
int par[18][MAXN], pae[18][MAXN], din[MAXN], dep[MAXN], rev[MAXN], piv;
vector<pi> gph[MAXN];

// (lca, max enjoy)
pi lca(int x, int y){
	if(dep[x] > dep[y]) swap(x, y);
	int dx = dep[y] - dep[x];
	int ret = 0;
	for(int i = 0; dx; i++){
		if(dx & 1){
			ret = max(ret, pae[i][y]);
			y = par[i][y];
		}
		dx >>= 1;
	}
	for(int i = 17; i >= 0; i--){
		if(par[i][y] != par[i][x]){
			ret = max({ret, pae[i][x], pae[i][y]});
			x = par[i][x];
			y = par[i][y];
		}
	}
	if(x != y) ret = max({ret, pae[0][x], pae[0][y]}), x = par[0][x];
	return pi(x, ret);
}

void dfs(int x, int p){
	din[x] = ++piv;
	rev[din[x]] = x;
	for(auto &[w, y] : gph[x]){
		if(y == p) continue;
		par[0][y] = x;
		pae[0][y] = w;
		dep[y] = dep[x] + 1;
		dfs(y, x);
	}
}

void uni(int p, int q){
	p = find(p);
	q = find(q);
	if(sz(data[p].cands) > sz(data[q].cands)) swap(p, q);
	pa[p] = q;
	if(data[q].maxE > data[p].maxE){
		return;
	}
	if(data[q].maxE < data[p].maxE){
		data[q].maxE = data[p].maxE;
		data[q].maxT = data[p].maxT;
		data[q].cands = data[p].cands;
		return;
	}
	data[q].maxT = max(data[q].maxT, data[p].maxT);
	for(auto &z : data[p].cands){
		auto l = data[q].cands.lower_bound(z);
		if(l != data[q].cands.end()){
			data[q].maxT = max(data[q].maxT, lca(rev[*l], rev[z]).second);
		}
		if(l != data[q].cands.begin()){
			l--;
			data[q].maxT = max(data[q].maxT, lca(rev[*l], rev[z]).second);
		}
		data[q].cands.insert(z);
	}
}

pi QQuery(int z){
	int q = find(z);
	z = din[z];
	int ret = data[q].maxT;
	auto l = data[q].cands.lower_bound(z);
	if(l != data[q].cands.end()){
		ret = max(ret, lca(rev[*l], rev[z]).second);
	}
	if(l != data[q].cands.begin()){
		l--;
		ret = max(ret, lca(rev[*l], rev[z]).second);
	}
	return pi(data[q].maxE, ret);
}

int main(){
	scanf("%d %d",&n,&q);
	for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
	vector<edg> merge_ord;
	vector<qry> query;
	for(int i = 0; i < n - 1; i++){
		int s, e, x, y;
		scanf("%d %d %d %d",&s,&e,&x,&y);
		gph[s].emplace_back(y, e);
		gph[e].emplace_back(y, s);
		merge_ord.push_back({s, e, x});
	}
	sort(all(merge_ord));
	for(int i = 0; i < q; i++){
		int v, x;;
		scanf("%d %d",&v,&x);
		query.push_back({v, x, i});
	}
	sort(all(query));
	{
		// dfs preprocessing
		dfs(1, 0);
		for(int i = 1; i < 18; i++){
			for(int j = 1; j <= n; j++){
				par[i][j] = par[i-1][par[i-1][j]];
				pae[i][j] = max(pae[i-1][j], pae[i-1][par[i-1][j]]);
			}
		}
		for(int i = 1; i <= n; i++){
			data[i].maxE = a[i];
			data[i].cands.insert(din[i]);
			pa[i] = i;
		}
	}
	int j = 0;
	vector<pi> dap(q);
	for(auto &i : query){
		while(j < sz(merge_ord) && i.lim <= merge_ord[j].x){
			uni(merge_ord[j].s, merge_ord[j].e);
			j++;
		}
		dap[i.idx] = QQuery(i.vtx);
	}
	for(auto &[x, y] : dap) printf("%d %d\n", x, y);
}