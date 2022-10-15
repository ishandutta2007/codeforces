#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;


ll puzz[55];
int main() {
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < m; i++) cin >> puzz[i];
	sort(puzz, puzz + m);
	ll mn = puzz[n - 1] - puzz[0];
	for(ll i = n; i < m; i++)
		mn = min(mn, puzz[i] - puzz[i - n + 1]);
	cout << mn << endl;
	return 0;
}