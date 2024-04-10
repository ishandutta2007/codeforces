#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, d;

int mul(int x, int y) {
	ll z = x * 1ll * y;
	if (z > 1e9)
		z = 1e9;
	return z;
}

int a[1005][1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> d;

	int prod = 1;
	// dve iste kolone ne smeju da postoje
	for (int i=0; i<d; i++)
		prod = mul(prod, k);

	if (prod < n) {
		cout << -1;
		return 0;
	}

	for (int i=0; i<n; i++) {
		int t = i;
		for (int j=0; j<d; j++) {
			a[j][i] = t % k + 1;
			t /= k;
		}
	}

	for (int i=0; i<d; i++) {
		for (int j=0; j<n; j++) {
			cout << a[i][j] << " ";
		}
		cout << '\n';
	}
}