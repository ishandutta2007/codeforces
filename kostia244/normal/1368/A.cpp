#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<19, mod = 1e9 + 7, i2 = (mod+1)/2;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll t;
	cin >> t;
	while(t--) {
		ll a, b, n, op = 0;
		cin >> a >> b >> n;
		while(max(a, b) <= n) {op++;
			if(a < b) a += b;
			else b += a;
		}
		cout << op << '\n';
	}
	return 0;
}