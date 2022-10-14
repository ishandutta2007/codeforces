#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 1<<17, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, F[maxn], vis[maxn], vise[maxn], ign[maxn];
array<ll, 2> answer = {1, 0};
vector<array<int, 2>> e;
vector<int> g[maxn], ord;
void dfs(int v) {
	if(vis[v]) return;
	vis[v] = 1;
	for(auto &i : g[v])
		if(!vise[i/2]) {
			ord.push_back(i);
			vise[i/2] = 1;
			dfs(e[i][0]);
		}
}
bool eval(int i, int x, int y = 0) {
	return (e[i][1]^(x+2*y)) > 0;
}
int add(int a, int b) { return a+b>=mod?a+b-mod:a+b; }
int getbit(int i, int j) { return (i>>j)&1; }
int setbit(int i, int j, int v = 1) { return min(i, i ^ (1<<j)) + (v<<j); }
array<int, 8> z = {0, 0, 0, 0, 0, 0, 0, 0};
void process(int v) {
	ord.clear();
	dfs(v);
	vector<array<int, 8>> dp (ord.size()+1, z);
	if(F[v] == -1) dp[0][0] = dp[0][6] = 1;
	else dp[0][F[v]] = dp[0][7^F[v]] = 1;
	for(int i = 0; i < ord.size(); i++) {
		for(int msk = 0; msk < 8; msk++) {
			for(int v = 0; v < 2; v++) {
				int nmsk = setbit(msk, 1, v) ^ eval(ord[i], getbit(msk, 1), v);
				if(F[e[ord[i]][0]] != -1)
					nmsk ^= v ^ F[e[ord[i]][0]];
				dp[i+1][nmsk] = add(dp[i+1][nmsk], dp[i][msk]);
			}
		}
	}
	array<ll, 2> ans = {0, 0};
	for(int i = 0; i < 8; i++)
		if(g[v].size() < 2 || getbit(i, 1) == getbit(i, 2)) ans[i&1] = add(ans[i&1], dp.back()[i]);
	ll Z = (ans[0]*answer[0] + ans[1]*answer[1])%mod;
	ll O = (ans[0]*answer[1] + ans[1]*answer[0])%mod;
	answer = {Z, O};
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	memset(F, -1, sizeof F);
	cin >> n >> m;
	int u = 1, ft = 1;
	for(int t,x,y,i = 0; i < n; i++) {
		cin >> t >> x;
		if(t == 2) cin >> y;
		if(t == 1 || x == y) {
			F[abs(x)] = x<0;
		} else if(x == -y) {
			u = (u+u)%mod, ft ^= 1;
			ign[abs(x)] = 1;
		} else {
			g[abs(x)].push_back(e.size());
			e.push_back({abs(y), (x<0) + (y<0) + (y<0)});
			g[abs(y)].push_back(e.size());
			e.push_back({abs(x), (y<0) + (x<0) + (x<0)});
		}
	}
	vector<int> order(m);
	iota(all(order), 1);
	sort(all(order), [](auto i, auto j) { return g[i].size() < g[j].size(); });
	for(auto i : order) if(!ign[i] && !vis[i]) process(i);
	cout << answer[ft]*u%mod;
}