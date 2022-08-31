#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using llf = long double;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 2100005;

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

int n, m;
vector<int> gph[MAXN];
int dep[MAXN], par[MAXN];

void dfs(int x, int p){
	for(auto &y : gph[x]){
		if(y != p){
			dep[y] = dep[x] + 1;
			par[y] = x;
			dfs(y, x);
		}
	}
}

int fuck;
bool vis[MAXN];

int dfs2(int x, int p){
	vis[x] = 1;
	vector<int> v;
	for(auto &y : gph[x]){
		if(y != p){
			v.push_back(dfs2(y, x));
		}
	}
	fuck += sz(v) / 2;
	if(sz(v) % 2 == 0) return x;
	else return v.back();
}


int lca(int x, int y){
	if(x == y) return x;
	if(dep[x] < dep[y]) return lca(x, par[y]);
	if(dep[x] > dep[y]) return lca(par[x], y);
	return lca(par[x], par[y]);
}

int cnt[MAXN];

void addPath(int a, int b){
	int l = lca(a, b);
	for(int i = a; i != l; i = par[i]) cnt[i] ^= 1;
	for(int i = b; i != l; i = par[i]) cnt[i] ^= 1;
}

int main(){
	scanf("%d %d",&n,&m);
	disj.init(n);
	for(int i = 1; i <= m; i++){
		int s, e; scanf("%d %d",&s,&e);
		if(disj.uni(s, e)){
			gph[s].push_back(e);
			gph[e].push_back(s);
		}
	}
	dfs(1, 0);
	int q; scanf("%d",&q);
	vector<pi> query(q);
	for(auto &[a, b] : query){
		scanf("%d %d",&a,&b);
		addPath(a, b);
	}
	if(count(cnt, cnt + MAXN, 1)){
		puts("NO");
		for(int i = 0; i <= n; i++) gph[i].clear();
		for(int i = 1; i <= n; i++){
			if(cnt[i]){
				gph[par[i]].push_back(i);
				gph[i].push_back(par[i]);
			}
		}
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				if(dfs2(i, -1) != i) fuck++;
			}
		}
		cout << fuck << endl;
	}
	else{
		puts("YES");
		for(auto &[a, b] : query){
			int l = lca(a, b);
			vector<int> v1, v2;
			for(int i = a; i != l; i = par[i]) v1.push_back(i);
			for(int i = b; i != l; i = par[i]) v2.push_back(i);
			reverse(all(v2));
			v1.push_back(l);
			for(auto &i : v2) v1.push_back(i);
			printf("%d\n", sz(v1));
			for(auto &i : v1) printf("%d ", i);
			puts("");
		}
	}
}