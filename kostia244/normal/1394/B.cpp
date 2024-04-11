#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;//2*5*7*9 3*4*6*8
const int maxn = 1<<20, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
#define prev perv
int n, m, k;
vector<array<int, 2>> g[maxn];
vector<int> can[maxn];
int comb[110][110], ans = 0;
int prev[13];
void dfs(int i) {
	if(i > k) {
		++ans;
		return;
	}
	for(int d = 0; d < i; d++) {
		int f = 0;
		prev[i] = i*9 + d;
		for(int j = 1; j <= i; j++) f |= comb[prev[j]][i*9 + d];
		if(!f) {
			dfs(i+1);
		}
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> k;
	for(int f, t, c, i = 0; i< m; i++) {
		cin >> f >> t >> c;
		g[f].push_back({c, t});
	}
	for(int i = 1; i <= n; i++) {
		sort(all(g[i]));
		int no = 0;
		for(auto [c, v] : g[i]) {
			can[v].push_back(9*g[i].size() + no);
			no++;
		}
	}
	for(int i = 1; i <= n; i++) {
		sort(all(can[i]));
		for(int j = 1; j < can[i].size(); j++) comb[can[i][j]][can[i][j-1]] = 1;
		can[i].erase(unique(all(can[i])), can[i].end());
		for(int x = 0; x < can[i].size(); x++)
			for(int y = 0; y < x; y++) {
				comb[can[i][x]][can[i][y]] = comb[can[i][y]][can[i][x]] = 1;
			}
	}
	dfs(1);
	cout << ans;
}