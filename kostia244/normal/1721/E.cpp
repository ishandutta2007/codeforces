// Problem: E. Prefix Function Queries
// Contest: Codeforces - Educational Codeforces Round 134 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1721/problem/E
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
	string s, t;
	int q;
	cin >> s >> q;
	int n = s.size();
	vector<int> pi(n + 1);
	vector<array<int, 26>> memo(n + 12);
	for(auto &i : memo) i.fill(-1);
	auto f = [&](auto self, int pos, char c) {
		if(pos == -1) return 0;
		if(memo[pos][c-'a'] != -1)
			return memo[pos][c-'a'];
		return memo[pos][c-'a'] = s[pos] == c ? pos+1 : self(self, pi[pos], c);
	};
	pi[0] = -1;
	for(int i = 1; i <= n; i++)
		pi[i] = f(f, pi[i-1], s[i-1]);
	while(q--) {
		for(int i = n; i <= n+10; i++)
			memo[i].fill(-1);
		cin >> t;
		for(auto i : t) {
			pi.push_back(f(f, pi.back(), i));
			s += i;
			cout << pi.back() << " ";
		}
		cout << '\n';
		for(int i = t.size(); i--;) {
			s.pop_back();
			pi.pop_back();
		}
	}
	
}