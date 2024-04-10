#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, a, b;

int e;

void cikl(int x) {
	for (int i=1; i<x; i++) {
		cout << e+i+1 << ' ';
	}
	cout << e+1 << ' ';
	e += x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> a >> b;

	for (ll i=0; i<=n; i++) {
		ll bx = n - a*i;
		if (bx % b) {
			continue;
		}
		if (bx < 0) {
			continue;
		}

		ll j = bx / b;

		for (int k=0; k<i; k++) {
			cikl(a);
		}
		for (int k=0; k<j; k++) {
			cikl(b);
		}
		return 0;

	}
	cout << -1;
	return 0;
}