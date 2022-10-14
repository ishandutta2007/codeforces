// Problem: C. MAX-MEX 
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		int n = s.size();
		cin >> n >> s >> t;
		string cur;
		auto solve = [&]() {
			int prv = -1, ans = 0;
			for(auto i : cur) {
				if(i == '0') {
					ans++;
					if(prv == 1)
						ans++, prv = -1;
					else
						prv = 0;
				} else {
					if(prv == 0)
						ans++, prv = -1;
					else
						prv = 1;
				}
			}
			return ans;
		};
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(s[i] != t[i])
				ans+=2+solve(), cur.clear();
			else 
				cur += s[i];
		}
		ans += solve();
		cout << ans << '\n';
	});
	
}