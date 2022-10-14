// Problem: C. Train and Queries
// Contest: Codeforces - Codeforces Round #805 (Div. 3)
// URL: https://codeforces.com/contest/1702/problem/C
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
	multitest([&](){
		int n, q;
		cin >> n >> q;
		map<int, int> L, R;
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			if(!L.count(t)) L[t] = i;
			R[t] = i;
		}
		for(int a, b; q--;) {
			cin >> a >> b;
			int ok = 1;
			if(L.count(a) && R.count(b)) {
				ok &= L[a] <= R[b];
			} else ok = 0;
			report(ok);
		}
	});
	
}