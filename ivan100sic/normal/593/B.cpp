#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	ll x1, x2;

	cin >> n >> x1 >> x2;

	vector<pair<ll, ll>> a;

	for (int i=0; i<n; i++) {
		ll k, b;
		cin >> k >> b;
		a.push_back({k*x1 + b, k*x2 + b});
	}

	sort(a.begin(), a.end());

	ll px = -1e18;

	for (int i=1; i<n; i++) {
		if (a[i].second < a[i-1].second) {
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}