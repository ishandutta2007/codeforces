#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[2][3];
int b[8], x[8];
int lo[7], hi[7];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		for (int k=0; k<2; k++)
			for (int j=0; j<3; j++)
				cin >> a[k][j];
		for (int i=0; i<7; i++)
			cin >> b[i];

		int found = 0;
		for (x[0]=0; x[0]<=b[0] && !found; x[0]++) {
			for (int p=0; p<=b[1]+b[2]+b[4]; p++) {
				lo[4] = max({0, x[0] + p - a[0][0]});
				hi[4] = min({b[4], a[1][0] + x[0] + p -b[0]-b[1]-b[2]});

				lo[2] = max({0, x[0] + p - a[0][1]});
				hi[2] = min({b[2], a[1][1] + x[0] + p -b[0]-b[1]-b[4]});

				lo[1] = max({0, x[0] + p - a[0][2]});
				hi[1] = min({b[1], a[1][2] + x[0] + p -b[0]-b[4]-b[2]});

				if (lo[1] <= hi[1] && lo[2] <= hi[2] && lo[4] <= hi[4]) {
					if (lo[1] + lo[2] + lo[4] <= p && p <= hi[1] + hi[2] + hi[4]) {
						
						x[1] = lo[1];
						x[2] = lo[2];
						x[4] = lo[4];

						for (int i : {1, 2, 4}) {
							if (x[1] + x[2] + x[4] < p) {
								int d = p - x[1] - x[2] - x[4];
								d = min(d, hi[i] - lo[i]);
								x[i] += d;
							}
						}

						// cerr << "mozda " << x[0] << ' ' << x[1] << ' ' << x[2];
						// cerr << ' ' << x[4] << '\n';

						x[3] = min(b[3], a[0][0] + x[4] - x[0] - p);
						x[5] = min(b[5], a[0][1] + x[2] - x[0] - p);
						x[6] = min(b[6], a[0][2] + x[1] - x[0] - p);

						int moze = 1;
						if (x[3] - x[4] < b[0] + b[1] + b[2] + b[3] - a[1][0] - x[0] - p)
							moze = 0;
						if (x[5] - x[2] < b[0] + b[1] + b[4] + b[5] - a[1][1] - x[0] - p)
							moze = 0;
						if (x[6] - x[1] < b[0] + b[2] + b[4] + b[6] - a[1][2] - x[0] - p)
							moze = 0;

						if (min({x[3], x[5], x[6]}) < 0)
							moze = 0;

						if (!moze)
							continue;

						for (int i=0; i<7; i++)
							cout << x[i] << " \n"[i == 6];
						found = 1;
						break;
					}
				}
			}
		}

		if (!found)
			cout << "-1\n";
	}
}