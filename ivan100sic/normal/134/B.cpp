#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int gcd_counter(int x, int y) {
	int c = 0;
	while (x != y) {
		if (x > y) {
			int r = x % y;
			if (r == 0) {
				c += x/y - 1;
				x = y;
			} else {
				c += x/y;
				x = r;
			}
		} else {
			swap(x, y);
		}
	}
	return x == 1 ? c : 123123123;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	int z = n + 5;

	for (int x=1; x<=n; x++) {
		z = min(z, gcd_counter(n, x));
	}

	cout << z << '\n';
}