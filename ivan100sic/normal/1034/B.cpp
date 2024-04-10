#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll solve(ll n, ll m) {
	if (n > m)
		swap(n, m);
	if (n == 1) {
		int a[] = {0, 1, 2, 3, 2, 1};
		return m - a[m%6];
	} else if (n == 2) {
		if (m < 8) {
			int a[] = {0, 2, 4, 2, 0, 0, 0, 2};
			return 2*m - a[m];
		} else {
			return 2*m;
		}
	} else {
		return n*m - (n*m % 2);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, m;
	cin >> n >> m;
	cout << solve(n, m) << '\n';
}