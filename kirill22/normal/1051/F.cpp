#include <bits/stdc++.h>

using namespace std;

const int N = 300 * 1000 + 9;
const int LOGN = 19;
const int M = 21;
const long long INF64 = 1e18;

int n, m, q;
vector <pair<int, int> > g[N];
int p[LOGN][N];
int tin[N], tout[N], T;
long long h[N];
set <pair<int, int> > badEdges;
long long d[M + M][N];
bool u[N];

void dfs(int v, int pr){
	tin[v] = T++;
	p[0][v] = pr;
	u[v] = true;
	for(int i = 1; i < LOGN; ++i)
		p[i][v] = p[i - 1][ p[i - 1][v] ];
		
	for(auto e : g[v]){
		int to = e.first, len = e.second;
		if(!u[to]){
			h[to] = h[v] + len;
			dfs(to, v);
			
			if(v < to)
				badEdges.erase(make_pair(v, to));
			else
				badEdges.erase(make_pair(to, v));			
		}
	}	
		
	tout[v] = T;
}

bool isAncestor(int a, int b){
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int getLCA(int a, int b){
	if(isAncestor(a, b)) return a;
	if(isAncestor(b, a)) return b;
	
	for(int i = LOGN - 1; i >= 0; --i)
		if(!isAncestor(p[i][a], b))
			a = p[i][a];
	
	return p[0][a];
}

void dij(int st, long long d[N]){
	set<pair<long long, int> > q;
	for(int i = 0; i < n; ++i) d[i] = INF64;
	d[st] = 0;
	q.insert(make_pair(d[st], st));
	
	while(!q.empty()){
		int v = q.begin()->second;
		q.erase(q.begin());
		
		for(auto e : g[v]){
			int to = e.first, len = e.second;
			if(d[to] > d[v] + len){
				q.erase(make_pair(d[to], to));
				d[to] = d[v] + len;
				q.insert(make_pair(d[to], to));
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	
	scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
    	int u, v, w;
    	scanf("%d %d %d", &u, &v, &w);
    	--u, --v;
    	g[u].push_back(make_pair(v, w));
       	g[v].push_back(make_pair(u, w));
    }
	
    for(int v = 0; v < n; ++v)
    	for(auto e : g[v])
    		if(v < e.first)
    			badEdges.insert(make_pair(v, e.first));

    dfs(0, 0);

    int cpos = 0;
    for(auto e : badEdges)
    	dij(e.first, d[cpos++]);
    scanf("%d", &q);
    for(int tc = 0; tc < q; ++tc){
    	int u, v;
    	scanf("%d %d", &u, &v);
    	--u, --v;
    	int lca = getLCA(u, v);
    	long long ans = h[u] + h[v] - 2 * h[lca];
    	for(int i = 0; i < badEdges.size(); ++i)
    		ans = min(ans, d[i][u] + d[i][v]);
    		
    	printf("%lld\n", ans);
    }	
    return 0;
}