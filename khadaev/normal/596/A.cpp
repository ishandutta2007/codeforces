#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
int main() {
	int n;
	cin >> n;
	int xmin = 2000, xmax = -2000, ymin = 2000, ymax = -2000, x, y;
	for (int i = 0; i < n; ++i) {
		cin >> x >> y;
		xmin = min(xmin, x);
		xmax = max(xmax, x);
		ymin = min(ymin, y);
		ymax = max(ymax, y);
	}
	if (xmin == xmax || ymin == ymax) cout << "-1\n";
	else cout << (xmax - xmin) * (ymax - ymin) << '\n';
}