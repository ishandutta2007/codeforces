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
const double eps = 1e-9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int a, b;
	while (cin >> a >> b) {
		if (b > a) {
			cout << -1 << endl;
			continue;
		}

		int x = b;

		if (a % (2 * x) == x) {
			cout << x << endl;
			continue;
		}

		int peaks = (a - x) / (2 * x) + 1;

		double res = x + ((a - x) % (2 * x)) / (2.0 * peaks);
		printf("%.10f\n", res);
	}

	return 0;
}