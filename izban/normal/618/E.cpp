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

const int MAXN = 1 << 19;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;
const double PHI = (sqrt(5.0) - 1) / 2.0;
const double PI = acos(-1.0);

const int K = 3;

struct matrix {
	double a[K][K];

	matrix() {}

	matrix operator* (const matrix &m) const {
		matrix res;
		for (int i = 0; i < K; i++) {
			for (int j = 0; j < K; j++) {
				res.a[i][j] = 0;
				for (int k = 0; k < K; k++) {
					res.a[i][j] += a[i][k] * m.a[k][j];
				}
			}
		}
		return res;
	}
};

matrix e() {
	matrix res;
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			res.a[i][j] = i == j ? 1.0 : 0.0;
		}
	}
	return res;
}
const matrix E = e();


int n, m;
matrix t[2 * MAXN];

void build(int v, int tl, int tr) {
	t[v] = E;
	if (tl == tr) return;
	int tm = (tl + tr) >> 1;
	build(v * 2, tl, tm);
	build(v * 2 + 1, tm + 1, tr);
}

void push(int v, int tl, int tr) {
	if (tl != tr) {
		t[v * 2] = t[v * 2] * t[v];
		t[v * 2 + 1] = t[v * 2 + 1] * t[v];
		t[v] = E;
	}
}

vector<double> get(int v, int tl, int tr, int x) {
	push(v, tl, tr);
	if (tl == tr) {
		vector<double> res(K), a(K);
		a[0] = tl;
		a[1] = 0.0;
		a[2] = 1.0;
		for (int i = 0; i < K; i++) {
			res[i] = 0;
			for (int j = 0; j < K; j++) {
				res[i] += a[j] * t[v].a[j][i];
			}
		}
		return res;
	}
	int tm = (tl + tr) >> 1;
	if (x <= tm) return get(v * 2, tl, tm, x);
	else return get(v * 2 + 1, tm + 1, tr, x);
}

void upd(int v, int tl, int tr, int l, int r, const matrix &u) {
	push(v, tl, tr);
	if (l > r) return;
	if (l == tl && r == tr) {
		t[v] = t[v] * u;
		push(v, tl, tr);
		return;
	}
	int tm = (tl + tr) >> 1;
	upd(v * 2, tl, tm, l, min(r, tm), u);
	upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, u);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d%d", &n, &m) == 2) {
		vector<int> x(m), y(m), z(m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &x[i], &y[i], &z[i]);
		}

		build(1, 0, n);
		for (int i = 0; i < m; i++) {
			matrix u;
			if (x[i] == 1) {
				vector<double> p1 = get(1, 0, n, y[i] - 1);
				vector<double> p2 = get(1, 0, n, y[i]);
				double dx = p2[0] - p1[0];
				double dy = p2[1] - p1[1];
				double d = sqrt(dx * dx + dy * dy);
				dx = dx / d * z[i];
				dy = dy / d * z[i];

				u.a[0][0] = 1.0; u.a[0][1] = 0.0; u.a[0][2] = 0.0;
				u.a[1][0] = 0.0; u.a[1][1] = 1.0; u.a[1][2] = 0.0;
				u.a[2][0] = dx;  u.a[2][1] = dy;  u.a[2][2] = 1.0;
			}
			if (x[i] == 2) {
				vector<double> p = get(1, 0, n, y[i] - 1);
				double x0 = p[0], y0 = p[1];

				u.a[0][2] = 0.0;
				u.a[1][2] = 0.0;
				u.a[2][2] = 1.0;
				double alpha = -z[i] / 180.0 * PI;
				u.a[0][0] = cos(alpha);
				u.a[1][0] = -sin(alpha);
				u.a[0][1] = sin(alpha);
				u.a[1][1] = cos(alpha);

				u.a[2][0] = x0 - x0 * cos(alpha) + y0 * sin(alpha);
				u.a[2][1] = y0 - x0 * sin(alpha) - y0 * cos(alpha);
			}
			upd(1, 0, n, y[i], n, u);
			vector<double> p = get(1, 0, n, n);
			printf("%.15f %.15f\n", p[0], p[1]);
		}
	}

	return 0;
}