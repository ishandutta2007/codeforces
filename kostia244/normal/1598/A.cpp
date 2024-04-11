// Problem: A. Computer Game
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/A
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
		int n;
		string a, b;
		cin >> n >> a >> b;
		vector<vector<int>> can(n, vector<int>(2, 0));
		can[0][0] = 1;
		for(int i = 0; i < n; i++) {
			if(a[i] == '1') can[i][0] = 0;
			if(b[i] == '1') can[i][1] = 0;
			if(i+1 == n) break;
			can[i+1][0] |= can[i][0]|can[i][1];
			can[i+1][1] |= can[i][0]|can[i][1];
		}
		report(can.back().back());
	});
	
}