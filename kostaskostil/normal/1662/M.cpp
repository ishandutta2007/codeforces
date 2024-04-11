// Problem: M. Bottle Arrangements
// Contest: Codeforces - SWERC 2021-2022 - Online Mirror (Unrated, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/contest/1662/problem/M
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
		int n, m;
		cin >> n >> m;
		int x = 0, y = 0, u = 0, v = 0;
		while(m--) {
			cin >> u >> v;
			x = max(x, u);
			y = max(y, v);
		}
		if(x+y <= n) {
			x += n-x-y;
			while(x--) cout << "R";
			while(y--) cout << "W";
			cout << '\n';
		} else {
			cout << "IMPOSSIBLE\n";
		}
		
	});
	
}