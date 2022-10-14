// Problem: F. RBS
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/F
// Memory Limit: 512 MB
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
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	int n;
	cin >> n;	
	vector<string> s(n);
	vector<int> sum(n), mn(n);
	vector<vector<int>> cnt(n);
	vector<vector<int>> F(n);
	for(auto &i : s) {
		cin >> i;
	}
	for(int i = 0; i < n; i++) {
		cnt[i].resize(2*(int)s[i].size()+1);
		F[i].resize(2*(int)s[i].size()+1);
		for(auto x : s[i]) {
			sum[i] += x == ')' ? -1 : 1;
			cnt[i][sum[i]+(int)s[i].size()]++;
			mn[i] = min(mn[i], sum[i]);
			if(sum[i] == mn[i])
				F[i][sum[i]+(int)s[i].size()]++;
		}
	}
	vector<int> dp(1<<n, -(1<<24));
	dp[0] = 0;
	for(int msk = 0; msk < 1<<n; msk++) {
		int sm = 0;
		for(int i = 0; i < n; i++) if((msk>>i)&1) sm += sum[i];
		for(int nxt = 0; nxt < n; nxt++) if(!((msk>>nxt)&1)) {
			int T = 0;
			if(abs(sm) <= s[nxt].size())
				T = cnt[nxt][-sm + (int)s[nxt].size()];
			if(sm+mn[nxt] >= 0)
			dp[msk|(1<<nxt)] = 
				max(dp[msk|(1<<nxt)], 
					dp[msk] + T);	
		}
	}

	int ans = max(0, dp[(1<<n)-1]);
	for(int msk = 0; msk < 1<<n; msk++) {
		int sm = 0;
		for(int i = 0; i < n; i++) if((msk>>i)&1) sm += sum[i];
		for(int nxt = 0; nxt < n; nxt++) if(!((msk>>nxt)&1)) {
			int cur = dp[msk];
			int bal = -sm;
			int f = 0;
			if(abs(sm) <= (int)s[nxt].size())
				f = F[nxt][(-sm + (int)s[nxt].size())];
			ans = max(ans, cur + f);
		}
	}
	cout << ans << endl;
}