#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int x[2005], y[2005];

int a[1005][1005];

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void sredi(int& x, int& y) {
	int d = gcd(abs(x), abs(y));
	x /= d;
	y /= d;
	if (x < 0) {
		x *= -1;
		y *= -1;
	} else if (x == 0) {
		y = abs(y);
	}

	y += 501;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
	}

	ll sol = 0;

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) if (j != i) {
			int xx = x[i] - x[j];
			int yy = y[i] - y[j];

			sredi(xx, yy);

			//cerr << "sredjeno: " << xx << ' ' << yy << '\n';

			sol += (a[xx][yy]++);

		}

		for (int j=0; j<n; j++) if (j != i) {
			int xx = x[i] - x[j];
			int yy = y[i] - y[j];

			sredi(xx, yy);
			a[xx][yy]--;
		}
	}

	cout << 1ll * n * (n-1) * (n-2) / 6 - sol / 3;

}