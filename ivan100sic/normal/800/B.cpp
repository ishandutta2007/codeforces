#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
#include <cmath>
using namespace std;

struct pt {
	double x, y;
};

int n;
pt a[1005];

inline double det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y -
		a.y*b.x - b.y*c.x - c.y*a.x;
}

inline double kv(double x) {
	return x*x;
}

inline double dist(pt a, pt b) {
	return sqrt(kv(a.x-b.x) + kv(a.y-b.y));
}

inline double aps(double x) {
	return x < 0 ? -x : x;
}

inline double probaj3(pt a, pt b, pt c) {
	double p = aps(det(a, b, c));

	double d = dist(a, b);

	return p / d / 2;
}

inline int nx(int i) {
	return i == n-1 ? 0 : i+1;
}

inline int pr(int i) {
	return i == 0 ? n-1 : i-1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].x >> a[i].y;
	}

	double sol = 1e9;

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (nx(i) != j) {
				sol = min(sol, probaj3(a[i], a[j], a[nx(i)]));
			}
			if (pr(i) != j) {
				sol = min(sol, probaj3(a[i], a[j], a[pr(i)]));
			}
			if (nx(j) != i) {
				sol = min(sol, probaj3(a[i], a[j], a[nx(j)]));
			}
			if (pr(j) != i) {
				sol = min(sol, probaj3(a[i], a[j], a[pr(j)]));
			}
			sol = min(sol, dist(a[i], a[j]));
		}
	}

	cout.precision(20);
	cout << fixed << sol;

}