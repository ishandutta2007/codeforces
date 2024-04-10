#include <iostream>
#include <complex>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef complex<double> point;

int n, m;

bool cmp(point p1, point p2) {
	return make_pair(real(p1), imag(p1)) < make_pair(real(p2), imag(p2));
}

double cross(point p1, point p2) {
	return imag(conj(p1) * p2);
}

double dot(point p1, point p2) {
	return real(conj(p1) * p2);
}

vector<point> buildHalfHull(const vector<point>& pnts) {
	vector<point> hull;
	hull.push_back(pnts[0]);
	for (int i = 1; i < (int)pnts.size(); ++i) {
		while (hull.size() > 1 && cross(hull.back() - hull[hull.size() - 2], pnts[i] - hull.back()) >= 0) {
			hull.pop_back();
		}
		hull.push_back(pnts[i]);
	}
	return hull;
}

double calc(vector<point> &r, vector<point> &b) {
	sort(r.begin(), r.end(), cmp);
	sort(b.begin(), b.end(), cmp);
	double res = 1e12;
	for (int c = 0; c < 2; ++c) {
		vector<point> r_hull = buildHalfHull(r);
		vector<point> b_hull = buildHalfHull(b);
		size_t optr = 0;
		for (size_t i = 1; i < b_hull.size(); ++i) {
			point nn = (b_hull[i] - b_hull[i-1]) * point(0, 1);
			if (abs(nn) < 1e-9) {
				continue;
			}
			nn /= abs(nn);
			double cand = max(0.0, dot(nn, b_hull[i]));
			double x = dot(nn, r_hull[optr]);
			while (optr + 1< r_hull.size()) {
				double y = dot(nn, r_hull[optr + 1]);
				if (y > x - 1e-8) {
					optr++;
					x = y;
				} else break;
			}
			if (x > cand - 1e-8)
				res = min(res, cand);
		}
		reverse(r.begin(), r.end());
		reverse(b.begin(), b.end());
	}
	return res;
}


double calc2(vector<point> &pnts) {
	if (m < 2) return 0;
	sort(pnts.begin(), pnts.end(), cmp);
	double res = 1e12;
	for (int c = 0; c < 2; ++c) {
		vector<point> hull;
		hull.push_back(pnts[0]);
		for (int i = 1; i < m; ++i) {
			while (hull.size() > 1 && cross(hull.back() - hull[hull.size() - 2], pnts[i] - hull.back()) >= 0) {
				hull.pop_back();
			}
			hull.push_back(pnts[i]);
		}
		for (size_t i = 1; i < hull.size(); ++i) {
			point nn = (hull[i] - hull[i-1]) * point(0, 1);
			if (abs(nn) < 1e-9) {
				continue;
			}
			res = min(res, dot(nn, hull[i]) / abs(nn));
		}
		reverse(pnts.begin(), pnts.end());
	}
	return res;
}

point inversia(point p) {
	return p / norm(p);
}

int main(void) {
	cin >> n >> m;
	vector<point> red(n), blue(m);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		red[i] = point(x, y);
	}
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		blue[i] = point(x, y);
	}
	if (m == 1) {
		cout << -1 << endl;
		return 0;
	}
	double invans = 1e10;
	for (int i = 0; i < m; ++i) {
		vector<point> r, b;
		for (int j = 0; j < m; ++j) {
			if (j == i) continue;
			b.push_back(inversia(blue[j] - blue[i]));
		}
		for (int j = 0; j < n; ++j) {
			r.push_back(inversia(red[j] - blue[i]));
		}
		invans = min(invans, calc(r, b));
	}
	vector<point> pnts(m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			pnts[j] = blue[j] - red[i];
			pnts[j] /= norm(pnts[j]);
		}
		invans = min(invans, calc2(pnts));
	}
	if (invans < 1e-10) {
		cout << -1 << endl;
	} else
		cout << fixed << setprecision(10) << 0.5 / invans << endl;
	return 0;
}