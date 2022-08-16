#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

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
const int logN = 15;
const int N = 3005;
ll dp[3005][3005];
int depth[N];

vector<int> adj[N];
int par[logN][N];
ll sizes[N];

ll dfs(int s = 1, int p = 0){
	par[0][s] = p;
	depth[s] = depth[p] + 1;
	sizes[s] = 1;
	for(int v : adj[s]) if(v != p) sizes[s] += dfs(v, s);
	return sizes[s];
}

int n; 

ll getSize(int u, int v){
	if(u == par[0][v]) return sizes[v];
	return n - sizes[u];
}

void pre(){
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

int getKth(int x, int k){
	for(int i = 0; i< logN; i++) if(k >> i & 1) x = par[i][x];
	return x;
}
vector<pii> which[3005];
int lst[N][N];
void getNext(int u, int v){
	int l = lca(u, v);
	int d = depth[u] + depth[v] - 2 * depth[l];
	// trace(u, v, l, d);
	lst[u][v] = l != u ? par[0][u] : getKth(v, d - 1);
	lst[v][u] = l != v ? par[0][v] : getKth(u, d - 1);
	which[d].push_back({u, v});
}

vector<pii> edges;

ll getDP(int u, int v){
	if(u > v) swap(u, v);
	return dp[u][v];
}


ll ret = 1;
void calc(int u, int v, int l){
	if(u > v) swap(u, v);
	if(l == 1){
		return;
	}
	int pu = lst[u][v], pv = lst[v][u];
	int ppu = lst[pu][v], ppv = lst[pv][u];
	int szu = getSize(pu, u);
	int szv = getSize(pv, v);
	int szu2 = getSize(ppu, pu);
	int szv2 = getSize(ppv, pv);
	dp[u][v] = getDP(pu, v) + (l - 1) * szv * (szu2 - szu);
	dp[u][v] = max(dp[u][v], getDP(u, pv) + (l - 1) * szu * (szv2 - szv));
	// trace(u, v, l, dp[u][v], szu, szv, szu2, szv2);
	ret = max(ret, dp[u][v] + l);
}

int main(){
	// memset(dp, -1, sizeof dp);
	sd(n);
	
	for(int i = 1; i < n; i++){
		int u, v;
		sd(u); sd(v); if(u > v) swap(u, v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		edges.push_back({u, v});
	}

	dfs();
	pre();

	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			getNext(i, j);
	
	for(int l = 1; l <= n; l++){
		for(auto it : which[l])
			calc(it.F, it.S, l);
	}

	printf("%lld\n", ret);
}