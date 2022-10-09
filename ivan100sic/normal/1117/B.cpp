#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n, m, k;
	cin >> n >> m >> k;
	k++;
	for (ll i=0; i<n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);

	ll z = (a[n-1] * (k-1) + a[n-2]) * (m/k);
	z += a[n-1] * (m%k);
	cout << z << '\n';
}