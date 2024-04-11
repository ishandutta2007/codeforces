// Problem: A. ABC
// Contest: Codeforces - Codeforces Round #769 (Div. 2)
// URL: https://codeforces.com/contest/1632/problem/A
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
		string s;
		int n;
		cin >> n >> s;
		if(s.size() > 2) cout << "NO\n";
		else cout << (s.size() < 2 || s == "01" || s == "10" ? "YES" : "NO") << '\n';
	});
	
}