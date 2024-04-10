#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<vector<double> > a(n, vector<double>(n));
		vector<vector<int> > b(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf("%d", &x);
				a[i][j] = x / 100.0;
				b[i][j] = x;
			}
		}

		vector<double> d(n);
		vector<double> cd(n);
		vector<double> curP(n);
		for (int i = 0; i < n - 1; i++) {
			if (b[i][n - 1] != 0) {
				// d[i] = 1.0 * a[i][n - 1] + (d[i] + 1) * (1 - a[i][n - 1])
				// a[i][n - 1] * d[i] = a[i][n - 1] + 1 - a[i][n - 1]
				// d[i] = 1 / a[i][n - 1]
				d[i] = 1.0 / a[i][n - 1];
				cd[i] = a[i][n - 1];
				curP[i] = 1 - a[i][n - 1];
			}
			else {
				d[i] = 1e20;
				cd[i] = 0;
				curP[i] = 1.0;
			}
		}
		vector<char> used(n, 0);
		for (int it = 0; it < n - 1; it++) {
			int mn = -1;
			double best = 1e20;
			for (int i = 0; i < n - 1; i++) {
				if (d[i] > 1e19) continue;
				double nd = d[i];
				if (!used[i] && (mn == -1 || nd < best)) {
					mn = i;
					best = nd;
				}
			}
			used[mn] = 1;
			if (d[mn] > 1e19) continue;
			// d = p * (d + 1) + curd
			// d = (p + curd) / (1 - p)
			for (int i = 0; i < n - 1; i++) {
				if (!used[i]) {
					if (b[i][mn] != 0) {
						// d[i] = a[i][mn] * (d[mn] + 1) + (1 - a[i][mn]) * (d[i] + 1)
						// a[i][mn] * d[i] = a[i][mn] * (d[mn] + 1) + 1 - a[i][mn]
						// d[i] = (a[i][mn] * (d[mn] + 1) + 1 - a[i][mn]) / a[i][mn]
						double curAns = cd[i] + curP[i] * a[i][mn] * (d[mn] + 1);
						double p = curP[i] * (1 - a[i][mn]);
						curAns = (p + curAns) / (1 - p);
						if (curAns < d[i]) {
							d[i] = curAns;
							cd[i] += curP[i] * a[i][mn] * (d[mn] + 1);
							curP[i] *= 1 - a[i][mn];
							if (curP[i] < 1e-20) curP[i] = 0;
						}
					}
				}
			}
		}
		printf("%.15f\n", d[0]);
	}

	return 0;
}