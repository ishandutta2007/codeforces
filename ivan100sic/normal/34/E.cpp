// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct ball {
	ld x, v, m;
	int idx;
};

int n;
ball a[10];
ld t, sol[10];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> t;
	for (int i=0; i<n; i++) {
		int x, v, m;
		cin >> x >> v >> m;
		a[i] = {ld(x), ld(v), ld(m), i};
	}

	sort(a, a+n, [](auto x, auto y) { return x.x < y.x; });

	int steps = 10000;
	while (steps-- > 0 && abs(t) > 1e-9) {
		int ii = -1, jj = -1;
		ld tcmin = t;
		for (int i=0; i<n-1; i++) {
			int j = i+1;
			if (a[i].v <= a[j].v) continue;

			ld tcol = (a[j].x - a[i].x) / (a[i].v - a[j].v);

			if (tcol < tcmin) {
				ii = i;
				jj = j;
				tcmin = tcol;
			}
		}

		if (ii == -1) {
			break;
		}

		// advansuj sve za tcmin
		for (int i=0; i<n; i++) {
			a[i].x += a[i].v * tcmin;
		}

		t -= tcmin;

		// odbij

		{
			int i = ii, j = jj;
			ld v1p = ((a[i].m - a[j].m)*a[i].v + 2*a[j].m*a[j].v) / (a[i].m + a[j].m);
			ld v2p = ((a[j].m - a[i].m)*a[j].v + 2*a[i].m*a[i].v) / (a[i].m + a[j].m);

			a[i].v = v1p;
			a[j].v = v2p;
		}
	}

	cout << setprecision(20) << fixed;
	for (int i=0; i<n; i++) {
		sol[a[i].idx] = a[i].x + a[i].v * t;
	}

	for (int i=0; i<n; i++) {
		cout << sol[i] << '\n';
	}
}