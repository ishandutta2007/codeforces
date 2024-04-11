// Problem: C. Smallest Word
// Contest: Codeforces - Codeforces Round #519 by Botan Investments
// URL: https://codeforces.com/contest/1043/problem/C
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
void solve(string s, int type) {
	if(s.empty()) return;
	char c = s.back();
	s.pop_back();
	if(type) c ^= 'a'^'b';
	if(c == 'b') {
		solve(s, type);
		cout << "0 ";
	} else {
		solve(s, type^1);
		cout << "1 ";
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	string s;
	cin >> s;
	solve(s, 0);
}