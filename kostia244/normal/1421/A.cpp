#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 1<<18, mod = 1000000007;

int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		ll a, b;
		cin >> a >> b;
		cout << (a+b - 2*(a&b)) << '\n';
	}
}