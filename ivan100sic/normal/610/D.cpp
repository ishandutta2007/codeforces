#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct seg {
	int l, r, x;

	bool operator< (const seg& b) const {
		return tie(x, l) < tie(b.x, b.l);
	}

	bool sekuse(const seg& b) const {
		return x == b.x && max(l, b.l) <= min(r, b.r);
	}

	void pripoji(const seg& b) {
		l = min(l, b.l);
		r = max(r, b.r);
	}
};

int n;
vector<seg> h, v;

void procisti(vector<seg>& a) {
	sort(a.begin(), a.end());
	vector<seg> b;
	for (auto t : a) {
		while (b.size()) {
			if (b.back().sekuse(t)) {
				t.pripoji(b.back());
				b.pop_back();
			} else {
				break;
			}
		}
		b.push_back(t);
	}
	swap(a, b);
}

struct node {
	int l, r, v;
} b[200000 * 31]; int bsz;

const int wid = 1'000'000'007;

int add(int p, int v, int x, int xl=-wid, int xr=wid) {
	if (!x)
		x = ++bsz;
	b[x].v += v;
	if (xl != xr) {
		int xm = xl + ((xr-xl) >> 1);
		if (p <= xm)
			b[x].l = add(p, v, b[x].l, xl, xm);
		else
			b[x].r = add(p, v, b[x].r, xm+1, xr);
	}
	return x;
}

int qry(int l, int r, int x, int xl=-wid, int xr=wid) {
	if (r < xl || xr < l || !x)
		return 0;
	if (l <= xl && xr <= r)
		return b[x].v;
	int xm = xl + ((xr-xl) >> 1);
	return qry(l, r, b[x].l, xl, xm) + qry(l, r, b[x].r, xm+1, xr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a > c)
			swap(a, c);
		if (b > d)
			swap(b, d);
		if (a == c)
			v.push_back({b, d, a});
		else
			h.push_back({a, c, b});
	}

	procisti(h);
	procisti(v);

	ll sol = 0;
	for (auto t : h)
		sol += t.r - t.l + 1;
	for (auto t : v)
		sol += t.r - t.l + 1;

	map<int, vector<array<int, 3>>> e;
	for (auto t : h) {
		e[t.l].push_back({1, t.x, 1});
		e[t.r+1].push_back({1, t.x, -1});
	}
	for (auto t : v) {
		e[t.x].push_back({0, t.l, t.r});
	}
	int root = 0;
	for (auto [_, w] : e) {
		for (auto v : w) {
			if (v[0])
				root = add(v[1], v[2], root);
			else
				sol -= qry(v[1], v[2], root);
		}
			
	}
	cout << sol << '\n';
}