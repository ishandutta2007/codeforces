#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vector<int> g[maxn];
int h[maxn];
void dfs(int v, int x = 0) {
	h[x]++;
	for(auto i : g[v]) dfs(i, x+1);
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int f, t, i = 2; i <= n; i++) {
		cin >> t;
		g[t].push_back(i);
	}
	dfs(1);
	int ans = 0;
	for(int i = 0; i <= n; i++) ans += h[i]&1;
	cout << ans << endl;
}