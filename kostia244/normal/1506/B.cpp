// Problem: B. Partial Replacement
// Contest: Codeforces - Codeforces Round #710 (Div. 3)
// URL: https://codeforces.com/contest/1506/problem/B
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
		int n, k;
		string s;
		cin >> n >> k >> s;
		vector<int> a;
		for(int i = 0; i < n; i++) if(s[i] == '*') a.push_back(i);
		int ans = 0, i = 0;n = a.size();
		while(i != n-1) {
			int j = i;
			ans++;
			while(j < n && a[j]-a[i]<=k) j++;
			i = j-1;
		}
		cout << ans+1 << '\n';
	});
	
}