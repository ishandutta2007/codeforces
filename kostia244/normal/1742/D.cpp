// Problem:  
// Contest: Codeforces
// URL: https://m2.codeforces.com/contest/1742/problem/D
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
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		vector<int> hv(1001, -1);
		int ans = -1;
		for(int i = n; i--;) {
			if(hv[a[i]] == -1) {
				hv[a[i]] = i+1;
				for(int j = 1; j <= 1000; j++) if(hv[j] != -1 && __gcd(a[i], j) == 1) {
					ans = max(ans, i+1 + hv[j]);
				}
			}
		}
		cout << ans << '\n';
	});
	
}