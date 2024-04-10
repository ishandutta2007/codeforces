#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int q, n, h;
int a[205][205];

bool moze(int x, int y, int w) {
	int z = 0;
	if (y + w - 1 > n)
		return false;
	for (int i=y; i<y+w; i++)
		z += a[x][i];
	return z == 0;
}

int dobrota(int x, int y, int w) {
	int z = 0;
	for (int i=y; i<y+w; i++) {
		z += abs(x - h) + abs(i - h);
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> q >> n;
	h = (n+1) / 2;
	while (q--) {
		int w;
		cin >> w;
		int x = -1, y = -1;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=n; j++) {
				if (moze(i, j, w)) {
					if (x == -1) {
						x = i;
						y = j;
					} else {
						if (dobrota(i, j, w) < dobrota(x, y, w)) {
							x = i;
							y = j;
						}
					}
				}
			}
		}
		if (x == -1) {
			cout << "-1\n";
		} else {
			cout << x << ' ' << y << ' ' << y+w-1 << '\n';
			for (int i=y; i<y+w; i++)
				a[x][i] = 1;
		}
	}
}