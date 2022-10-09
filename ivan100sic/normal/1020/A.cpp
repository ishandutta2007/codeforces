#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, h, a, b, k;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> h >> a >> b >> k;
	while (k--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int sol = abs(x1 - x2);

		if (x1 == x2) {
			sol += abs(y1-y2);
		} else {
			if (y1 > b && y2 > b)
				sol += y1+y2-b-b;
			else if (y1 < a && y2 < a)
				sol += a+a-y1-y2;
			else
				sol += abs(y1-y2);
		}

		cout << sol << '\n';
	}
}