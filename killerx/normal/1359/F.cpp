#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using db = long double;
const db eps = 1e-17, pi = std::acos((db) -1);

struct point {
	db x, y;

	void rot(db theta) {
		db nx = x * std::cos(theta) - y * std::sin(theta);
		db ny = y * std::cos(theta) + x * std::sin(theta);
		x = nx, y = ny;
	}

	inline bool operator < (const point &oth) const { return x < oth.x || (x == oth.x && y < oth.y); }

	friend inline point operator - (const point &a, const point &b) { return {a.x - b.x, a.y - b.y}; }

	friend inline db det(point a, point b) { return a.x * b.y - a.y * b.x; }
};

db X;

struct segment {
	point a, b;

	inline db get() const { return a.y + (b.y - a.y) * (X - a.x) / (b.x - a.x); }

	inline bool operator < (const segment &oth) const { return get() < oth.get(); }

	friend inline void debug(segment s) { eprintf("polygon((%Lf, %Lf), (%Lf, %Lf))\n", s.a.x, s.a.y, s.b.x, s.b.y); }
};

inline bool chk(segment p, segment q) {
	if (std::max(p.a.x, p.b.x) + eps < std::min(q.a.x, q.b.x)) return 0;
	if (std::max(q.a.x, q.b.x) + eps < std::min(p.a.x, p.b.x)) return 0;
	if (std::max(p.a.y, p.b.y) + eps < std::min(q.a.y, q.b.y)) return 0;
	if (std::max(q.a.y, q.b.y) + eps < std::min(p.a.y, p.b.y)) return 0;
	if (det(q.a - p.a, q.b - p.a) > eps && det(q.a - p.b, q.b - p.b) > eps) return 0;
	if (det(q.a - p.a, q.b - p.a) < -eps && det(q.a - p.b, q.b - p.b) < -eps) return 0;
	if (det(p.a - q.a, p.b - q.a) > eps && det(p.a - q.b, p.b - q.b) > eps) return 0;
	if (det(p.a - q.a, p.b - q.a) < -eps && det(p.a - q.b, p.b - q.b) < -eps) return 0;
	return 1;
}

const int mxn = 25005;

int n;
point a[mxn], b[mxn];

std::mt19937 rng;

inline bool solve() {
	db theta = std::uniform_real_distribution <db> (0, 2 * pi)(rng);
	rep(i, n) {
		a[i].rot(theta);
		b[i].rot(theta);
	}
	db mx = 0;
	rep(i, n) {
		mx = std::max(mx, std::max(std::fabs(a[i].x), std::fabs(a[i].y)));
		mx = std::max(mx, std::max(std::fabs(b[i].x), std::fabs(b[i].y)));
	}
	rep(i, n) {
		a[i].x /= mx, a[i].y /= mx;
		b[i].x /= mx, b[i].y /= mx;
	}
	std::vector <db> vx, vy;
	rep(i, n) vx.push_back(a[i].x), vx.push_back(b[i].x);
	rep(i, n) vy.push_back(a[i].y), vy.push_back(b[i].y);
	std::sort(vx.begin(), vx.end());
	std::sort(vy.begin(), vy.end());
	std::vector <std::vector <segment> > add(vx.size()), del(vx.size());
	rep(i, n) {
		int l = std::lower_bound(vx.begin(), vx.end(), a[i].x) - vx.begin();
		int r = std::lower_bound(vx.begin(), vx.end(), b[i].x) - vx.begin();
		if (l > r) std::swap(l, r);
		add[l].push_back({a[i], b[i]});
		del[r].push_back({a[i], b[i]});
	}
	std::multiset <segment> st;
#ifdef DEBUG
	eprintf("!\n");
#endif
	rep(i, vx.size()) {
		X = vx[i];
		for (auto s : add[i]) {
#ifdef DEBUG
			eprintf("+ "); debug(s);
#endif
			auto it = st.insert(s);
			if (it != st.begin()) if (chk(*std::prev(it), s)) return 1;
			if (std::next(it) != st.end()) if (chk(*std::next(it), s)) return 1;
		}
		for (auto s : del[i]) {
#ifdef DEBUG
			eprintf("- "); debug(s);
#endif
			auto it = st.find(s);
			assert(it != st.end());
			if (it != st.begin() && std::next(it) != st.end()) if (chk(*std::prev(it), *std::next(it))) return 1;
			st.erase(it);
		}
#ifdef DEBUG
		for (auto s : st) debug(s);
		eprintf("\n");
#endif
	}
	return 0;
}

int x[mxn], y[mxn], dx[mxn], dy[mxn], s[mxn];

inline bool check(db T) {
	rep(i, n) {
		a[i] = {(db) x[i], (db) y[i]};
		db L = std::sqrt(dx[i] * dx[i] + dy[i] * dy[i]);
		b[i] = {x[i] + dx[i] * s[i] * T / L, y[i] + dy[i] * s[i] * T / L};
	}
	return solve();
}

int main() {
	scanf("%d", &n);
	rep(i, n) scanf("%d %d %d %d %d", &x[i], &y[i], &dx[i], &dy[i], &s[i]);
	db lb = 0, rb = 1e11;
	rep(tms, 80) {
		db md = (lb + rb) / 2;
		if (check(md)) rb = md;
		else lb = md;
	}
	if (lb > 1e10) {
		puts("No show :(");
		return 0;
	}
	printf("%.10Lf\n", rb);
	return 0;
}