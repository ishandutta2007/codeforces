#include <iostream>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <time.h>

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<llong, llong> pll;

const ld eps = 1e-10;
int n, r;
int x[1000];
ld y[1000];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> r;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		y[i] = r;
		for (int j = 0; j < i; ++j) {
			if (abs(x[i] - x[j]) > 2 * r) continue;
			ld tmp = sqrtl(powl(2 * r, 2) - powl(x[i] - x[j], 2));
			y[i] = max(y[j] + tmp, y[i]);
		}
		printf("%.12Lf ", y[i]);
	}

	return 0;
}