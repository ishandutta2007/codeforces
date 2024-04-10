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

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;
const double EPS = 1e-9;

struct pt {
	double x, y;

	pt() {}
	pt(double x, double y) : x(x), y(y) {}

	pt operator+ (const pt &p) const {
		return pt(x + p.x, y + p.y);
	}

	pt operator- (const pt &p) const {
		return pt(x - p.x, y - p.y);
	}

	pt operator* (const double d) const {
		return pt(x * d, y * d);
	}

	double d() const {
		return sqrt(x * x + y * y);
	}

	pt norm() const {
		return (*this) * (1.0 / d());
	}
};

int sign(double x) {
	if (fabs(x) < EPS) return 0;
	if (x > 0) return 1;
	return -1;
}

double sqr(double x) {
	return x * x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		vector<pt> a(n);
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d%d", &x, &y);
			a[i] = pt(x, y);
		}
		double all = 0;
		for (int i = 0; i < n; i++) {
			all += fabs(a[i].x - a[(i + 1) % n].x) + fabs(a[i].y - a[(i + 1) % n].y);
		}
		for (int i = 0; i < n; i++) a.push_back(a[i]);

		double av = all / m;

		vector<pt> b(m);
		vector<int> id(m);
		b[0] = a[0];
		int cur = 1;
		double len = 0;
		int ci = 1;
		pt pp = a[0];
		while (cur < m) {
			double nlen = len + (a[ci] - pp).d();
			if (nlen >= av) {
				pt np = pp + (a[ci] - pp).norm() * (av - len);
				b[cur] = np;
				id[cur] = ci;
				cur++;
				pp = np;
				len = 0;
				continue;
			}
			else {
				len = nlen;
				pp = a[ci];
				ci = (ci + 1) % n;
				continue;
			}
		}
		assert(cur == m);

		double l = 0, r = 4e3;
		for (int it = 0; it < 50; it++) {
			double z = (l + r) / 2;

			vector<pair<double, int> > vct;
			bool ok = 0;
			for (int i = 0; i < m; i++) {
				double ct = 0;
				pt p1 = b[i];
				int i1 = id[i];
				pt p2 = b[(i + 1) % m];
				int i2 = id[(i + 1) % m];
				while (ct < av) {
					double dt = all;
					dt = min(dt, av - ct);
					dt = min(dt, (a[i1] - p1).d());
					dt = min(dt, (a[i2] - p2).d());

					if (fabs(dt) < EPS) {
						if (fabs(ct - av) < EPS) break;
						if ((a[i1] - p1).d() < EPS) {
							p1 = a[i1];
							i1 = (i1 + 1) % n;
						}
						if ((a[i2] - p2).d() < EPS) {
							p2 = a[i2];
							i2 = (i2 + 1) % n;
						}
						continue;
					}

					double x1 = p1.x;
					double dx1 = sign(a[i1].x - x1);
					double y1 = p1.y;
					double dy1 = sign(a[i1].y - y1);

					double x2 = p2.x;
					double dx2 = sign(a[i2].x - x2);
					double y2 = p2.y;
					double dy2 = sign(a[i2].y - y2);

					double A = sqr(dx2 - dx1) + sqr(dy2 - dy1);
					double B = 2 * ((x2 - x1) * (dx2 - dx1) + (y2 - y1) * (dy2 - dy1));
					double C = sqr(x2 - x1) + sqr(y2 - y1);

					// sqrt(Att+Bt+C) <= z

					double L = ct, R = ct + dt;
					double nL = 0, nR = dt;
					if (sign(A) != 0) {
						C = C - z * z;
						double D = B * B - 4 * A * C;
						if (D < 0) {
							nL = nR + 1;
						}
						else {
							double t1 = (-B - sqrt(D)) / (2 * A);
							double t2 = (-B + sqrt(D)) / (2 * A);
							nL = t1;
							nR = t2;
						}
					}
					else {
						if (sign(B) != 0) {
							if (sign(B) > 0) {
								// Bx + C <= z*z
								nL = -C / B;
								nR = (z * z - C) / B;
							}
							else {
								// Bx + C <= z * z
								// (-B)x - C >= -z * z
								nL = C / -B;
								nR = (C - z * z) / (-B);
							}
						}
						else {
							if (C >= 0 && sqrt(C) <= z) {
								// OK
							}
							else {
								// FAIL
								nL = nR + 1;
							}
						}
					}
					L = max(L, nL + ct);
					R = min(R, nR + ct);
					if (L < R) {
						vct.push_back(make_pair(L, 1));
						vct.push_back(make_pair(R, -1));
					}

					ct += dt;
					p1 = p1 + pt(dx1, dy1) * dt;
					p2 = p2 + pt(dx2, dy2) * dt;
				}
			}
			sort(vct.begin(), vct.end());
			int cur = 0;
			for (int i = 0; i < (int)vct.size(); i++) {
				cur += vct[i].second;
				if (cur == m) {
					ok = 1;
				}
			}

			if (ok) r = z;
			else l = z;
		}
		printf("%.15f\n", r);
	}

	return 0;
}