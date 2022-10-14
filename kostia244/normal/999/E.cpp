#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;
const int maxn = 5005, mod = 998244353;
int n, m, s, mom = 3;
vi g[maxn];
int vis[maxn];
int tvis[maxn];
void go(int v) {
	vis[v] = 1;
	for(auto i : g[v]) if(!vis[i]) go(i);
}
int cnt(int v) {
	tvis[v] = mom;
	int cur = 1;
	for(auto i : g[v]) if(!vis[i]&&tvis[i]!=mom) cur += cnt(i);
	return cur;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> s;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
	}
	pair<int, int> t;
	int ans = 0, cur = cnt(s);
	go(s);
	for(;cur != n; ans++) {
		pair<int, int> t = {-(1<<30), -1};
		for(int i = 1; i <= n; i++) if(!vis[i]) ++mom, t = max(t, {cnt(i), i});
		cur += t.first;
		go(t.second);
	}
	cout << ans;
}