// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct rac {
	ll x, y;

	rac(ll x, ll y) : x(x), y(y) {
		if (y < 0) {
			x = -x;
			y = -y;
		}
	}

	ll dif(const rac& b) const {
		return x*b.y - b.x*y;
	}
};

struct vek {
	rac r;
	int d;

	bool operator< (const vek& b) const {
		ll dif = r.dif(b.r);
		if (dif) return dif < 0;
		return d < b.d;
	}
};

struct pt {
	ll x, y;
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

vector<pt> hull(const vector<pt>& v) {
	vector<pt> s;
	for (pt p : v) {
		while (s.size() >= 2 && det(s[s.size() - 2], s.back(), p) >= 0) {
			s.pop_back();
		}
		s.push_back(p);
	}
	return s;
}

int n;
int xl[2005], xr[2005], y[2005];
vector<vek> v;
vector<rac> q;

ld proj(pt p, rac v) {
	return p.x - ld(p.y) * v.x / v.y;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> xl[i] >> xr[i] >> y[i];
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (y[i] < y[j]) {
				int dy = y[j] - y[i];
				v.push_back({rac(xl[j] - xr[i], dy), +1});
				v.push_back({rac(xr[j] - xl[i], dy), -1});
			}
		}
	}

	if (v.size() == 0) {
		cout << *max_element(xr, xr+n) - *min_element(xl, xl+n) << '\n';
		return 0;
	}

	sort(begin(v), end(v));

	int pre = 0;
	for (auto vv : v) {
		int posle = pre + vv.d;
		if (!pre || !posle) {
			if (q.empty() || q.back().dif(vv.r)) {
				q.push_back(vv.r);
			}
		}
		pre = posle;
	}

	vector<ld> lp(q.size()), rp(q.size());

	// lp
	vector<pt> vl(n);
	for (int i=0; i<n; i++) {
		vl[i] = {xl[i], y[i]};
	}

	sort(begin(vl), end(vl), [](pt a, pt b) {
		return make_pair(a.y, a.x) < make_pair(b.y, b.x);
	});

	vl = hull(vl);

	for (ull i=0, j=0; i<q.size(); i++) {
		while (j+1 < vl.size() && proj(vl[j+1], q[i]) < proj(vl[j], q[i])) {
			j++;
		}
		lp[i] = proj(vl[j], q[i]);
	}

	// rp
	vector<pt> vr(n);
	for (int i=0; i<n; i++) {
		vr[i] = {xr[i], y[i]};
	}

	sort(begin(vr), end(vr), [](pt a, pt b) {
		return make_pair(-a.y, -a.x) < make_pair(-b.y, -b.x);
	});

	vr = hull(vr);

	for (ull i=0, j=0; i<q.size(); i++) {
		while (j+1 < vr.size() && proj(vr[j+1], q[i]) > proj(vr[j], q[i])) {
			j++;
		}
		rp[i] = proj(vr[j], q[i]);
	}

	ld sol = 1e18;
	for (ull i=0; i<q.size(); i++) {
		sol = min(sol, rp[i] - lp[i]);
	}

	cout << setprecision(20) << fixed << sol << '\n';
}