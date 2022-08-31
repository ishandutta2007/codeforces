#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, int>;
const int MAXN = 500005;

int n, m, k;
struct disj{
	int pa[MAXN];
	void init(int n){
		iota(pa, pa + n + 1, 0);
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
}disj;

struct edg{
	int s, e, x;
	bool operator<(const edg &e)const{
		return x < e.x;
	}
};

vector<edg> mst, repl;
vector<pi> gph[MAXN];

int dep[MAXN];
int par[19][MAXN], isquery[MAXN];

void dfs(int x, int p){
	for(auto &i : gph[x]){
		if(i.second == p) continue;
		if(i.first == 0) isquery[i.second] = 1;
		dep[i.second] = dep[x] + 1;
		par[0][i.second] = x;
		dfs(i.second, x);
	}
}

int lca(int s, int e){
	if(dep[s] > dep[e]) swap(s, e);
	int dx = dep[e] - dep[s];
	for(int i=0; i<19; i++){
		if((dx >> i) & 1) e = par[i][e];
	}
	for(int i=18; i>=0; i--){
		if(par[i][s] != par[i][e]){
			s = par[i][s];
			e = par[i][e];
		}
	}
	if(s != e) return par[0][s];
	return s;
}


int pa[MAXN], ans[MAXN];

int paint(int s, int l, int v, int *ans){
	if(s != pa[s]) return pa[s] = paint(pa[s], l, v, ans);
	if(dep[s] <= dep[l]) return s;
	else{
		ans[s] = v;
		return pa[s] = paint(par[0][s], l, v, ans);
	}
}

int main(){
	scanf("%d %d %d",&n,&k,&m);
	for(int i=0; i<k; i++){
		int s, e; scanf("%d %d",&s,&e);
		mst.push_back({s, e, 0});
	}
	for(int i=0; i<m;i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		mst.push_back({s, e, x});
	}
	disj.init(n);
	sort(mst.begin(), mst.end());
	for(auto &i : mst){
		if(disj.uni(i.s, i.e)){
			gph[i.s].push_back(pi(i.x, i.e));
			gph[i.e].push_back(pi(i.x, i.s));
		}
		else{
			repl.push_back(i);
		}
	}
	dfs(1, 0);
	for(int i=1; i<19; i++){
		for(int j=1; j<=n; j++){
			par[i][j] = par[i-1][par[i-1][j]];
			pa[j] = j;
		}
	}
	for(auto &i : repl){
		int l = lca(i.s, i.e);
		paint(i.s, l, i.x, ans);
		paint(i.e, l, i.x, ans);
	}
	lint dap = 0;
	for(int i=2; i<=n; i++){
		if(isquery[i]){
			if(ans[i] == 0){
				puts("-1");
				return 0;
			}
			dap += ans[i];
		}
	}
	cout <<dap << endl;
}