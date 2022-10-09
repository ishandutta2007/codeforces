// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int lim = 1000000;

template<class T = int, class F = plus<T>>
struct fenwick {
	vector<T> a;
	T e;
	F f;

	fenwick(int n, T e = T(), F f = F()) : a(n, e), e(e), f(f) {}

	void add(int p, const T& v) {
		for (p++; p <= (int)a.size(); p += p & -p)
			a[p-1] = f(a[p-1], v);
	}

	T operator() (int p) const {
		T v = e;
		for (; p; p -= p & -p)
			v = f(v, a[p-1]);
		return v;
	}
};

struct seg {
	int x, l, r;
};

struct pseg {
	int x, y, d, id;
};

pair<ll, ll> resi(vector<seg> hs, vector<seg> vs) {
	vector<int> lo(lim+1, -1), hi(lim+1); // line segment, []
	for (auto [x, l, r] : hs) {
		lo[x] = l;
		hi[x] = r;
	}

	fenwick drvo(lim+2, 0);
	int dp = -1;

	vector<pseg> ps;
	vector<ll> rez;

	int id = 0;
	for (auto [x, l, r] : vs) {
		ps.push_back({x, l-1, -1, id}); // gde treba da detektujemo sta je sve ubaceno, ]
		ps.push_back({x, r, 1, id});
		rez.emplace_back(0);
		id++;
	}

	sort(begin(ps), end(ps), [](auto x, auto y) { return x.y < y.y; });

	ll cv = 0, gr = 0;

	for (auto [x, y, d, id] : ps) {
		while (dp < y) {
			dp++;
			if (lo[dp] != -1) {
				drvo.add(lo[dp], 1);
				drvo.add(hi[dp]+1, -1);
			}
		}

		rez[id] += d * drvo(x+1);
	}

	for (ll x : rez) {
		cv += x;
		gr += x - 1;
	}

	return {cv, gr};
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	vector<seg> hs, vs;

	int a[2];
	cin >> a[0] >> a[1];
	int aa = 0;

	for (auto ss : {&hs, &vs}) {
		int n = a[aa++];
		while (n--) {
			int y, l, r;
			cin >> y >> l >> r;
			ss->push_back({y, l, r});
		}
		ss->push_back({0, 0, lim});
		ss->push_back({lim, 0, lim});
	}

	auto [cv, gr1] = resi(hs, vs);
	auto [cv_, gr2] = resi(vs, hs);

	cout << gr1 + gr2 - cv + 1 << '\n';
}