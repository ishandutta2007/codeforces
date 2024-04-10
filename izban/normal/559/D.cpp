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

const dbl eps = 1e-9;
const int MAXN = 1 << 17;

dbl pw[MAXN], ppw[MAXN];
int n;
pair<int, int> a[MAXN];

int nxt(int x) {
	return (x + 1) % n;
}

int prv(int x) {
	return (x - 1 + n) % n;
}

ll gcd(ll a, ll b) {
	a = abs(a);
	b = abs(b);
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	pw[0] = ppw[0] = 1;
	for (int i = 1; i < MAXN; i++) pw[i] = pw[i - 1] * 0.5, ppw[i] = ppw[i - 1] * 2;

	while (scanf("%d", &n) == 1) {
	//n = 1e5; {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &a[i].first, &a[i].second);
			//a[i] = make_pair(i, i);
		}

		dbl s = 0.0;
		dbl bord = 0.0;
		
		for (int i = 0; i < n; i++) {
			int k = 0;
			dbl cs = 0.0;
			for (int j = nxt(i); nxt(j) != i; j = nxt(j), k++) {
				if (k > 100) break;

				cs += (a[j].first - a[prv(j)].first) * 0.5 * (a[j].second + a[prv(j)].second);
				dbl ns = cs + (a[i].first - a[j].first) * 0.5 * (a[i].second + a[j].second);

				dbl prob;
				if (n <= 100) {
					prob = (ppw[n - k - 2] - 1) / (ppw[n] - 1 - n - n / 2.0 * (n - 1));
				} else {
					prob = pw[k + 2];
				}
				if (k) {
					s += fabs(ns) * prob;
				}
				bord += (gcd(a[j].first - a[i].first, a[j].second - a[i].second)) * prob;
			}
		}
		
		dbl all = 0.0;
		for (int i = 0; i < n; i++) {
			all += (a[nxt(i)].first - a[i].first) * 0.5 * (a[nxt(i)].second + a[i].second);
		}
		all = fabs(all);

		s = all - s;

		double ans = s + 1 - bord / 2.0;
		printf("%.15f\n", ans);
	}

	return 0;
}