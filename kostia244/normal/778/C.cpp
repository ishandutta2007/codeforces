#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 300300, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, V[maxn];
int to[maxn][26], fake[maxn][26], sz[maxn], deg[maxn];
vector<pair<int, int>> g[maxn];
int T = 1;
void check(int v, int r, int &cnt) {
	//cout << v << " -- " << r << endl;
	for(auto [i, c] : g[v]) {
		//cout << v << " -> " << i << " ( " << c << " ) | " << r << " | " << to[r][c] << endl;
		if(fake[r][c] && fake[r][c] < T) to[r][c] = 0;
		if(to[r][c]) {
			check(i, to[r][c], cnt);
		} else {
			cnt += sz[i];
			to[r][c] = i;
			fake[r][c] = T;
		}
	}
}
void dfs(int v, int h) {
	int big = -1;
	sz[v] = 1;
	for(auto &[i, c] : g[v]) {
		dfs(i, h+1);
		sz[v] += sz[i];
		if(big == -1 || sz[i] > sz[big]) big = i;
	}
	if(big == -1) return;
	V[h] += sz[big] - sz[v];
	T++;
	//cout << "Going through " << v << " " << g[v].size() << endl;
	for(auto &[i, c] : g[v]) if(i != big) {
		check(i, big, V[h]);
	}
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	int f, t; char c;
	for(int i = 1; i < n; i++) {
		cin >> f >> t>> c;--f, --t;
		to[f][c-'a'] = t;
		g[f].push_back({t, c-'a'});
		deg[f]++;
		//cout << f << " " << t << " " << c << endl;
	}
	dfs(0, 0);
	array<int, 2> ans = {n, 1};
	for(int i = 0; i <= n; i++) {
		ans = min(ans, {n+V[i], i+1});
		//cout << i << " = " << V[i] << endl;
	}
	cout << ans[0] << endl << ans[1] << endl;
}