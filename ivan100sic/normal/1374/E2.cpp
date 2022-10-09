// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

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

struct dynset {
	fenwick<int, plus<int>> f, g;
	vector<int> a, sp;
	int br_;

	int br() {
		return br_;
	}

	dynset(vector<int> a) : f(200005), g(200005), br_(0) {
		this->a = a;
		int n = a.size();
		vector<pair<int, int>> b(n);
		for (int i=0; i<n; i++) {
			b[i] = {a[i], i};
		}
		sort(begin(b), end(b));
		sp.resize(n);
		for (int i=0; i<n; i++) {
			sp[b[i].second] = i;
		}
	}

	void update(int id, int d) {
		br_ += d;
		f.add(sp[id], a[id] * d);
		g.add(sp[id], d);
	}

	int seek(int t) {
		int l = 0, r = 200005, o = 0;
		while (l <= r) {
			int m = (l+r) >> 1;
			if (g(m) >= t) {
				o = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		return f(o);
	}
};

vector<int> prefsum(vector<pair<int, int>> v) {
	int n = v.size();
	vector<int> a(n + 1);
	for (int i=0; i<n; i++) {
		a[i+1] = a[i] + v[i].first;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n), tip(n);

	vector<pair<int, int>> p[4];
	vector<int> ps[4];

	for (int i=0; i<n; i++) {
		int x, u, v;
		cin >> x >> u >> v;
		a[i] = x;
		tip[i] = 2*u + v;
		p[tip[i]].emplace_back(x, i);
	}

	for (int i=0; i<4; i++) {
		sort(begin(p[i]), end(p[i]));
		ps[i] = prefsum(p[i]);
	}

	dynset ds(a);

	// dodaj vrh 1, 2, ceo 0, 3
	for (int j=0; j<4; j++) {
		for (int i=(j == 1 || j == 2 ? k : 0); i<(int)p[j].size(); i++) {
			ds.update(p[j][i].second, 1);
		}
	}

	// koliko iz 3?
	int bestj = -1, bestv = 2.02e9;
	for (int j=0; j<=k; j++) {
		int r = k-j;
		bool radi = true;
		if (j > (int)p[3].size() || r > (int)p[1].size() || r > (int)p[2].size()) {
			radi = false;
		}

		int f = m-j-r-r;
		if (f < 0 || f > ds.br()) {
			radi = false;
		}

		if (radi) {
			int v = ps[3][j] + ps[1][r] + ps[2][r] + ds.seek(f);
			if (v < bestv) {
				bestv = v;
				bestj = j;
			}
		}

		// 3 izbaci j
		if (j < (int)p[3].size()) {
			ds.update(p[3][j].second, -1);
		}

		// 1, 2 ubaci r-1
		for (int x : {1, 2}) {
			if (r-1 >= 0 && r-1 < (int)p[x].size()) {
				ds.update(p[x][r-1].second, 1);
			}
		}
	}

	if (bestj == -1) {
		cout << "-1\n";
		return 0;
	}

	cout << bestv << '\n';

	basic_string<int> sol;
	for (int i=0; i<bestj; i++) {
		sol += p[3][i].second;
	}

	for (int i=0; i<k-bestj; i++) {
		sol += p[1][i].second;
		sol += p[2][i].second;
	}

	int ostalo = m - sol.size();
	vector<pair<int, int>> govno = p[0];

	for (int i=bestj; i<(int)p[3].size(); i++) {
		govno.push_back(p[3][i]);
	}

	for (int i=k-bestj; i<(int)p[1].size(); i++) {
		govno.push_back(p[1][i]);
	}

	for (int i=k-bestj; i<(int)p[2].size(); i++) {
		govno.push_back(p[2][i]);
	}

	sort(begin(govno), end(govno));

	for (int i=0; i<ostalo; i++)
		sol.push_back(govno[i].second);

	for (int x : sol)
		cout << x+1 << ' ';
	cout << '\n';
}