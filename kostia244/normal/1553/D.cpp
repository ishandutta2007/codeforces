// Problem: D. Backspace
// Contest: Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1553/problem/D
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		string s, t;
		cin >> s >> t;
		int n = s.size(), m = t.size();
		vector<vector<int>> nxt(n+5, vector<int>(26, n+4));
		for(int i = n; i--;) {
			for(int j = 0; j < 26; j++)
				nxt[i][j] = nxt[i+2][j];
			nxt[i][s[i]-'a'] = i;
		}
		array<int, 2> dp{n+4, n+4};
		for(int i = 0; i < n; i++) {
			if(s[i] == t[0] && dp[i&1] == n+4)
				dp[i&1] = i+1;
		}
		t.erase(t.begin());
		for(auto c : t) {
			c -= 'a';
			dp[0] = min(n+4, nxt[dp[0]][c]+1);
			dp[1] = min(n+4, nxt[dp[1]][c]+1);
		}
		int ok = 0;
		if(dp[0] <= n && (dp[0]+n)%2 == 0)
			ok = 1;
		if(dp[1] <= n && (dp[1]+n)%2 == 0)
			ok = 1;
		report(ok);
	});
	
}