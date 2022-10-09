#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, h, k;
ll a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> h >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];

	ll t = 0, z = 0, i = 0;

	while (1) {
		// ubaci?
		while (i < n && t + a[i] <= h)
			t += a[i++];
		// rokaj
		if (i < n) {
			ll q = t - (h - a[i]);
			q = (q + k - 1) / k;
			z += q;
			t = max(0ll, t-q*k);
		} else {
			z += (t + k - 1) / k;
			break;
		}
	}
	cout << z << '\n';
}