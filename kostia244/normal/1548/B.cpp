// Problem: B. Integers Have Friends
// Contest: Codeforces - Codeforces Round #736 (Div. 1)
// URL: https://codeforces.com/contest/1548/problem/B
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
		#define int long long
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		vector<int> b;
		for(int i = 1; i < n; i++)
			b.push_back(abs(a[i]-a[i-1]));
		vector<array<int, 2>> c;
		int ans = 1;
		for(int i = 0; i < n-1; i++) {
			vector<array<int, 2>> nw {{b[i], i}};
			for(auto [val, L] : c) {
				val = __gcd(val, nw.back()[0]);
				if(val == nw.back()[0])
					nw.back()[1] = L;
				else
					nw.push_back({val, L});
			}
			c = nw;
			if(c.back()[0] == 1) c.pop_back();
			if(!c.empty()) {
				ans = max(ans, i-c.back()[1]+2);
			}
		}
		cout << ans << '\n';
	});
	
}