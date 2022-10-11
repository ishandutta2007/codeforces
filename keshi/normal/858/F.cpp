#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 100;

#define pii pair<int, int>
#define pb push_back
#define F first
#define S second

int n, m, k, p[maxn], d[maxn];

bool vis[maxn];

vector<int> g[maxn];

vector<pair<int, pii> > ans;

set<pii> s;

set<int> e[maxn];

void dfs(int v){
	int u;
	vis[v] = 1;
	d[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u]) continue;
		p[u] = v;
		dfs(u);
		d[v]++;
	}
	s.insert({d[v], v});
	return;
}

int main(){
	int v, u;
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++){
		cin >> v >> u;
		e[v].insert(u);
		g[v].pb(u);
		g[u].pb(v);
	}
	
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			dfs(i);
		}
	}
	
	while(!s.empty()){
		v = s.begin() -> S;
		if(e[v].size() % 2 && p[v]){
			if(e[v].find(p[v]) != e[v].end()){
				e[v].erase(p[v]);
				e[p[v]].insert(v);
			}
			else{
				e[v].insert(p[v]);
				e[p[v]].erase(v);
			}
		}
		d[v]--;
		s.erase(s.begin());
		if(p[v]){
			s.erase({d[p[v]], p[v]});
			d[p[v]]--;
			s.insert({d[p[v]], p[v]});
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(e[i].size() % 2) e[i].erase(e[i].begin());
		for(set<int>::iterator it = e[i].begin(); it != e[i].end(); it++){
			ans.pb({*it, {i, *(++it)}});
		}
	}
	
	cout << ans.size() << '\n';
	
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].F << " " << ans[i].S.F << " " << ans[i].S.S << '\n';
	}
	
	return 0;
}