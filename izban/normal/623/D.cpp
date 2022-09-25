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
const double EPS = 1e-10;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	cout.precision(15);
	cout << fixed;

	int n;
	while (cin >> n) {
		double start = clock() / (double)CLOCKS_PER_SEC;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<double> b(n);
		for (int i = 0; i < n; i++) b[i] = (100 - a[i]) / 100.0;
		/*if (n == 1) {
			cout << 1.0 << endl;
			continue;
		}*/
		vector<double> p(n, 1.0);
		int turns = 0;
		double sum = 0;
		while (1) {
			double win = 1.0;
			for (int i = 0; i < n; i++) win *= 1 - p[i];
			sum += 1 - win;
			if (turns % 100 == 0) {
				if (clock() / (double)CLOCKS_PER_SEC - start > 1.5) {
					cout << sum << endl;
					break;
				}
			}
			int id = 0;
			for (int i = 1; i < n; i++) {
				//if (p[i] > p[id]) {
				if ((1 - p[i] * b[i]) * (1 - p[id]) >(1 - p[id] * b[id]) * (1 - p[i])) {
					id = i;
				}
			}
			p[id] *= b[id];
			if (p[id] < 1e-30) p[id] = 0;
			turns++;
		}
	}

	return 0;
}