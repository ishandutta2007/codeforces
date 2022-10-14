// Problem: B.  
// Contest: Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1534/problem/B
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
		cin >> n;ll ans  = 0;
		vector<int> a(n+2);
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) {
			if(a[i] > max(a[i-1], a[i+1]))
				ans -= a[i]-max(a[i-1], a[i+1]);
			ans += abs(a[i]-a[i-1]);
		}
		ans += a[n];
		cout << ans << '\n';
	});
	
}