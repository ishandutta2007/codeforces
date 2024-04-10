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

const double eps = 1e-9;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	ll a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		double ans = 1e20;
		for (int k11 = -1; k11 <= 1; k11 += 2) {
			for (int k12 = -1; k12 <= 1; k12 += 2) {
				for (int k21 = -1; k21 <= 1; k21 += 2) {
					for (int k22 = -1; k22 <= 1; k22 += 2) {
						if (k11 + k22 - k21 - k12 == 0 && a + d - b - c == 0) continue;
						
						double A = k11 * k22 - k21 * k12;
						double B = a * k22 + d * k11 - b * k21 - c * k12;
						double C = a * d - b * c;
						if (k11 * k22 - k21 * k12 == 0) {
							ans = min(ans, abs(-C / B));
							continue;
						}

						double d = sqrt(B * B - 4 * A * C);
						double x1 = (-B - d) / (2 * A);
						double x2 = (-B + d) / (2 * A);
						
						if (ans > abs(x1)) ans = abs(x1);
						if (ans > abs(x2)) ans = abs(x2);
					}
				}
			}
		}
		printf("%.15lf\n", ans);
	}

	return 0;
}