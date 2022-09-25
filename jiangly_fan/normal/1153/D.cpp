#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 360000;
int f[maxn], s[maxn], r[maxn], t[maxn];
vector<int> G[maxn];
void DFS(int u){
	if(G[u].size() and t[u] == 1) r[u] = 1e9;
	if(G[u].size() and t[u] == 0) r[u] = 0;
	if(G[u].empty()) s[u] = r[u] = 1;
	for(int v : G[u]){
		DFS(v);
		s[u] += s[v];
		if(t[u] == 1) r[u] = min(r[u], s[v] - r[v]);
		if(t[u] == 0) r[u] += r[v] - 1;
	}
	if(G[u].size() and t[u] == 1) r[u] = s[u] - r[u];
	if(G[u].size() and t[u] == 0) r[u] += 1;
}
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> t[i];
	for(int i = 2; i <= n; i += 1){
		cin >> f[i];
		G[f[i]].push_back(i);
	}
	DFS(1);
	cout << r[1];
}