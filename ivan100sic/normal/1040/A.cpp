#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, x, y, c, bad;
int a[22];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> x >> y;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1, j=n; i<=j; i++, j--) {
		if (i == j) {
			if (a[i] == 2)
				c += min(x, y);
		} else {
			if (a[i] == 2 && a[j] == 2)
				c += 2 * min(x, y);
			else if (a[i] == 2) {
				if (a[j] == 1)
					c += y;
				else
					c += x;
			} else if (a[j] == 2) {
				if (a[i] == 1)
					c += y;
				else
					c += x;
			} else if (a[i] != a[j]) {
				bad = 1;
			}
		}
	}

	if (bad)
		c = -1;

	cout << c;
}