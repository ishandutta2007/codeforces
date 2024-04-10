// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
ll a[111];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<n; i++) {
			string s;
			cin >> s;
			ll x = 0;
			for (int j=0; j<m; j++) {
				x = 2*x + (s[j] == '1');
			}
			a[i] = x;
		}
		sort(a, a+n);

		ll idx = ((1ll << m) - n - 1) / 2;

		ll l = 0, r = (1ll << m) - 1, o = -1;
		while (l <= r) {
			ll mid = (l+r) / 2;
			ll less = mid - (lower_bound(a, a+n, mid) - a);
			if (less > idx) {
				r = mid - 1;
			} else {
				o = mid;
				l = mid + 1;
			}
		}

		for (int i=0; i<m; i++)
			cout << ((o >> (m - 1ll - i)) & 1);
		cout << '\n';
	}
}