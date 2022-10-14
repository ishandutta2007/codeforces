// Problem: E.  
// Contest: Codeforces - Codeforces Round #760 (Div. 3)
// URL: https://codeforces.com/contest/1618/problem/E
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

int main() {//https://atcoder.jp/contests/agc010/submissions/26522519
	cin.tie(0)->sync_with_stdio(0);
	multitest([&](){
		ll n, s = 0, S;
	    cin >> n;
	    vector<ll> a(n);
	    for(auto &i : a) cin >> i, s += i;
	    S = n*(n+1)/2;
	    if(s%S != 0) return report(0), 0;
	    s /= S;
	    vector<ll> ans;
	    for(int i = 0; i < n; i++) {
	        ll t = a[i]-a[(i+1)%n]+s;
	        ans.push_back(t/n);
	        if(t <= 0 || t%n) return report(0), 0;
	    }
	    for(int i = n-1; i >= 1; i--) swap(ans[i], ans[i-1]);
	    cout << "YES\n";
	    for(auto i : ans) 
	    	cout << i << " "; cout << endl;
	    return 0;
	});
}