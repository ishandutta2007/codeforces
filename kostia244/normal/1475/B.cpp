#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 4055, mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		ll x = n/2020;
		n %= 2020;
		cout << (n<=x?"YES":"NO") << '\n';
	}
}