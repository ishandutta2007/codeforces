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

struct pt {
	int x, y;

	pt() {}
	pt(int x, int y) : x(x), y(y) {}

	void read() {
		scanf("%d%d", &x, &y);
	}

	pt operator+ (const pt &p) const {
		return pt(x + p.x, y + p.y);
	}

	pt operator- (const pt &p) const {
		return pt(x - p.x, y - p.y);
	}

	ll operator* (const pt &p) const {
		return 1LL * x * p.y - 1LL * y * p.x;
	}

	bool operator< (const pt &p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}

	bool operator== (const pt &p) const {
		return x == p.x && y == p.y;
	}
};

struct ptd {
	double x, y;

	ptd() {}
	ptd(double x, double y) : x(x), y(y) {}
	ptd(pt p) : x(p.x), y(p.y) {}

	ptd operator+ (const ptd &p) const {
		return ptd(x + p.x, y + p.y);
	}

	ptd operator- (const ptd &p) const {
		return ptd(x - p.x, y - p.y);
	}

	ptd operator* (const double d) const {
		return ptd(x * d, y * d);
	}
};

void convex_hull(vector<pt> &a) {
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
	int n = a.size();
	if (n == 1) return;
	pt p1 = a[0];
	pt p2 = a.back();

	vector<pt> up, down;
	for (int i = 0; i < n; i++) {
		if (i == 0 || i == n - 1 || ((a[i] - p1) * (p2 - p1)) > 0) {
			while (down.size() > 1 && ((a[i] - down.back()) * (down[(int)down.size() - 1] - down[(int)down.size() - 2])) >= 0) {
				down.pop_back();
			}
			down.push_back(a[i]);
		}
		if (i == 0 || i == n - 1 || ((a[i] - p1) * (p2 - p1)) < 0) {
			while (up.size() > 1 && ((a[i] - up.back()) * (up[(int)up.size() - 1] - up[(int)up.size() - 2])) <= 0) {
				up.pop_back();
			}
			up.push_back(a[i]);
		}
	}

	vector<pt> res;
	for (int i = 0; i < (int)down.size(); i++) res.push_back(down[i]);
	for (int i = (int)up.size() - 2; i > 0; i--) res.push_back(up[i]);
	a = res;
}

int n;
pt p0;

double f(ptd p) {
	return max(p0.x / p.x, p0.y / p.y);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	while (scanf("%d", &n) == 1) {
		p0.read();
		vector<pt> a(n);
		for (int i = 0; i < n; i++) a[i].read();
	/*{
		n = 1e5;
		vector<pt> a(n);
		for (int i = 0; i < n; i++) {
			a[i] = pt(i, rand() % n);
		}
		p0 = pt(5 * n, 5 * n);*/

		convex_hull(a);
		//cerr << a.size() << endl;

		double ans = 1e20;
		for (int i = 0; i < (int)a.size(); i++) {
			ptd p1 = a[i];
			ptd p2 = a[(i + 1) % a.size()];

			double f1 = f(p2 - (p2 - p1) * PHI);
			double f2 = f(p1 + (p2 - p1) * PHI);
			for (int it = 0; it < 200; it++) {
				if (f1 < f2) {
					f2 = f1;
					p2 = p1 + (p2 - p1) * PHI;
					f1 = f(p2 - (p2 - p1) * PHI);
				}
				else {
					f1 = f2;
					p1 = p2 - (p2 - p1) * PHI;
					f2 = f(p1 + (p2 - p1) * PHI);
				}
			}
			ans = min(ans, f1);
		}
		printf("%.15f\n", ans);
	}

	return 0;
}