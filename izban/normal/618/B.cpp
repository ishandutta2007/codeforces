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
const double PHI = (sqrt(5.0) - 1) / 2.0;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		vector<vector<int> > a(n, vector<int>(n));
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

		vector<int> p(n, -1);
		for (int it = 1; it <= n; it++) {
			for (int i = 0; i < n; i++) {
				bool ok = 1;
				for (int j = 0; j < n; j++) if (i != j) ok &= (p[j] != -1 || p[j] == -1 && a[i][j] == it);
				if (ok) {
					p[i] = it;
					break;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << p[i] << " \n"[i + 1 == n];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) if (i != j) {
				assert(a[i][j] == min(p[i], p[j]));
			}
		}
	}

	return 0;
}