// Problem: G. Good Key, Bad Key
// Contest: Codeforces - Codeforces Round #806 (Div. 4)
// URL: https://codeforces.com/contest/1703/problem/G
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
#define int ll
	multitest([&](){
		int n, k;
		cin >> n >> k;
		vector<int> s(n);
		for(auto &i : s) cin >> i;
		ll ans = 0, cur = 0;
		for(int a = 0; a <= n; a++) {
			ll curr = cur;
			for(int b = 0; a + b < n && b <= 30; b++) {
				curr += s[a+b]>>(b+1);
				ans = max(curr, ans);
			}
			if(a < n) cur += s[a] - k;
			ans = max(ans, cur);
		}
		cout << ans << '\n';
	});
	
}