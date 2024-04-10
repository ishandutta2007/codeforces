#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int x, y, z;
};

int n, k, m;
int a[1555], qs;
int cool[1555];
node stanje[1555];

int getd() {
	return (200*m + n) / (2*n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];

	for (int t=0; t<155555; t++) {
		for (int j=0; j<k; j++) {
			if (stanje[j].x == stanje[j].y) {
				if (stanje[j].x)
					m++;
				if (qs < n) {
					stanje[j] = {1, a[qs], qs};
					qs++;
				} else {
					stanje[j] = {0, 0, 0};
				}
			} else {
				stanje[j].x++;
			}
		}

		// if (m < n) {
		// 	for (int j=0; j<k; j++)
		// 		cerr << stanje[j].x << '/' << stanje[j].y << ' ';
		// 	cerr << '\n';
		// }

		// sad proveri
		int d = getd();
		for (int j=0; j<k; j++) {
			if (d == stanje[j].x && stanje[j].x) {
				// cerr << "cool! " << t << ' ' << d << ' ' << stanje[j].z << '\n';
				cool[stanje[j].z] = 1;
			}
		}
	}

	cout << accumulate(cool, cool+n, 0) << '\n';
}