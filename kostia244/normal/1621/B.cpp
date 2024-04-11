// Problem: B. Integers Shop
// Contest: Codeforces - Hello 2022
// URL: https://codeforces.com/contest/1621/problem/B
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
		array<int, 2> L {1<<30, 0}, R{-(1<<30), 0};
		auto C = R;
		for(int l, r, c, i = 0; i < n; i++) {
			cin >> l >> r >> c;
			L = min(L, array<int, 2>{l, c});
			R = max(R, array<int, 2>{r, -c});
			C = max(C, array<int, 2>{r-l+1, -c});
			int ans = L[1]-R[1];
			if(C[0] == R[0]-L[0]+1)
				ans = min(ans, -C[1]);
			cout << ans << '\n';
		}
	});
	
}