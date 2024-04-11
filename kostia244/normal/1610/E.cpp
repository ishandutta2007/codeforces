// Problem: E. AmShZ  G.O.A.T.
// Contest: Codeforces - Codeforces Global Round 17
// URL: https://codeforces.com/contest/1610/problem/E
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
		vector<int> a(n);
		map<int, int> cnt;
		for(auto &i : a) cin >> i, cnt[i]++;
		int ans = max(0, n-2);
		for(auto i : cnt) ans = min(ans, n-i.second);
		for(int st = 0; st+1 < n; st++) if(a[st] != a[st+1]) {
			int p = st+1, C = cnt[a[st]];
			while(p!=n) {
				C++;
				p = lower_bound(all(a), 2*a[p]-a[st])-a.begin();
			}
			ans = min(ans, n-C);
		}
		cout << ans << '\n';
	});
	
}