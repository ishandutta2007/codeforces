#include <bits/stdc++.h>

using namespace std;

const int N = 100;
const double op = 1e-8;

struct Point {
	double x, y;
	Point() { }
	Point(double x, double y) : x(x), y(y) { }
	double abs() const { return hypot(x, y); }
};

Point operator+(const Point& lhs, const Point& rhs) {
	return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

Point operator-(const Point& lhs, const Point& rhs) {
	return Point(lhs.x - rhs.x, lhs.y - rhs.y);
}

Point operator*(const double& lhs, const Point& rhs) {
	return Point(lhs * rhs.x, lhs * rhs.y);
}

double operator*(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.x + lhs.y * rhs.y;
}

double operator%(const Point& lhs, const Point& rhs) {
	return lhs.x * rhs.y - rhs.x * lhs.y;
}

bool parallel(const Point& a, const Point& b, const Point& c, const Point& d) {
	return fabs((b - a) % (c - d)) < op;
}

bool between(const Point& a, const Point& b, const Point c) {
	return (c - a) * (b - a) > op && (c - b) * (a - b) > op;
}

Point intersection(const Point& a, const Point& b, const Point& c, const Point& d) {
	double r = ((c - a) % (d - c)) / ((b - a) % (d - c));
	return a + r * (b - a);
}

int main() {
	int n;
	Point s, t, x;
	double sum, ans;
	vector<int> k;
	vector<Point> p;

	scanf("%lf%lf%lf%lf%d", &s.x, &s.y, &t.x, &t.y, &n);
	p.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}
	p.push_back(p.front());

	for (int i = 0; i < (int)p.size() - 1; ++i) {
		if (parallel(p[i], p[i + 1], s, t)) {
			continue;
		}
		x = intersection(p[i], p[i + 1], s, t);
		if (!between(s, t, x)) {
			continue;
		}
		if ((p[i] - x).abs() < op) {
			k.push_back(i);
		} else if (between(p[i], p[i + 1], x)) {
			++i;
			k.push_back(i);
			p.insert(p.begin() + i, x);
		}
	}

	if (k.size() < 2) {
		ans = (s - t).abs();
	} else {
		if ((s - p[k[0]]).abs() > (s - p[k[1]]).abs()) {
			swap(k[0], k[1]);
		}
		ans = 2 * (p[k[0]] - p[k[1]]).abs();
		n = (int)p.size() - 1;
		sum = 0;
		for (int i = k[0]; i != k[1]; i = (i + 1) % n) {
			sum += (p[i + 1] - p[i]).abs();
		}
		ans = min(ans, sum);
		sum = 0;
		for (int i = k[1]; i != k[0]; i = (i + 1) % n) {
			sum += (p[i + 1] - p[i]).abs();
		}
		ans = min(ans, sum);
		ans += (s - p[k[0]]).abs();
		ans += (t - p[k[1]]).abs();
	}
	printf("%.10lf\n", ans);

	return 0;
}