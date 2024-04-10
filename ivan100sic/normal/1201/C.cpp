#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
int a[200005];

bool moze(ll x) {
	ll y = 0;
	for (int i=n/2; i<n; i++)
		y += max(0ll, x-a[i]);
	return y <= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	ll l = a[n/2], r = 3e9, o = a[n/2];
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (moze(m)) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << o << '\n';
}