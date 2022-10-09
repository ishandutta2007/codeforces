#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[100005], tot, n, h;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (ll i=1; i<=n; i++) {
		cin >> a[i];
		tot += a[i];
	}

	if (tot % 2) {
		cout << "NO";
		return 0;
	}

	h = tot / 2;

	{
		set<ll> s;
		ll zz = 0;
		for (ll i=1; i<=n; i++) {
			s.insert(a[i]);
			zz += a[i];
			if (s.count(zz - h)) {
				cout << "YES";
				return 0;
			}
			if (zz == h) {
				cout << "YES";
				return 0;
			}
		}
	}

	{
		set<ll> s;
		ll zz = 0;
		for (ll i=n; i>=1; i--) {
			s.insert(a[i]);
			zz += a[i];
			if (s.count(zz - h)) {
				cout << "YES";
				return 0;
			}
		}
	}

	cout << "NO";
}