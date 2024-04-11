// Problem: A. Game of Life
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/A
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
		int n, m;string s;
		cin >> n >> m >> s;
		m = min(m, 1010);
		s = "0" + s + "0";
		for(auto &i : s) i -= '0';
		string t;
		for(int z = 0; z < m; z++) {
			t=s;
			for(int i = 1; i <= n; i++)
				t[i] |= s[i-1]^s[i+1];
			t.swap(s);
		}
		for(int i = 1; i <= n; i++)
			cout << char('0'+s[i]);cout<<'\n';
	});
	
}