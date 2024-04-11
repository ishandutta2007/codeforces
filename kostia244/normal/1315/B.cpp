// Problem: B. Homecoming
// Contest: Codeforces - Codeforces Round #623 (Div. 2, based on VK Cup 2019-2020 - Elimination Round, Engine)
// URL: https://codeforces.com/contest/1315/problem/B
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
		int a, b, p;
		string s;
		cin >> a >> b >> p >> s;
		s.pop_back();
		reverse(all(s));
		int i = 0;
		ll cur = 0;
		for(; i < s.size(); i++) {
			if(i == 0 || s[i] != s[i-1])
				cur += s[i] == 'A' ? a : b;
			if(cur > p) break;
		}
		cout << int(s.size())+1-i << '\n';
	});
}