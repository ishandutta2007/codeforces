// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll a[300005], q[300005], z, n = 1;

int main() {
	ios::sync_with_stdio(!cin.tie(0));
	cout << setprecision(10) << fixed;

	int t;
	cin >> t;
	while (t--) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			ll b, x;
			cin >> b >> x;
			q[b] += x;
			z += b*x;
		} else if (tp == 2) {
			ll x;
			cin >> x;
			a[n++] = x;
			z += x;
		} else {
			q[n-1] += q[n];
			z -= a[n-1] + q[n];
			q[n] = 0;
			n--;
		}

		cout << ld(z)/n << '\n';
	}
}