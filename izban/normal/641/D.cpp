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
typedef long double dbl;

using namespace std;

const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const dbl EPS = 1e-11;

dbl sqr(dbl x) {
	return x * x;
}

bool ok(dbl x) {
	return x >= -EPS && x <= 1 + EPS;
}

void norm(dbl &x) {
	if (x < 0) x = 0;
	if (x > 1) x = 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		vector<dbl> mn(n), mx(n);
		for (int i = 0; i < n; i++) {
			double o;
			scanf("%lf", &o);
			mx[i] = o;
		}
		for (int i = 0; i < n; i++) {
			double o;
			scanf("%lf", &o);
			mn[i] = o;
		}

		vector<double> a(n), b(n);

		dbl sa = 0.0, sb = 0.0;
		for (int i = 0; i < n; i++) {
			dbl g = mn[i] + mx[i];
			dbl A = -1;
			dbl B = (sb + g - sa);
			dbl C = g * sa - mx[i];
			dbl D = B * B - 4 * A * C;
			assert(D >= -EPS);
			D = fabs(D);
			dbl na = (-B - sqrt(D)) / (2 * A);
			dbl nb = g - na;

			assert(ok(na));
			assert(ok(nb));
			a[i] = na;
			b[i] = nb;
			sa += na;
			sb += nb;
		}

		for (int i = 0; i < n; i++) printf("%.15f%c", a[i], " \n"[i + 1 == n]);
		for (int i = 0; i < n; i++) printf("%.15f%c", b[i], " \n"[i + 1 == n]);
	}

	return 0;
}