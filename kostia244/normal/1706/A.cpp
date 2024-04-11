// Problem: A. Another String Minimization Problem
// Contest: Codeforces - Codeforces Round #809 (Div. 2)
// URL: https://codeforces.com/contest/1706/problem/A
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
		int n, k;
		cin >> k >> n;
		string s(n, 'B');
		for(int t, i = 0; i < k; i++) {
			cin >> t;
			t--;
			t = min(t, n - 1 - t);
			if(s[t] == 'A') t = n - 1 - t;
			s[t] = 'A';
		}
		cout << s << '\n';
	});
	
}