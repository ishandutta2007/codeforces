#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

const int N = 1000005;
const int logN = 21;
vector<pii> con[N];
int par[logN][N],depth[N];
int nxt_util[N];
int nxt[N];
bool forest_edge[N];
void dfs(int s, int d, int p){
    depth[s] = d;
    par[0][s] = p;
    for(auto v:con[s])
        if(v.F!=p){
            dfs(v.F,d+1,s);
            if(v.S){
            	forest_edge[v.F] = 1;
            } else nxt_util[v.F] = s;
        }
}

void pre(int n){
    for(int j = 1;j<logN;j++)
        for(int i = 1;i<=n;i++)
            par[j][i] = par[j-1][par[j-1][i]];
}

int lca(int a, int b){
    if(depth[a]<depth[b])
        swap(a,b);
    int l = depth[a]-depth[b];
    for(int i = 0;i<logN;i++) if(l&(1<<i)) a = par[i][a];    
    if(a==b) return a;
    assert(depth[a] == depth[b]);
    for(int i = logN-1;i>=0;i--)
        if(par[i][a]!=par[i][b])
            a = par[i][a],b = par[i][b];
    return par[0][a];
}


int root(int x){
	return x == nxt[x] ? x : (nxt[x] = root(nxt[x]));
}

int root_util(int x){
	return x == nxt_util[x] ? x : (nxt_util[x] = root_util(nxt_util[x]));
}

bool in_mst[N];
void merge(int x, int y, bool f, int ind = 0){
	int x1 = x, y1 = y;
	x = root(x); y = root(y);
	if(x == y) return;
	con[x1].push_back({y1, f});
	con[y1].push_back({x1, f});
	in_mst[ind] = 1;
	nxt[x] = y;
}

pair<int, pii> edges[N];
int wt[N];
ll ans = 0;
void go(int u, int l, int w){
	u = root_util(u);
	while(u != 1 && depth[u] > depth[l]){
		ans += w;
		nxt_util[u] = par[0][u];
		u = root_util(u);
	}
}
int main(){
	for(int i = 1; i < N; i++) nxt[i] = nxt_util[i] = i;
	int n, k, m; sd(n); sd(k); sd(m);
	for(int i = 1; i <= k; i++){
		int u, v; sd(u); sd(v);
		merge(u, v, 1);
	}
	for(int i = 1; i <= m; i++){
		sd(edges[i].S.F), sd(edges[i].S.S), sd(edges[i].F);
	}
	sort(edges + 1, edges + m + 1);

	for(int i = 1; i <= m; i++){
		merge(edges[i].S.F, edges[i].S.S, 0, i);
	}
	dfs(1, 1, -1);
	pre(n);
	for(int i = 1; i <= m; i++){
		if(!in_mst[i]){
			int u = edges[i].S.F, v = edges[i].S.S;
			int l = lca(u, v);
			go(u, l, edges[i].F);
			go(v, l, edges[i].F);
		}
	}
	for(int i = 1; i <= n; i++) if(root_util(i) != 1){
		printf("-1\n");
		return 0;
	}
	printf("%lld\n", ans);
}