// Problem: D.    
// Contest: Codeforces - Codeforces Global Round 19
// URL: https://codeforces.com/contest/1637/problem/D
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
		bitset<10100> b;
		b[0] = 1;
		ll ans = 0, S = 0;
		vector<int> U(n), V(n);
		for(int t, i = 0; i < 2*n; i++) {
			cin >> t;
			(i < n ? U : V)[i%n] = t;
			S += t;
			ans += (n-2)*1ll*t*t;
		}
		for(int i = 0; i < n; i++) b = (b<<U[i])|(b<<V[i]);
		ll B = (1ll<<60);
		for(int z = 0; z < 10100; z++) if(b[z]) {
			B = min(B, z*1ll*z + (S-z)*1ll*(S-z));
		}
		ans += B;
		cout << ans << '\n';
	});
	
}