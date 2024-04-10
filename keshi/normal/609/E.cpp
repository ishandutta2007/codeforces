#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
const int MAXM = 2e5 + 100;
const int INF = 1e9;

#define ll int
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, level, dsu[MAXN], Size[MAXN], parent[MAXN][18], mtp[MAXN][18], depth[MAXN], cost[MAXM];
long long sum;
bool visited[MAXN], used[MAXM];
vector< pll > g[MAXN], es, e;

void initialize(){
    for(int i = 1; i <= n; i++){
    	dsu[i] = i;
    	Size[i] = 1;
	}
}

int root(int i){
	if (dsu[i] == i){
		return dsu[i];
	}
	dsu[i] = root(dsu[i]);
	return dsu[i];
}

bool find(int i, int j){
	if (root(i) == root(j)){
		return 1;
	}
	return 0;
}

void Union(int i, int j){
	if (find(i, j)){
		return;
	}
    int root_i = root(i);
    int root_j = root(j);
    if(Size[root_i] < Size[root_j]){
		dsu[root_i] = dsu[root_j];
		Size[root_j] += Size[root_i];
	}
	else{
		dsu[root_j] = dsu[root_i];
		Size[root_i] += Size[root_j];
	}
}

void dfs(int v){
	visited[v] = 1;
	int u, c;
	for(int i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		c = g[v][i].S;
		if(!visited[u]){
			depth[u] = depth[v] + 1;
			parent[u][0] = v;
			mtp[u][0] = c;
			dfs(u);
		}
	}
}

int LCA(int v, int u){
	int ans = -1;
	if(depth[v] < depth[u]){
		swap(v, u);
	}
	int d = depth[v] - depth[u];
	for(int i = 0; i < level; i++){
		if((d >> i) & 1){
			ans = max(ans, mtp[v][i]);
			v = parent[v][i];
		}
	}
	for (int i = level - 1 ; i > -1; i--){
        if (parent[u][i] != parent[v][i]){
        	ans = max(ans, mtp[u][i]);
        	ans = max(ans, mtp[v][i]);
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    //cout << u << " " << v << endl;
    if(u != v && parent[u][0] != -1){
    	ans = max(ans, mtp[u][0]);
    	ans = max(ans, mtp[v][0]);
	}
    return ans;
}

int main(){
	ll u, v, c;
	fast_io;
	cin >> n >> m;
	level = ceil(log2(n));
	initialize();
	for (ll i = 0; i < m; i++){
		cin >> u >> v >> c;
		e.pb({u, v});
		es.pb({c, i});
		cost[i] = c;
	}
	sort(es.begin(), es.end());
	for(int i = 0; i < m; i++){
		u = e[es[i].S].F;
		v = e[es[i].S].S;
		c = es[i].F;
		if(!find(u, v)){
			Union(u, v);
			//cout << " # " << u << "_" << v << " " << c << endl;;
			g[u].pb({v, c});
			g[v].pb({u, c});
			used[es[i].S] = 1;
			sum += c;
		}
	}
	for (int i = 0; i < level; i++){
        for (int node = 1; node <= n; node++){
            parent[node][i] = -1;
            mtp[node][i] = INF;
        }
    }
	dfs(1);
	for (int i = 1; i < level; i++){
        for (int node = 1; node <= n; node++){
            if (parent[node][i - 1] != -1){
            	parent[node][i] = parent[parent[node][i - 1]][i - 1];
            	mtp[node][i] = max(mtp[node][i - 1], mtp[parent[node][i - 1]][i - 1]);
			}
        } 
    } 
	for(ll i = 0; i < m; i++){
		if(used[i]){
			cout << sum << endl;
		}
		else{
			cout << sum + cost[i] - LCA(e[i].F, e[i].S) << endl;
		}
	}
	return 0;
}