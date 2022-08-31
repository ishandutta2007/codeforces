#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int mod = 1e9 + 7;
const int MAXN = 200005;

struct disj{
	int par[200005];
	void init(int n){
		iota(par, par + n + 1, 0);
	}
	int find(int x){
		return par[x] = (par[x] == x ? x : find(par[x]));
	}
	bool uni(int p, int q){
		p = find(p);
		q = find(q);
		if(p == q) return 0;
		par[q] = p; return 1;
	}
}disj;

struct pi{
	int first, second, idx;
};

struct edg{
	int s, e, x, idx;
	bool operator<(const edg &e)const{
		return x < e.x;
	}
}e[MAXN];

int n, m;
int ret[MAXN], idx[MAXN];
int par[18][MAXN], mxv[18][MAXN], dep[MAXN];
vector<pi> gph[MAXN];

void dfs(int x, int p){
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		dep[i.second] = dep[x] + 1;
		idx[i.second] = i.idx;
		par[0][i.second] = x;
		mxv[0][i.second] = i.first;
		dfs(i.second, x);
	}
}

int lca(int s, int e){
	if(dep[s] > dep[e]) swap(s, e);
	int dx = dep[e] - dep[s];
	for(int i=0; i<18; i++){
		if((dx >> i) & 1) e = par[i][e];
	}
	for(int i=17; i>=0; i--){
		if(par[i][s] != par[i][e]){
			s = par[i][s];
			e = par[i][e];
		}
	}
	if(s != e) s = par[0][s];
	return s;
}

int query(int s, int e){
	int l = lca(s, e);
	int ans = 0;
	for(int i=17; i>=0; i--){
		if(dep[s] - (1<<i) >= dep[l]){
			ans = max(ans, mxv[i][s]);
			s = par[i][s];
		}
		if(dep[e] - (1<<i) >= dep[l]){
			ans = max(ans, mxv[i][e]);
			e = par[i][e];
		}
	}
	return ans;
}

int gap[MAXN];

int comp(int s, int e, int x){
	if(dep[s] <= dep[e]) return e;
	ret[idx[s]] = min(ret[idx[s]], x);
	return gap[s] = comp(gap[par[0][s]], e, x);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		scanf("%d %d %d",&e[i].s,&e[i].e,&e[i].x);
		e[i].idx = i;
	}
	sort(e, e+m);
	disj.init(n);
	iota(gap, gap + n + 1, 0);
	vector<edg> rem;
	for(int i=0; i<m; i++){
		if(disj.uni(e[i].s, e[i].e)){
			gph[e[i].s].push_back({e[i].x, e[i].e, e[i].idx});
			gph[e[i].e].push_back({e[i].x, e[i].s, e[i].idx});
		}
		else{
			rem.push_back(e[i]);
		}
	}
	dfs(1, 0);
	for(int i=1; i<18; i++){
		for(int j=1; j<=n; j++){
			par[i][j] = par[i-1][par[i-1][j]];
			mxv[i][j] = max(mxv[i-1][j], mxv[i-1][par[i-1][j]]);
		}
	}
	memset(ret, 0x3f, sizeof(ret));
	for(auto &i : rem){
		ret[i.idx] = query(i.s, i.e) - 1;
		int l = lca(i.s, i.e);
		comp(i.s, l, i.x - 1);
		comp(i.e, l, i.x - 1);
	}
	for(int i=0; i<m; i++){
		if(ret[i] > 1e9 + 100) ret[i] = -1;
		printf("%d ", ret[i]);
	}
}