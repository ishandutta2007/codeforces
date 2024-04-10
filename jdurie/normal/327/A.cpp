#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;


int main() {
	ll n, mn = 0, curr = 0, ones = 0, x, ans = 0;
	cin >> n;
	for(ll i = 0; i < n; i++) {
		cin >> x;
		curr += x == 1 ? -1 : 1;
		ans = max(ans, curr - mn);
		mn = min(mn, curr);
		ones += x == 1 ? 1 : 0;
	}
	cout << (ones == n ? n - 1 : ones + ans) << endl;
	return 0;
}