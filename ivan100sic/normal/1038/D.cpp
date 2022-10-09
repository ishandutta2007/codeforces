#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[500005];

bool cmpa(ll x, ll y) {
	return abs(x) < abs(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	if (n == 1)
		return cout << a[1], 0;

	sort(a+1, a+n+1, cmpa);

	int p=0, m=0, e=0;
	for (int i=1; i<=n; i++)
		if (a[i] > 0)
			p++;
		else if (a[i] < 0)
			m++;
		else
			e++;

	ll sol = 0;

	if (e || (p && m)) {
		for (int i=1; i<=n; i++)
			sol += abs(a[i]);
	} else {
		for (int i=2; i<=n; i++)
			sol += abs(a[i]);

		sol -= abs(a[1]);
	}

	cout << sol << '\n';
}