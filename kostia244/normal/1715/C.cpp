// Problem: C. Monoblock
// Contest: Codeforces - Codeforces Round #816 (Div. 2)
// URL: https://codeforces.com/contest/1715/problem/C
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
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(auto &i : a) cin >> i;
	ll ans = 0, sum = 0;
	for(int i = 0; i+1 < n; i++)
		ans += (i+1)*1ll*(n-1-i)*(a[i]==a[i+1]), sum += (i+1)*1ll*(n-i);
	sum += n;
	for(int i, p; m--;) {
		cin >> i >> p;
		i--;
		if(i) {
			ans -= i*1ll*(n-i)*(a[i]==a[i-1]);
		}
		if(i+1 < n) {
			ans -= (i+1)*1ll*(n-1-i)*(a[i]==a[i+1]);
		}
		a[i] = p;
		if(i) {
			ans += i*1ll*(n-i)*(a[i]==a[i-1]);
		}
		if(i+1 < n) {
			ans += (i+1)*1ll*(n-1-i)*(a[i]==a[i+1]);
		}
		cout << sum - ans << '\n';
	}
	
}