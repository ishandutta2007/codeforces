// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<ll> a(n);
		for (ll& x : a) cin >> x;
		ll dzabe = 0, cena = 0;
		for (int i=0; i<n; i++) {
			if (a[i] < 0) {
				ll d = min(-a[i], dzabe);
				dzabe -= d;
				a[i] += d;
				if (a[i] < 0) {
					cena += -a[i];
					a[i] = 0;
				}
			} else {
				dzabe += a[i];
				a[i] = 0;
			}
		}
		cout << cena << '\n';
	}
}