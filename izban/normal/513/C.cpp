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

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std; 

const int maxn = -1;
const int inf = 1e9;

int f(int mask) {
	int res = 0;
	while (mask) {
		res += mask % 2;
		mask /= 2;
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		vector<int> l(n), r(n);
		for (int i = 0; i < n; i++) {
			cin >> l[i] >> r[i];
		}

		double res = 0;
		for (int ans = 1; ans <= 10000; ans++) {
			for (int mask = 1; mask < 1 << n; mask++) {
				double pr = 1;
				for (int i = 0; i < n; i++) {
					if (mask & (1 << i)) {
						if (ans < l[i] || ans > r[i]) pr = 0;
						pr = pr * 1.0 / (r[i] - l[i] + 1);
					}
				}
				{
					for (int j = 0; j < n; j++) if (!(mask & (1 << j))) {
						double cpr = pr;
						if (r[j] <= ans) cpr = 0;
						if (l[j] <= ans) {
							cpr = cpr * (r[j] - ans) / (r[j] - l[j] + 1);
						}
						for (int k = 0; k < n; k++) if (k != j && !(mask & (1 << k))) {
							if (r[k] < ans) continue;
							if (l[k] >= ans) cpr = 0;
							cpr = cpr * (ans - l[k]) / (r[k] - l[k] + 1);
						}
						res += ans * cpr;
					}
				} 
				if (f(mask) > 1) {
					double cpr = pr;
					for (int k = 0; k < n; k++) if (!(mask & (1 << k))) {
						if (r[k] < ans) continue;
						if (l[k] >= ans) cpr = 0;
						cpr = cpr * (ans - l[k]) / (r[k] - l[k] + 1);
					}
					res += ans * cpr;
				}
			}
		}
		printf("%.10lf\n", res);
	}

	return 0;
}