#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

ll a[101];
int main() {
	ll n;
	cin >> n;
	for(ll i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for(ll i = 0; i < n; i++) cout << a[i] << " ";
	return 0;
}