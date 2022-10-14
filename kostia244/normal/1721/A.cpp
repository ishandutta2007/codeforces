// Problem: A. Image
// Contest: Codeforces - Educational Codeforces Round 134 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1721/problem/A
// Memory Limit: 512 MB
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
		cin >> s >> t;map<char,int> cnt;
		for(auto i : s) cnt[i]++;
		for(auto i : t) cnt[i]++;
		int ans=  0, mn = 4;
		for(auto [x, y] : cnt) ans = max(ans, y), mn = min(mn, y);
		cout << (mn == ans && ans == 2 ? 1 : (4 - ans)) << '\n';
	});
	
}