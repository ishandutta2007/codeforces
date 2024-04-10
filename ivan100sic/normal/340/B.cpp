#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	int x, y;
};

int det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y
		- a.y*b.x - b.y*c.x - c.y*a.x;
}

int n;
pt a[305];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].y;

	int sol = 0;

	for (int i=0; i<n; i++)
		for (int j=i+1; j<n; j++) {

			int lo = 123123123, hi = -123123123;

			for (int k=0; k<n; k++) {
				if (k == i || k == j)
					continue;
				int d = det(a[i], a[j], a[k]);
				lo = min(lo, d);
				hi = max(hi, d);
			}

			sol = max(sol, hi - lo);
		}
	
	cout.precision(20);
	cout << fixed;

	cout << sol * 0.5 << '\n';
}