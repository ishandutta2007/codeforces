#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
const int maxn = 1e5 + 55, mod = 998244353;
using ll = long long;
int main() {
    cin.tie(0)->sync_with_stdio(0);
	ll t, a, b, x, y;
	cin >> t;
	while(t--) {
		cin >> x >> y >> a >> b;
		if(x > y) swap(x, y);
		y -= x;
		b = min(b, 2*a);
		cout << x*b + y*a << '\n';
	}
}