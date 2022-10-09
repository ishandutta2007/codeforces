#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int lad[111];
int idx[11][11];
ld d[111];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			idx[i][j] = i % 2 == 0 ? j+10*i : 9-j+10*i;
		}
	}

	for (int i=0; i<10; i++) {
		for (int j=0; j<10; j++) {
			int x;
			cin >> x;
			if (x > 0) {
				lad[idx[i][j]] = idx[i-x][j];
			} else {
				lad[idx[i][j]] = idx[i][j];
			}
		}
	}

	d[0] = 0;
	fill(d+1, d+6, 6);
	for (int i=6; i<100; i++) {
		ld e = 1;
		for (int r=1; r<=6; r++) {
			int t1 = i-r;
			int t2 = lad[t1];
			e += min(d[t1], d[t2]) / 6;
		}
		d[i] = e;
	}
	cout << setprecision(20) << fixed << d[99] << '\n';
}