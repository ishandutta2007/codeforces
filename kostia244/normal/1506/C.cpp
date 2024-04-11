// Problem: C. Double-ended Strings
// Contest: Codeforces - Codeforces Round #710 (Div. 3)
// URL: https://codeforces.com/contest/1506/problem/C
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
		string a, b;
		cin >> a >> b;
		int n = a.size();
		int m = b.size();
		a += "X"; b += "Y";int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++) {
				int k = 0;
				while(a[i+k] == b[j+k]) k++;
				ans = max(ans, k);
			}
		cout << a.size()+b.size()-2*ans-2 << '\n';
	});
	
}