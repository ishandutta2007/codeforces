// Problem: C. String Transformation 2
// Contest: Codeforces - Codeforces Round #659 (Div. 1)
// URL: https://codeforces.com/contest/1383/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
struct dsu {
	vector<int> e;
	dsu(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};
const int N = 20;
int dp[1<<N], G[N];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		string s, t;
		cin >> s >> s >> t;
		memset(G, 0, sizeof G);
		for(int i = 0; i < 1<<N; i++)
			dp[i] = 2*__builtin_popcount(i);
		dsu d(N);
		for(int i = 0; i < s.size(); i++) {
			d.join(s[i]-'a', t[i]-'a');
			G[s[i]-'a']|=1<<(t[i]-'a');
		}
		dp[0] = 0;
		for(int i = 0; i < 1<<N; i++) {
			for(int j = 0; j < N; j++) if(!(i&G[j]))
				dp[i|(1<<j)] = min(dp[i|(1<<j)], dp[i]+1);
		}
		for(int i = 0; i < 1<<N; i++) {
			for(int j = 0; j < N; j++)
				dp[i|(1<<j)] = min(dp[i|(1<<j)], dp[i]+2);
		}
		int ans = 0;
		vector<int> vis(N);
		for(int i = 0; i < N; i++) if(!vis[i]) {
			int msk = 0;
			for(int j = 0; j < N; j++) if(d.sameSet(i, j))
				vis[j] = 1, msk |= 1<<j;
			ans += dp[msk]-1;
		}
		cout << ans << '\n';
	});
	
}