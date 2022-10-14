#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n, m, a, b;
	cin >> n >> m >> a >> b;
	ll mn = n * a;
	for(ll k = 0; (k - 1) * m <= n; k++)
		mn = min(mn, k * b + max(0LL, n - k * m) * a);
	cout << mn << endl;
}