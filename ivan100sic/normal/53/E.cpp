// Retired?
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, k;
uint8_t a[10][10];
uint8_t g[10];

int sol;
uint8_t dg[10];

void chk(int mask) {
	if (n - __builtin_popcount(mask) != k) return;
	fill(dg, dg+n, 1);
	for (int i=0; i<n-2; i++) {
		dg[g[i]]++;
	}

	int dg1 = 0;

	for (int i=0; i<n; i++) {
		if (dg[i] == 1) {
			dg1 |= 1 << i;
		}
	}

	for (int i=0; i<n-2; i++) {
		int x = g[i];

		int j = __builtin_ctz(dg1);

		if (!a[x][j]) {
			return;
		}
		dg[j]--;
		dg1 -= 1 << j;

		if (dg[x]-- == 0) dg1 -= 1 << x;
		dg1 += (dg[x] == 1) << x;
	}

	int x=-1;
	for (int i=0; i<n; i++) {
		if (dg[i] == 1) {
			if (x == -1) {
				x = i;
			} else {
				if (!a[x][i]) {
					return;
				}
			}
		}
	}

	sol++;
}

void rek(int l, int mask) {
	if (l == n-2) {
		chk(mask);
		return;
	}

	for (int i=0; i<n; i++) {
		g[l] = i;
		rek(l+1, mask | (1 << i));
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> k;
	while (m--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		a[x][y] = a[y][x] = 1;
	}

	rek(0, 0);
	cout << sol << '\n';
}