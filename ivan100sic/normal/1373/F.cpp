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
		vector<ll> p(3*n+1), q(3*n+1);

		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=0; i<n; i++) cin >> b[i];

		for (int i=0; i<3*n; i++) p[i+1] = p[i] + a[i%n];
		for (int i=0; i<3*n; i++) q[i+1] = q[i] + b[i%n];

		ll v = q[0] - p[1], e = 0;
		for (int i=2; i<3*n; i++) {
			v = max(v, q[i-2] - p[i-1]);
			e = max(e, v + p[i] - q[i]);
		}

		bool ok = e == 0 && q[n] >= p[n];

		cout << (ok ? "YES\n" : "NO\n");
	}
}