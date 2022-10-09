#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[1005][1005];

ll isqrt(ll x) {
	ll z = sqrt(ld(x));
	while (z*z < x)
		z++;
	while (z*z > x)
		z--;
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> a[i][j];

	for (int i=0; i<n; i++) {
		int j = (i+1) % n;
		int k = (i+2) % n;
		cout << isqrt(a[i][j] * a[i][k] / a[j][k]) << " \n"[i == n-1];
	}
}