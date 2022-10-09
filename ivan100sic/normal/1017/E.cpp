#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct pt {
	ll x, y;
	bool operator< (const pt& other) const {
		return x < other.x || (x == other.x && y < other.y);
	}
};

ll det(pt a, pt b, pt c) {
	return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

ll len(pt a, pt b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

ll sp(pt a, pt b) {
	return a.x*b.x + a.y*b.y;
}

ll spa(pt a, pt b, pt c) {
	pt u = {a.x - b.x, a.y - b.y};
	pt v = {b.x - c.x, b.y - c.y};

	return sp(u, v);
}

vector<pt> hull_part(vector<pt> a) {
	vector<pt> st;
	for (pt p : a) {
		while (st.size() >= 2 && det(st[st.size() - 2], st.back(), p) <= 0)
			st.pop_back();
		st.push_back(p);
	}
	st.pop_back();
	return st;
}

vector<pt> hull(vector<pt> a) {
	vector<pt> h = hull_part(a);
	reverse(a.begin(), a.end());
	auto h2 = hull_part(a);
	for (pt p : h2)
		h.push_back(p);
	return h;
}

vector<pt> a, b, ha, hb;
int n, m;

const ll INF = 1'000'000'000'000'000'000ll;
const ll ALT = 1'000ll;

vector<ll> descriptor(vector<pt> a) {
	int n = a.size();

	vector<ll> d;

	auto p = a[0];
	a.push_back(p);

	p = a[1];
	a.push_back(p);

	for (int i=0; i<n; i++) {
		d.push_back(len(a[i], a[i+1]));
		d.push_back(INF + spa(a[i], a[i+1], a[i+2]));
	}

	return d;
}

bool kmp(vector<ll> s, vector<ll> q) {
	int n = s.size();
	int m = q.size();
	
	vector<int> f(m);
	fill(f.begin(), f.end(), -1);

	for (int r=1, l=-1; r<m; r++) {
		while (l != -1 && q[l+1] != q[r])
			l = f[l];

		if (q[l+1] == q[r])
			f[r] = ++l;
	}

	int t = -1;
	for (int i=0; i<n; i++) {
		while (t != -1 && s[i] != q[t + 1])
			t = f[t];
		if (s[i] == q[t+1])
			t++;
		if (t == m-1)
			return true;
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	for (pt& p : a)
		cin >> p.x >> p.y;
	for (pt& p : b)
		cin >> p.x >> p.y;

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ha = hull(a);
	hb = hull(b);

	/*
	for (pt p : ha)
		cerr << p.x << ' ' << p.y << '\n';
	cerr << '\n';

	for (pt p : hb)
		cerr << p.x << ' ' << p.y << '\n';
	cerr << '\n';
	*/

	if (ha.size() == 2 || hb.size() == 2) {
		if (ha.size() == hb.size()) {
			if (len(ha[0], ha[1]) == len(hb[0], hb[1])) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		} else {
			cout << "NO\n";
		}
		return 0;
	}

	auto da = descriptor(ha);
	auto db = descriptor(hb);

	auto ddaa = da;
	for (auto x : da)
		ddaa.push_back(x);

	/*
	for (ll x : ddaa)
		cerr << x << ' ';
	cerr << '\n';

	for (ll x : db)
		cerr << x << ' ';
	cerr << '\n';
	*/

	cout << (kmp(ddaa, db) ? "YES\n" : "NO\n");
}