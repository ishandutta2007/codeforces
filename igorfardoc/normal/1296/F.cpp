#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n;
vvi g;
vvi min1;

bool dfs(int v, int p, int u, int c) {
	if(v == u) {
		return true;
	}
	for(int u1 : g[v]) {
		if(u1 == p) continue;
		if(dfs(u1, v, u, c)) {
			min1[v][u1] = max(min1[v][u1], c);
			min1[u1][v] = max(min1[u1][v], c);
			return true;
		}
	}
	return false;
}

int dfs1(int v, int p, int u) {
	if(v == u) {
		return 1000000;
	}
	for(int u1 : g[v]) {
		if(u1 == p) continue;
		int res = dfs1(u1, v, u);
		if(res != -1) {
			return min(res, min1[v][u1]);
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    cin >> n; 
   	g.resize(n);
   	min1.assign(n, vi(n, 1));
   	vector<pair<int, int>> e(n - 1);
   	for(int i = 0; i < n - 1; i++) {
   		cin >> e[i].first >> e[i].second;
   		--e[i].first;
   		--e[i].second;
   		g[e[i].first].push_back(e[i].second);
   		g[e[i].second].push_back(e[i].first);
   	}
   	int m;
   	cin >> m;
   	vector<pair<pair<int, int>, int>> z(m);
   	for(int i = 0; i < m; i++) {
   		int a, b, c;
   		cin >> a >> b >> c;
   		--a;
   		--b;
   		z[i] = {{a, b}, c};
   		dfs(a, -1, b, c);
   	}
   	bool ok = true;
   	for(auto el : z) {
   		if(dfs1(el.first.first, -1, el.first.second) != el.second) {
   			ok = false;
   			break;
   		}
   	}
   	if(!ok) {
   		cout << -1;
   		return 0;
   	}
   	for(auto el : e) {
   		cout << min1[el.first][el.second] << ' ';
   	}
}