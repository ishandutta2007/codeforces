#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
const int N = 3e5 + 10;
vector<pair<int, int> > edges;
vi con[N];
int d[N], p[N], cnt = 0, vis[N];
map<pair<int, int>, int> ind;
void dfs1(int s){
	vis[s] = 1;
	for(int v : con[s]){
		if(!vis[v]){
			dfs1(v);
			if(p[v] == 1){
				edges.push_back({s, v});
				p[s]  ^= 1;
			}
		}
	}
}
int P[N];
void dfs2(int s){
	random_shuffle(con[s].begin(), con[s].end());
	vis[s] = 1;
	for(int v : con[s]){
		if(!vis[v]){
			dfs2(v);
			if(P[v] == 1) edges.pb({s, v}), P[s] ^= 1;
		}
	}
}
int main(){
	srand(time(NULL));
	int n, m, u, v; sd(n); sd(m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &d[i]);
		if(d[i] == -1) cnt++;
	}
	for(int i = 1; i <= m; i++){
		sd(u); sd(v);
		con[u].pb(v); con[v].pb(u);
		ind[{u, v}] = i;
		ind[{v, u}] = i;
	}
	for(int i = 1; i <= n; i++){
		p[i] = (d[i] == -1) ? 0 : d[i];
	}
	if(cnt){
		for(int i = 1; i <= n; i++){
			if(d[i] == -1){
				dfs1(i);
				printf("%d\n", edges.size());
				for(auto it : edges) printf("%d\n", ind[it]);
				return 0;
			}
		}
	}
	// return 0;
	while(clock() < CLOCKS_PER_SEC){
		memset(vis, 0, sizeof vis);
		memcpy(P, p, sizeof P);
		edges.clear();
		dfs2(1);
		if(!P[1]){
			printf("%d\n", edges.size());
			for(auto it : edges) printf("%d\n", ind[it]);
			return 0;
		}
	}
	cout << -1;
}