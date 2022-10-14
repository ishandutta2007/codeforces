// Problem: E. Binary Subsequence Rotation
// Contest: Codeforces - Codeforces Round #651 (Div. 2)
// URL: https://codeforces.com/contest/1370/problem/E
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
	//multitest([&](){});
	int n;
	string s, t;
	cin >> n >> s >> t;
	if(count(all(s), '1') != count(all(t), '1'))
		return cout << "-1\n", 0;
	int a = 0, b = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == t[i]) continue;
		if(s[i]-'0') b = max(0, b-1), a++;
		else a = max(0, a-1), b++; 
	}
	cout << a+b << '\n';
}