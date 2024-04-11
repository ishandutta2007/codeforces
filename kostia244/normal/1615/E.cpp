// Problem: E.  
// Contest: Codeforces - Codeforces Global Round 18
// URL: https://codeforces.com/contest/1615/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}
const int N = 2e5 + 3333;
int n, k;
vector<int> g[N];
vector<int> lvs;
ll dfs(int v, int p) {
	vector<int> ch;
	for(auto i : g[v]) if(i != p) {
		int t = dfs(i, v);
		ch.push_back(t);
	}
	sort(all(ch));
	if(ch.empty()) return {1};
	int ret = -69;
	ret = 1+ch.back();
	ch.pop_back();
	for(auto i : ch)
		lvs.push_back(i);
	return ret;
}
ll check(ll r, ll mb) {
	//(n-r-x)(r-x) = nr - r^2 - nx + x^2
	// cout << r << " " << mb << endl;
	vector<ll> ck {0, mb};
	ll v = n/2, ans = 1ll<<60;
	ck.push_back(v);
	ck.push_back(v+1);
	ck.push_back(v-1);
	for(auto i : ck) if(i >= 0 && i <= mb)
		ans = min(ans, (n-r-i)*(r-i));
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n >> k;
	k = min(k, n);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	int M = dfs(1, -1);
	lvs.push_back(M);
	sort(all(lvs), greater<>());
	// for(auto i : lvs) cout << i << " "; cout << endl;
	while(lvs.size() > k)
		lvs.pop_back();
	ll ans = check(0, n);
	//don't take all leaves
	ll block = 0, use = 0;
	for(auto i : lvs) {
		block += i, use++;
		ans = max(ans, check(use, n-block));
	}
	for(int i = 0; use+i <= k; use++) {
		ll r = use+i;
		//b in 0....n-block
		ans = max(ans, check(r, n-block));
	}
	cout << ans << '\n';
}