//Author: HeXun
//Date: 09-23-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 120000;
constexpr LL mod = 1000000007;
LL x[maxn], ans;
map<LL, int> mp[maxn];
vector<int> G[maxn];
void DFS(int u, int pa = 0){
	for(auto p : mp[pa]) mp[u][__gcd(x[u], p.first)] += p.second;
	mp[u][x[u]] += 1;
	for(auto p : mp[u]) ans = (ans + p.first * p.second) % mod;
	for(int v : G[u]) if(v != pa) DFS(v, u);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i += 1) cin >> x[i];
	for(int i = 1, u, v; i < n; i += 1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	DFS(1);
	cout << ans;
	return 0;
}