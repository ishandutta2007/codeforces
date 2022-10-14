// Problem: D. Exact Change
// Contest: Codeforces - Educational Codeforces Round 119 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1620/problem/D
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
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		int ans = 1e9;
		for(int i = 0; i < 2; i++) {
			for(int j = 0; j < 3; j++) {
				int R = 0;
				for(auto v : a) {
					int cur = 1e9;
					for(int x = 0; x <= i; x++)	
						for(int y = 0; y <= j; y++)
							if(v-x-2*y >= 0 && (v-x-2*y)%3 == 0)
								cur = min(cur, (v-x-2*y)/3);
					R = max(R, cur);
				}
				ans = min(ans, R+i+j);
			}
		}
		cout << ans << '\n';
	});
	
}