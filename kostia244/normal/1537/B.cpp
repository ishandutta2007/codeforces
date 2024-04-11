// Problem: B. Bad Boy
// Contest: Codeforces - Codeforces Round #726 (Div. 2)
// URL: https://codeforces.com/contest/1537/problem/B
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
		array<ll, 3> mode = {-1, 0, 0};
		ll n, m, x, y;
		cin >> n >> m >> x >> y;
		mode = max(mode, array<ll, 3>{min(x+y-2, n+m-x-y), 1, 1});
		mode = max(mode, array<ll, 3>{min(n-x+y-1, x-1+m-y), 1, m});
		cout << mode[1] << " " << mode[2] << " ";
		mode[1] ^= n^1; mode[2] ^= m^1;
		cout << mode[1] << " " << mode[2] << '\n';
	});
	
}