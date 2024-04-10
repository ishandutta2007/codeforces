// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll a[1000005], n, z, q, r;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (ll i=0; i<n; i++) {
		cin >> a[i];
		a[i] -= i;
		z += a[i];
	}

	q = z / n;
	r = z % n;
	for (ll i=0; i<n; i++) {
		a[i] = q + (i < r) + i;
		cout << a[i] << " \n"[i == n-1];
	}

}