#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>

using namespace std;

#define sd(s) scanf("%d", &(s))
#define pb push_back 
#define ll long long
#define F first
#define S second

const int N = 1e5 + 10;

int vis[N], height[N], ecc[N], VAL[N], comp[N], dia[N], component, size[N];
vector<int> con[N], nodes[N];
vector<ll> prefnodes[N];
map<int, int> val[N];
map<int, ll> queries[N];

void dfs1(int s, int p){
	comp[s] = component;
	size[component]++;
	vis[s] = 1;
	int h = 0;
	for(int v : con[s]) if(v != p) dfs1(v, s), h = max(h, height[v] + 1);
	height[s] = h;
}

void dfs2(int s, int p){
	if(p != 0) VAL[s] = max(VAL[p] + 1, val[p][s] + 1);

	multiset<int> ms;

	for(int v : con[s]) if(v != p) ms.insert(height[v] + 1);	
	if(ms.size() > 1){
		for(int v : con[s]){
			if(v == p) continue;
			int _h = height[v] + 1;
			ms.erase(ms.find(_h));
			val[s][v] = *ms.rbegin();
			ms.insert(_h);
		}
	}	
	

	ecc[s] = max(height[s], VAL[s]);	
	nodes[component].pb(ecc[s]);
	dia[component] = max(dia[component], ecc[s]);

	for(int v : con[s]) if(v != p) dfs2(v, s);
}

void dfs(int n){
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			component++;
			dfs1(i, 0);
			dfs2(i, 0);
			sort(nodes[component].begin(), nodes[component].end());
			for(int i = 0; i < nodes[component].size(); i++){
				if(i == 0) prefnodes[component].pb(nodes[component][i]);
				else prefnodes[component].pb(prefnodes[component][i - 1] + nodes[component][i]);
			}
		}
	}
}

double process_query(int i, int j){
	int x = comp[i], y = comp[j];
	int sx = size[x], sy = size[y];
	if(sx > sy){
		swap(x, y);
		swap(sx, sy);
	}

	double total = sx * 1ll * sy;

	if(x == y) return -1;
	if(queries[x][y]) return queries[x][y] / total;
	if(queries[y][x]) return queries[y][x] / total;
	int d = max(dia[x], dia[y]);
	ll ans = 0;
	for(i = 0; i < nodes[x].size(); i++){
		int e = nodes[x][i];
		int ind = upper_bound(nodes[y].begin(), nodes[y].end(), d - e - 1) - nodes[y].begin();
		ans += d * 1ll * ind;
		ans += (e + 1) * 1ll * (nodes[y].size() - ind) + prefnodes[y].back() - (ind == 0 ? 0 : prefnodes[y][ind - 1]);
	}
	queries[x][y] = ans;
	return ans / total;
}
int main(){
	int n, m, u, v, q;
	sd(n); sd(m); sd(q);
	for(int i = 1; i <= m; i++){
		sd(u); sd(v);
		con[u].pb(v);
		con[v].pb(u);
	}
	dfs(n);
	while(q--){
		sd(u); sd(v);
		printf("%.10lf\n", process_query(u, v));
	}
}