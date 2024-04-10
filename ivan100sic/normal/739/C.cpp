#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;

int n;
long long a[300005], d[300005];
int tp[300005];

struct segment {
	int l, r, tip;
	mutable int val;

	int len() const {
		return r-l+1;
	}

	bool operator< (const segment& other) const {
		return l < other.l;
	}
};

set<segment> sg;
multiset<int> vals;

inline void sg_erase(segment u) {
	sg.erase(u);
	if (u.val != -1) {
		vals.erase(vals.find(u.val));
	}
}

inline void sg_insert(segment u) {
	sg.insert(u);
	if (u.val != -1) {
		vals.insert(u.val);
	}
}

inline void change_val(int& val, int nu) {
	if (val != -1) {
		vals.erase(vals.find(val));
	}
	val = nu;
	if (val != -1) {
		vals.insert(val);
	}
}

inline void update_vals(set<segment>::iterator it) {
	if (it == sg.end()) return;
	int val = it->val;
	if (it->tip == 2) {
		val = it->len() + 1;
		auto nit = next(it);
		if (nit != sg.end()) {
			if (nit->tip == 0) {
				val += nit->len();
			}
		}
	} else if (it->tip == 0) {
		val = it->len() + 1;
	}

	if (val != it->val) {
		change_val(it->val, val);
	}
}

inline void compute_vals() {
	auto it = sg.begin();
	while (it != sg.end()) {
		update_vals(it);
		++it;
	}
}

inline int ttip(long long x) {
	if (x < 0) {
		return 0;
	} else if (x == 0) {
		return 1;
	} else {
		return 2;
	}
}

inline void update_vals_surround(set<segment>::iterator it) {
	if (it == sg.end()) return;

	if (next(it) != sg.end()) {
		update_vals(next(it));
	}

	update_vals(it);
	if (it != sg.begin()) {
		update_vals(--it);
	}
}

inline void sg_merge(set<segment>::iterator it) {

	if (it == sg.end()) return;

	segment tmp = *it;
	tmp.val = -1;

	if (it != sg.begin()) {
		if (prev(it)->tip == it->tip && prev(it)->r == it->l - 1) {

			segment lu = *prev(it);
			sg_erase(lu);

			tmp.l = lu.l;
		}
	}

	if (next(it) != sg.end()) {
		if (next(it)->tip == it->tip  && next(it)->l == it->r + 1) {

			segment ru = *next(it);
			sg_erase(ru);

			tmp.r = ru.r;
		}
	}

	sg_erase(*it);
	sg_insert(tmp); // pravi insert

	update_vals_surround(sg.find(tmp));
}

inline void update_delta(int i, long long vr) {
	if (tp[i] == ttip(d[i] + vr)) {
		d[i] += vr;
		return;
	}
	// nadji segment koji sadrzi i
	segment ki;
	ki.l = i;
	auto it = --sg.upper_bound(ki);

	segment izv = *it;
	sg_erase(izv);

	segment levi;
	levi.l = izv.l;
	levi.r = i-1;
	levi.tip = izv.tip;
	levi.val = -1;

	segment desni;
	desni.l = i+1;
	desni.r = izv.r;
	desni.tip = izv.tip;
	desni.val = -1;

	tp[i] = ttip(d[i] += vr);

	segment srednji;
	srednji.l = i;
	srednji.r = i;
	srednji.tip = tp[i];
	srednji.val = -1;

	// RAW INSERT

	sg_insert(srednji);

	if (levi.len() > 0) {
		//cerr << "insertujem levi\n";
		sg_insert(levi);
		sg_merge(sg.find(levi));
	}

	if (desni.len() > 0) {
		//cerr << "insertujem desni\n";
		sg_insert(desni);
		sg_merge(sg.find(desni));
	}

	sg_merge(sg.find(srednji));
}

void debug_vals() {
	cerr << "Vals: \n";
	for (int x : vals) {
		cerr << x << ' ';
	}
	cerr << '\n';
}

void debug_segs() {
	cerr << "Segs: \n";
	for (segment s : sg) {
		cerr << s.l << ' ' << s.r << ' ' << s.tip << ' ' << s.val << '\n';
	}
	cerr << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		d[i] = a[i] - a[i-1];
	}

	for (int i=2; i<=n; i++) {
		tp[i] = ttip(d[i]);
	}

	int start = 2;
	for (int i=3; i<=n+1; i++) {
		if (i == n+1 || tp[i] != tp[i-1]) {
			segment tmp;

			tmp.l = start;
			tmp.r = i-1;
			tmp.tip = tp[i-1];
			tmp.val = -1;

			sg.insert(tmp);

			start = i;
		}
	}

	compute_vals();

	//debug_vals();
	//debug_segs();

	int m;
	cin >> m;
	while (m--) {
		int l, r;
		long long p;
		cin >> l >> r >> p;

		if (l > 1) {
			update_delta(l, p);
		}

		if (r < n) {
			update_delta(r+1, -p);
		}

		//debug_vals();
		//debug_segs();

		if (vals.empty()) {
			cout << "1\n";
		} else {
			cout << *vals.rbegin() << '\n';
		}
	}
}