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
		vector<ll> a(n), b(n);
		for (ll& x : a) cin >> x;
		for (ll& x : b) cin >> x;

		ll aa = *min_element(begin(a), end(a));
		ll bb = *min_element(begin(b), end(b));

		ll z = 0;
		for (int i=0; i<n; i++) {
			z += max(a[i]-aa, b[i]-bb);
		}

		cout << z << '\n';
	}
}