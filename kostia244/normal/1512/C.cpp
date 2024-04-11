// Problem: C. A-B Palindrome
// Contest: Codeforces - Codeforces Round #713 (Div. 3)
// URL: https://codeforces.com/contest/1512/problem/C
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
		int a, b;
		string s;
		cin >> a >> b >> s;
		int n = s.size();
		for(int i = 0; i < n; i++) {
			if(s[i] != '?') {
				if(s[n-1-i] == '?') {
					s[n-1-i] = s[i];
				}
				if(s[n-1-i] != s[i]) {
					cout << "-1\n";
					return;
				}
			}
		}
		for(auto i : s) {
			if(i=='0')a--;
			if(i=='1')b--;
		}
		if(n&1) {
			if(s[n/2]=='?') {
				if(a&1) a--, s[n/2] = '0';
				else if(b&1) b--, s[n/2] = '1';
			}
		}
		for(int i = 0; i < n; i++) {
			if(s[i] == '?') {
				if(a) {
					s[i] = s[n-1-i] = '0';
					a -= 2;
				}else 
				if(b) {
					s[i] = s[n-1-i] = '1';
					b-=2;
				}
			}
		}
		if(a||b) {
			cout << "-1\n";
			return;
		}
		cout << s << '\n';
	});
	
}