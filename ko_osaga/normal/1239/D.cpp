#include<bits/stdc++.h>
#define sz(v) ((int)(v).size())
using namespace std;
using lint = long long;
using pi = pair<int, int>;


const int MAXN = 1000050;
struct strongly_connected{
	vector<int> gph[MAXN];
	vector<int> rev[MAXN];
	vector<int> dfn;
	vector<int> comp, vis;
	int piv;

	void clear(int n){
		comp.resize(n+5);
		vis.resize(n+5);
		for(int i=0; i<n+5; i++){
			gph[i].clear();
			rev[i].clear();
		}
	}

	void add_edge(int s, int e){
		gph[s].push_back(e);
		rev[e].push_back(s);
	}

	void dfs(int x){
		vis[x] = 1;
		for(auto &i : gph[x]){
			if(!vis[i]) dfs(i);
		}
		dfn.push_back(x);
	}

	void rdfs(int x, int p){
		comp[x] = p;
		for(auto &i : rev[x]){
			if(!comp[i]) rdfs(i, p);
		}
	}

	void get_scc(int n){
		dfn.clear();
		fill(comp.begin(), comp.end(), 0);
		fill(vis.begin(), vis.end(), 0);
		piv = 0;
		for(int i=0; i<n; i++){
			if(!vis[i]) dfs(i);
		}
		reverse(dfn.begin(), dfn.end());
		for(auto &i : dfn){
			if(!comp[i]) rdfs(i, ++piv);
		}
	}
}scc;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n, m; scanf("%d %d",&n,&m);
		scc.clear(n);
		for(int i=0; i<m; i++){
			int s, e; scanf("%d %d",&s,&e);
			if(s != e) scc.add_edge(s - 1, e - 1);
		}
		scc.get_scc(n);
		if(scc.piv == 1) puts("No");
		else{
			vector<int> l, r;
			for(int i=0; i<n; i++){
				if(scc.comp[i] == scc.piv) l.push_back(i);
				else r.push_back(i);
			}
			puts("Yes");
			printf("%d %d\n", sz(l), sz(r));
			for(auto &i : l) printf("%d ", i + 1);
			puts("");
			for(auto &i : r) printf("%d ", i + 1);
			puts("");
		}
	}
}