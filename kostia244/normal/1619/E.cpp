// Problem: E. MEX and Increments
// Contest: Codeforces - Codeforces Round #762 (Div. 3)
// URL: https://codeforces.com/contest/1619/problem/E
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
		vector<ll> freq(n+1);
		for(int t, i = n; i--;) {
			cin >> t;
			freq[t]++;
		}
		vector<ll> res(n+1, -1);
		multiset<ll> hv;
		ll ans = 0;
		for(int j = 0, i = 0; i <= n; i++) {
			while(j < i) {
				if(hv.empty()) break;
				if(j-*hv.rbegin() < 0) break;
				ans += j-*hv.rbegin();
				hv.erase(hv.find(*hv.rbegin()));
				j++;
			}
			if(j == i) res[i] = ans+freq[i];
			while(freq[i]--)
				hv.insert(i);
		}
		for(auto i : res) cout << i << " "; cout << '\n';
	});
	
}