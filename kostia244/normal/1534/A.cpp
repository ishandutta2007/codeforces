// Problem: A. Colour the Flag
// Contest: Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1534/problem/0
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
char f[1010][1010];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		int n, m;
		cin >> n >> m;
		
		char c;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				cin >> f[i][j];
			}
		}
		int a = 1, b = 1;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				char c = (i+j)&1 ? 'R' : 'W';
				if(f[i][j] == '.') continue;
				if(f[i][j] == c)
					b = 0;
				else 
					a = 0;
			}
		report(a||b);
		if(a||b)
		for(int i = 0; i < n; i++,cout<<'\n')
			for(int j = 0; j < m; j++) {
				char c = (i+j+b)&1 ? 'R' : 'W';
				cout << c;
				}
	});
	
}