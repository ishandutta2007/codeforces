#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
	xM - K >= L
	xM <= N

	L + K <= xM <= N
	min x
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, m, k, l;
	cin >> n >> m >> k >> l;

	ll x = -1;
	if ((l + k) % m == 0) {
		x = (l + k) / m;
	} else {
		x = (l + k) / m + 1;
	}

	if (x*m <= n) {
		cout << x << '\n';
	} else {
		cout << "-1\n";
	}
}