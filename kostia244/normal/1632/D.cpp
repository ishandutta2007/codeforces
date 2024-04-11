// Problem: D. New Year Concert
// Contest: Codeforces - Codeforces Round #769 (Div. 2)
// URL: https://codeforces.com/contest/1632/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
	cin >> n;
	vector<array<int, 3>> st; 
	int ans = 0;
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		st.push_back({t, i, i});
		decltype(st) nst;
		for(auto [v, l, r] : st) {
			v = __gcd(v, t);
			while(nst.size() && nst.back()[0] == v) {
				l = nst.back()[1];
				nst.pop_back();
			}
			nst.push_back({v, l, r});
		}
		st = nst;
		reverse(all(st));
		int I = i;//oops
		for(int i = 0; i < st.size(); i++) {
			int pos = I-st[i][0]+1;
			if(st[i][1] <= pos && pos <= st[i][2]) {
				st = {{1, 0, I}};
				ans++;
			}
		}
		reverse(all(st));
		cout << ans << " ";
	}
	cout << '\n';
}
//2 -1 4 8 -1 3 6