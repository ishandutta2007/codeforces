#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105];
int prost[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
int d[105][1 << 16];
int p[105][1 << 16];
int msk[66];
int sol[105];

int calc_mask(int x) {
	int y = 0;
	for (int i=0; i<16; i++)
		if (x % prost[i] == 0)
			y += 1 << i;
	return y;
}

void precalc() {
	for (int i=1; i<=66; i++)
		msk[i] = calc_mask(i);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	precalc();

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	memset(d, 63, sizeof(d));
	d[0][0] = 0;
	
	for (int i=1; i<=n; i++) {
		for (int y=0; y<65536; y++) {
			for (int x=1; x<59; x++) {
				if ((msk[x] & y) == 0) {
					int z = msk[x] | y;
					int kand = d[i-1][y] + abs(a[i] - x);
					if (d[i][z] > kand) {
						d[i][z] = kand;
						p[i][z] = x;
					}
				}
			}
		}
	}


	int g = min_element(d[n], d[n]+65536) - d[n];
	cerr << d[n][g] << '\n';

	int j = 0;
	for (int i=n; i>=1; i--) {
		j = p[i][g];
		sol[i] = j;
		g -= msk[j];
	}
	for (int i=1; i<=n; i++)
		cout << sol[i] << ' ';
	cout << '\n';
}