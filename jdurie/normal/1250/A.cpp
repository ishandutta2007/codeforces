#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll a[1010];
ll ans[2];
int main() {
	ll n;
	cin >> n;
	for(ll i = 0; i < n; i++) cin >> a[i];
	ll start = 0, end = n - 1, move = 0;
	while(start <= end)
		ans[move++ % 2] += a[start] >= a[end] ? a[start++] : a[end--];
	cout << ans[0] << " " << ans[1] << endl;
	return 0;
}