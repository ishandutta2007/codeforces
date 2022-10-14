#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<20, maxk = 1<<11, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m;
vector<int> g[maxn];
set<pair<int, int>> q;
int dp[maxn];
bitset<maxn> col;
int vis[maxn];
void enq(int v, int d) {
	if(vis[v/2]) return;
	q.erase({max(dp[v], dp[v^1]), v/2});
	dp[v] = min(dp[v], d);
	q.insert({max(dp[v], dp[v^1]), v/2});
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	for(int f, t, c, i = 0; i < m; i++) {
		cin >> f >> t >> c;
		g[t].push_back(2*f+c);
	}
	memset(dp, 0x3f, sizeof dp);
	for(int i = 1; i <= n; i++) q.insert({dp[i], i});
	enq(2*n, 0);
	enq(2*n+1, 0);
	while(!q.empty()) {
		auto [dist, v] = *q.begin();q.erase(q.begin());
		col[v] = dist==dp[2*v+1];
		vis[v] = 1;
		for(auto &i : g[v]) enq(i, 1+dist);
	}
	int r = max(dp[2], dp[3]);
	if(r > n) r = -1;
	cout << r << '\n';
	for(int i = 1; i <= n; i++) cout << col[i]; cout << endl;
}