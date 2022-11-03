



#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, r;
	cin >> n >> r;
	vector<long double> x(n);
	for (int i = 0; i < n; i++)
		cin >> x[i];
	vector<long double> res(n);
	for (int i = 0; i < n; i++) {
		long double y = r;
		for (int j = 0; j < i; j++) {
			if (abs(x[i] - x[j]) <= 2 * r) {
				long double val = sqrt(4 * r * r - (x[j] - x[i]) * (x[j] - x[i])) + res[j];

				y = max(y, val);
			}
		}
		res[i] = y;
		cout << fixed << setprecision(9) << y << ' ';
	}

	return 0;
}