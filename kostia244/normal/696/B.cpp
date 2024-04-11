#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<17, mod = 1e9 + 7 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, sz[maxn];
ld ex[maxn];
vi g[maxn];
void szs(int v) {
	sz[v] = 1;
	for(auto i : g[v]) szs(i), sz[v] += sz[i];
}
void dfs(int v, ld cur = 0) {
	ex[v] = cur;
	for(auto i : g[v]) {
		dfs(i, cur + 2 + (sz[v]-1-sz[i]));
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int f, i = 2; i <= n; i++) {
		cin >> f;
		g[f].pb(i);
	}
	szs(1);
	dfs(1);
	cout << fixed << setprecision(1);
	for(int i = 1; i <= n; i++) cout << ex[i]*0.5 + 1 << " ";
	return 0;
}