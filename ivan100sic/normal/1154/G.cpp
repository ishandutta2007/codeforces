#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[10000005];
int a[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		e[x] += i;
		a[i] = x;
	}
	ll sol = 1231231231231233123ll;
	int p = -1, q = -1;
	for (int g=1; g<=10'000'000; g++) {
		int x = -1, y = -1;
		for (int i=g; i<=10'000'000; i+=g) {
			if (e[i].size() >= 1) {
				// uzmi jednog
				if (x == -1)
					x = e[i][0];
				else if (y == -1)
					y = e[i][0];
			}
			if (e[i].size() >= 2) {
				if (x == -1)
					x = e[i][1];
				else if (y == -1)
					y = e[i][1];
			}

			if (y != -1) {
				ll z = a[x] * 1ll * a[y] / g;
				if (z < sol) {
					sol = z;
					p = x;
					q = y;
				}
			}
		}
	}
	if (p > q)
		swap(p, q);
	cout << p << ' ' << q << '\n';
}