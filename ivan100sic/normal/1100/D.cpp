#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 666, W = 999, C = 500;

int u, v;
int x[N+1], y[N+1];

bool zauzeto(int p, int q) {
	for (int i=1; i<=N; i++)
		if (x[i] == p && y[i] == q)
			return true;
	return false;
}

bool cekirano(int p, int q) {
	for (int i=1; i<=N; i++)
		if (x[i] == p || y[i] == q)
			return true;
	return false;
}

void mvto(int u1, int v1) {
	// proveri da nema nekog tu
	if (zauzeto(u1, v1)) {
		// odlicno sad cu da se cekiram!
		for (int dx=-1; dx<=1; dx++) {
			for (int dy=-1; dy<=1; dy++) {
				int u2 = u + dx;
				int v2 = v + dy;
				if (!zauzeto(u2, v2) && cekirano(u2, v2)) {
					cout << u2 << ' ' << v2 << '\n' << flush;
					exit(0);
				}
			}
		}
	} // ako udje u if nece da izadje odatle!

	u = u1;
	v = v1;

	cout << u << ' ' << v << '\n' << flush;
	if (cekirano(u, v))
		exit(0);
	else {
		int k, p, q;
		cin >> k >> p >> q;
		if (k == -1 && p == -1 && q == -1) {
			// cekirani smo
			exit(0);
		}
		x[k] = p;
		y[k] = q;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> u >> v;
	for (int i=1; i<=N; i++)
		cin >> x[i] >> y[i];

	while (u > C) mvto(u-1, v);
	while (u < C) mvto(u+1, v);
	while (v > C) mvto(u, v-1);
	while (v < C) mvto(u, v+1);

	int region[4] = {0, 0, 0, 0};
	for (int i=1; i<=N; i++) {
		int mask = 0;
		if (x[i] > C)
			mask += 1;
		if (y[i] > C)
			mask += 2;
		region[mask]++;
	}

	int r = min_element(region, region+4) - region;
	int dx=0, dy=0;
	dx = basic_string<int>({+1, -1, +1, -1})[r];
	dy = basic_string<int>({+1, +1, -1, -1})[r];

	while (1)
		mvto(u+dx, v+dy);
}