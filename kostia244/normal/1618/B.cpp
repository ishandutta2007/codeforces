// Problem: B.  
// Contest: Codeforces - Codeforces Round #760 (Div. 3)
// URL: https://codeforces.com/contest/1618/problem/B
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
		cin >> n;
		vector<string> a(n-2);
		for(auto &i : a) cin >> i;
		int bad = -1;
		for(int i = 0; i+1 < a.size(); i++)
			if(a[i][1] != a[i+1][0]) {
				if(bad == -1) bad = i;
				if(bad != i) bad = -2;
			}
		for(int i = 0; i< a.size(); i++) {
			if(i-1 == bad) cout << (i?a[i-1][1]:'a');
			cout << a[i][0];
		}
		cout << a.back()[1] << '\n';
	});
	
}