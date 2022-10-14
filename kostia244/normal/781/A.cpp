#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<19;
int n, col[maxn];
vector<int> g[maxn];
void dfs(int v, int p = 0) {
	int c = 1;
	for(int i : g[v]) if(i != p) {
		while(c == col[v] || c == col[p]) c++;
		col[i] = c;
		dfs(i, v);
		c++;
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans = max(ans, (int)g[i].size()+1);
	cout << ans << '\n';
	col[1] = 1;
	dfs(1);
	for(int i = 1; i <= n; i++) cout << col[i] << " "; cout << endl;
}