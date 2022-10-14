#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using ll = long long;
#define int ll
using namespace std;
const int maxn = 1<<19;
const int inf = 1e18;
int32_t main() {
	ios::sync_with_stdio(0);
	ll n, r = 1;
	cin >> n;
	for(int i = 1; i <= n; i++) r *= i;
	r /= n/2;
	r /= n;
	cout << r << endl;
	return 0;
}