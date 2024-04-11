// Problem: B. Mirror in the String
// Contest: Codeforces - Good Bye 2021: 2022 is NEAR
// URL: https://codeforces.com/contest/1616/problem/B
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
		int n;
		string s;
		cin >> n >> s;
		string ans; ans += s[0], ans += s[0];
		int z = 1;
		while(z < s.size() && s[z-1] >= s[z])
			z++;
		string t = s.substr(0, z);
		auto tt = t;
		reverse(all(tt));
		t += tt;
		cout << min(ans, t) << '\n';
	});
	
}