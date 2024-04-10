#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using db = long double;
const db pi = std::acos(-1);
const db eps = 1e-8;

inline db dist(db x0, db y0, db x1, db y1) {
	return std::sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

inline db det(db x0, db y0, db x1, db y1) {
	return x0 * y1 - y0 * x1;
}

inline db AREA(db a, db b, db c) {
//	eprintf("%.10Lf %.10Lf %.10Lf\n", a, b, c);
	if (a - b - c > eps || b - c - a > eps || c - a - b > eps) return -1e9;
	if (std::fabs(a - b - c) < eps || std::fabs(b - a - c) < eps) return 0;
	if (std::fabs(c - a - b) < eps) return 0;
	db p = (a + b + c) / 2;
	return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

inline db COS_TH(db a, db b, db c) {
//	eprintf("cos th: %.10Lf %.10Lf %.10Lf\n", a, b, c);
	if (a - b - c > eps || b - c - a > eps || c - a - b > eps) return -1e9;
	if (std::fabs(a) < eps || std::fabs(b) < eps || std::fabs(c) < eps) return 0;
	if (std::fabs(a - b - c) < eps || std::fabs(b - a - c) < eps) return 0;
	if (std::fabs(c - a - b) < eps) return pi;
	return std::acos((a * a + b * b - c * c) / (2 * a * b));
}

int main() {
	#ifdef DEBUG
	freopen("in", "r", stdin);
	#endif
	int t1, t2, x0, y0, x1, y1, x2, y2;
	auto chk = [&] (db d) -> bool {
//		eprintf("%.10Lf\n", d);
		if (d > dist(x0, y0, x2, y2) - eps) {
			db rest = std::min(t2 + dist(x0, y0, x2, y2) - d, d - dist(x0, y0, x2, y2));
			if (d + dist(x1, y1, x2, y2) - rest - eps < t1 + dist(x0, y0, x1, y1)) return true;
		}
		bool flag = true, flbg = true;
		{
			db ang = std::fabs(det(x1 - x0, y1 - y0, x2 - x0, y2 - y0)) / 2;
			db sum = 0;
			sum += AREA(d, dist(x0, y0, x1, y1), std::min(d + dist(x0, y0, x1, y1), t1 + dist(x0, y0, x1, y1) - d));
			sum += AREA(d, dist(x0, y0, x2, y2), std::min(d + dist(x0, y0, x2, y2), t2 + dist(x0, y0, x2, y2) - d));
			sum += AREA(
				std::min(d + dist(x0, y0, x2, y2), t2 + dist(x0, y0, x2, y2) - d),
				std::min(d + dist(x0, y0, x1, y1), t1 + dist(x0, y0, x1, y1) - d),
				dist(x1, y1, x2, y2));
			if (sum - ang < -eps) flag = false;
		}
		{
			db ang = std::atan2(y1 - y0, x1 - x0) - std::atan2(y2 - y0, x2 - x0);
			if (ang < 0) ang += 2 * pi;
			ang = std::min(ang, 2 * pi - ang);
			db sum = 0;
			sum += COS_TH(d, dist(x0, y0, x1, y1), std::min(d + dist(x0, y0, x1, y1), t1 + dist(x0, y0, x1, y1) - d));
			sum += COS_TH(d, dist(x0, y0, x2, y2), std::min(d + dist(x0, y0, x2, y2), t2 + dist(x0, y0, x2, y2) - d));
			if (sum - ang < -eps) flbg = false;
		}
		return flag || flbg;
	};
	scanf("%d %d", &t1, &t2);
	scanf("%d %d", &x0, &y0);
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	std::swap(x1, x2), std::swap(y1, y2);
	db lb = 0, rb = std::min(dist(x0, y0, x1, y1) + dist(x1, y1, x2, y2) + t1, dist(x0, y0, x2, y2) + t2);
	if (rb > dist(x0, y0, x1, y1) + dist(x1, y1, x2, y2) - eps && rb > dist(x0, y0, x2, y2) - eps) {
		printf("%.10Lf\n", rb);
		return 0;
	}
	rep(_, 200) {
		db md = (lb + rb) / 2;
		if (chk(md)) lb = md;
		else rb = md;
	}
	printf("%.10Lf\n", rb);
	return 0;
}