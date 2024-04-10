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
		ll n, x;
		cin >> n >> x;
		vector<ll> a(n);
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}

		sort(begin(a), end(a));
		int fodder = 0, t = 0;
		for (int i=n-1; i>=0; i--) {
			fodder++;
			if (a[i] * fodder >= x) {
				int u = (x + a[i] - 1) / a[i];
				fodder -= u;
				t++;
			}
		}

		cout << t << '\n';
	}
}