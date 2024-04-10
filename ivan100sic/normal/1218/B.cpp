#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ld x, y;
};

struct ppt {
	pt a, b;
	bool infinite;

	ppt() : infinite(true) {}
	ppt(pt a, pt b) : a(a), b(b), infinite(false) {}

	bool cmp(ppt t, ld p) const {
		if (infinite) return false;
		if (t.infinite) return true;
		return ray(p) < t.ray(p);
	}

	ld ray(ld p) const {
		ld cx = cos(p);
		ld cy = sin(p);
		ld g = (a.y*b.x - a.x*b.y) / (a.y*cx - b.y*cx - a.x*cy + b.x*cy);
		return g;
	}

	pt ray_pt(ld p) const {
		ld cx = cos(p);
		ld cy = sin(p);
		ld g = (a.y*b.x - a.x*b.y) / (a.y*cx - b.y*cx - a.x*cy + b.x*cy);
		return {g*cx, g*cy};
	}
};

ld det(pt a, pt b) {
	return a.x*b.y - b.x*a.y;
}

struct line {
	pt a, b;
	ld pa, pb;
};

const ld pi = acos(ld(-1));

ld atan22(ld y, ld x) {
	ld t = atan2(y, x);
	if (t < 0)
		t += 2*pi;
	return t;
}

vector<line> lines;
ld u[300000]; int k;
ld v[300000];

void radi(pt a, pt b) {
	if (det(a, b) == 0)
		return;
	if (det(a, b) < 0)
		swap(a, b);
	if (a.y < 0 && b.y > 0) {
		// podeli na dve
		pt t = {det(a, b) / (b.y - a.y), 0};
		radi(a, t);
		radi(b, t);
	} else {
		if (a.y < 0 && b.y == 0)
			b.y -= 1e-10;

		ld pa = atan22(a.y, a.x);
		ld pb = atan22(b.y, b.x);
		lines.push_back({a, b, pa, pb});
	}
}

struct cvor {
	ppt p, q;

	void inc(ppt r, ld ray) {
		if (r.cmp(p, ray))
			q = p, p = r;
		else if (r.cmp(q, ray))
			q = r;
	}

	void inc(cvor s, ld ray) {
		inc(s.p, ray);
		inc(s.q, ray);
	}
};

const int maxn = 131072;

struct segmentno {
	vector<cvor> a;

	segmentno() : a(2*maxn) {}

	void add(ppt c, int l, int r, int x=1, int xl=0, int xr=maxn-1) {
		if (xr < l || r < xl)
			return;
		if (l <= xl && xr <= r) {
			a[x].inc(c, v[xl]);
			return;
		}
		int xm = (xl+xr) >> 1;
		add(c, l, r, 2*x, xl, xm);
		add(c, l, r, 2*x+1, xm+1, xr);
	}

	void push() {
		vector<int> xl(2*maxn);
		for (int i=0; i<maxn; i++)
			xl[i+maxn] = i;
		for (int i=maxn-1; i; i--)
			xl[i] = xl[2*i];
		for (int i=1; i<maxn; i++) {
			a[2*i].inc(a[i], v[xl[2*i]]);
			a[2*i+1].inc(a[i], v[xl[2*i+1]]);
		}
	}

	ld area() {
		push();
		ld sol = 0;
		for (int i=maxn; i<2*maxn; i++) {
			if (!a[i].q.infinite) {
				pt c = a[i].p.ray_pt(u[i-maxn]);
				pt d = a[i].p.ray_pt(u[i-maxn+1]);
				sol -= abs(det(c, d));
				c = a[i].q.ray_pt(u[i-maxn]);
				d = a[i].q.ray_pt(u[i-maxn+1]);
				sol += abs(det(c, d));
			}
		}
		return sol / 2;
	}
} drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	while (n--) {
		int m;
		cin >> m;
		vector<pt> a(m+1);
		for (int i=0; i<m; i++)
			cin >> a[i].x >> a[i].y;
		a[m] = a[0];
		for (int i=0; i<m; i++)
			radi(a[i], a[i+1]);
	}

	for (auto [a, b, pa, pb] : lines) {
		u[k++] = pa;
		u[k++] = pb;
	}
	sort(u, u+k);
	k = unique(u, u+k) - u;
	for (int i=0; i<k-1; i++)
		v[i] = (u[i] + u[i+1]) / 2;
	
	for (auto [a, b, pa, pb] : lines) {
		int ia = lower_bound(u, u+k, pa) - u;
		int ib = lower_bound(u, u+k, pb) - u;
		drvo.add({a, b}, ia, ib-1);
	}

	cout << setprecision(20) << fixed << drvo.area() << '\n';
}