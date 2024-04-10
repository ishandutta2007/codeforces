#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct figura {
	int x, y, p, m;
};

bool cmp_x(const figura& a, const figura& b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmp_y(const figura& a, const figura& b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

bool cmp_p(const figura& a, const figura& b) {
	return a.p < b.p || (a.p == b.p && a.m < b.m);
}

bool cmp_m(const figura& a, const figura& b) {
	return a.m < b.m || (a.m == b.m && a.p < b.p);
}

int n;
figura a[500005];
string tip[500005];
figura ox[500005], oy[500005], op[500005], om[500005];
int kx, ky;

template<class T>
void check(figura low, figura hi, T cmp, figura* ar) {
	if (cmp(hi, low)) {
		swap(low, hi);
	}
	auto it1 = upper_bound(ar, ar+n, low, cmp);
	auto it2 = lower_bound(ar, ar+n, hi, cmp);

	if (it1 != it2) {
		return;
	}
	cout << "YES";
	exit(0);
}

int main() {
	cin >> n >> kx >> ky;
	figura kralj;
	kralj.x = kx;
	kralj.y = ky;
	kralj.p = kx + ky;
	kralj.m = kx - ky;
	for (int i=0; i<n; i++) {
		cin >> tip[i] >> a[i].x >> a[i].y;
		a[i].p = a[i].x + a[i].y;
		a[i].m = a[i].x - a[i].y;
		ox[i] = oy[i] = op[i] = om[i] = a[i];
	}
	sort(ox, ox+n, cmp_x);
	sort(oy, oy+n, cmp_y);
	sort(op, op+n, cmp_p);
	sort(om, om+n, cmp_m);
	for (int i=0; i<n; i++) {
		if (tip[i] == "R" || tip[i] == "Q") {
			if (a[i].x == kx) {
				check(kralj, a[i], cmp_x, ox);
			}
			if (a[i].y == ky) {
				check(kralj, a[i], cmp_y, oy);
			}
		}
		if (tip[i] == "B" || tip[i] == "Q") {
			if (a[i].p == kx+ky) {
				check(kralj, a[i], cmp_p, op);
			}
			if (a[i].m == kx-ky) {
				check(kralj, a[i], cmp_m, om);
			}
		}
	}
	cout << "NO";
}