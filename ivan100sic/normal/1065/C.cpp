#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, k;
ll a[200005];
ll c[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		c[a[i]]++;
	}

	for (int i=200000; i>=1; i--)
		c[i] += c[i+1];

	ll z = 0, sol = 0;

	for (int i=200000; i>=1; i--) {
		if (c[i] == n)
			break;
		if (z + c[i] <= k) {
			z += c[i];
		} else {
			sol++;
			z = c[i];
		}
	}

	if (z)
		sol++;

	cout << sol << '\n';
}