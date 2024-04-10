#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long INF = 1e18;

#define F first
#define S second

int n, m, u, v, c, last[MAXN];
bool visited[MAXN];
vector< pair<int, int> > g[MAXN];
vector<int> ans;
long long cost[MAXN];
priority_queue < pair< long long, int > > Cost;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	fill(cost, cost + n + 10, INF);
	for (int i = 0; i < m; i++){
		cin >> u >> v >> c;
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	cost[1] = 0;
	Cost.push({0, 1});
	while (!Cost.empty()){
		u = Cost.top().second;
		Cost.pop();
		if(visited[u]){
			continue;
		}
		visited[u] = 1;
		for(int i = 0; i < g[u].size(); i++){
			v = g[u][i].F;
			c = g[u][i].S;
			if(cost[v] > cost[u] + c){
				cost[v] = cost[u] + c;
				last[v] = u;
				Cost.push({-cost[v], v});
			}
		}
	}
	u = n;
	while(u != 0){
		ans.push_back(u);
		u = last[u];
	}
	if(ans.back() != 1){
		cout << -1;
		return 0;
	}
	for (int i = ans.size() - 1; i > -1; i--){
		cout << ans[i] << ' ';
	}
}