// Problem: C.   
// Contest: Codeforces - Codeforces Global Round 17
// URL: https://codeforces.com/contest/1610/problem/C
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
		vector<array<int, 2>> a(n);
		for(auto &[x, y] : a)
			cin >> x >> y;
		auto check = [&](int x) {
			int pos = 0;
			for(auto [a, b] : a) if(pos < x) {
				if(pos <= b && x-1-pos <= a)
					pos++;
			}
			return pos == x;
		};
		int ans = -1;
		for(int z = 1<<20;z>>=1;)
			ans += z*check(ans+z);
		cout << ans << '\n';
	});
	
}