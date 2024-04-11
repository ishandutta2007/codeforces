// Problem: A. AquaMoon and Strange Sort
// Contest: Codeforces - Codeforces Round #732 (Div. 1)
// URL: https://codeforces.com/contest/1545/problem/A
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
		int n;
		cin >> n;
		vector<int> a, b, d, c;
		for(int t, i = 0; i < n; i++) {
			cin >> t;
			a.push_back(t);
			(i&1?c:b).push_back(t);
		}
		sort(all(a));
		sort(all(b));
		sort(all(c));
		for(int i = 0; i < n; i++) {
			if(i<b.size())
				d.push_back(b[i]);
			if(i<c.size())
				d.push_back(c[i]);
		}
		report(a==d);
	});
	
}