#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ld eps = 1e-8;
inline bool eq(ld x, ld y) { return fabs(x - y) < eps; }
inline bool leq(ld x, ld y) { return x < y || eq(x, y); }
inline bool lss(ld x, ld y) { return x < y && !eq(x, y); }

struct pt {
	ld x;
	ld y;
	pt(ld x = 0, ld y = 0): x(x), y(y) {}
	pt operator * (ld t) const { return pt(x * t, y * t); }
	pt operator + (const pt& rhs) const { return pt(x + rhs.x, y + rhs.y); }
	pt operator - (const pt& rhs) const { return pt(x - rhs.x, y - rhs.y); }
	pt operator + (pt&& rhs) const { return pt(x + rhs.x, y + rhs.y); }
	pt operator - (pt&& rhs) const { return pt(x - rhs.x, y - rhs.y); }
	pt rot() const { return pt(y, -x); }
	bool operator < (const pt& rhs) const { return lss(x, rhs.x) || (eq(x, rhs.x) && lss(y, rhs.y)); }
	bool operator == (const pt& rhs) const { return eq(x, rhs.x) && eq(y, rhs.y); }
	ld abs() const { return sqrt(max<ld>(0., x * x + y * y)); }
};

pt c[5555];
int r[5555];
set<pt> s[5555];
set<pt> points;

vector<pt> intersect(int a, int b) {
	ld d = (c[a] - c[b]).abs();
	// cout << r[a] << " " << r[b] << " " << d << endl;
	if (lss(r[a] + r[b], d) || lss(r[a] + d, r[b]) || lss(r[b] + d, r[a])) { // ah yes
		return {};
	}
	// cout << a << " " << b << endl;
	// z + t = d
	// z^2 - t^2 = r1^2 - r2^2
	ld diff = (r[a] * r[a] - r[b] * r[b]) / d;
	ld sum = d;
	ld z = (sum + diff) / 2.;
	ld h = sqrt(max<ld>(0, r[a] * r[a] - z * z));
	pt vec = (c[b] - c[a]) * (1. / d);
	pt vec2 = vec.rot();
	vec = vec * z;
	vec2 = vec2 * h;
	return {c[a] + vec + vec2, c[a] + vec - vec2};
}

vector<int> dsu;
int find(int x) {
	if (dsu[x] < 0)
		return x;
	return dsu[x] = find(dsu[x]);
}

int unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)
		return 0;
	if (dsu[x] > dsu[y])
		swap(x, y);
	dsu[x] += dsu[y];
	dsu[y] = x;
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> c[i].x >> c[i].y >> r[i];
	}
	dsu.resize(n, -1);
	int comps = n;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			auto in = intersect(i, j);
			if (!in.empty()) {
				comps -= unite(i, j);
			}
			for (const pt& p: in) {
				// cout << i << " " << j << " " << p.x << " " << p.y << endl;
				points.insert(p);
				s[i].insert(p);
				s[j].insert(p);
			}
		}
	}
	int v = points.size();
	int e = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i].size() == 0) {
			v += 1;
			e += 1;
		} else {
			e += s[i].size();
		}
	}
	// v + f - e = 1 + comps
	int f = 1 + comps + e - v;
	cout << f << "\n";
	// cout << "v = " << v << endl;
	// cout << "e = " << e << endl;
}