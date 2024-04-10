#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[500005], n, c;

/*
. . . c . 3 . c . 3 3 . c c c c
c -> -1
3 -> +1
*/

int d[500005], z[500005], p[500005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> c;
	int sol = 0;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z[i] = z[i-1];
		if (a[i] == c) {
			z[i]++;
			sol++;
		}
	}

	int extra = 0;

	for (int i=1; i<=n; i++) {
		int x = a[i];
		if (x == c)
			continue;

		if (p[x] == 0) {
			d[x] += 1 - z[i];
			if (d[x] < 1)
				d[x] = 1;
			extra = max(extra, d[x]);
		} else {
			d[x] += 1 - (z[i] - z[p[x]]);
			if (d[x] < 1)
				d[x] = 1;
			extra = max(extra, d[x]);
		}
		p[x] = i;
	}

	cout << sol + extra << '\n';
}