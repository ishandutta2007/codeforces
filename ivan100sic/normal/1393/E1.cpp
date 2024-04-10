// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int, class F = plus<T>>
struct sparse_table {
	vector<vector<T>> d;
	T e;
	F f;

	sparse_table(vector<T> a, T e = T(), F f = F()) : e(e), f(f) {
		d.push_back(a);
		int n = a.size();
		for (int h=1; h*2<=n; h<<=1) {
			int m = a.size() - h;
			vector<T> b(m);
			for (int i=0; i<m; i++)
				b[i] = f(a[i], a[i+h]);
			d.push_back(b);
			swap(a, b);
		}
	}

	T operator() (int l, int r) const {
		if (l >= r) return e;
		int i = 31 - __builtin_clz(r-l);
		return f(d[i][l], d[i][r-(1<<i)]);
	}
};

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 1'000'000'007;
typedef modint<mod> mint;

vector<int> scs_faster(const string& s) {
	int n = s.size(), k = 28, sz = 0;
	vector<int> p(n), c(s.begin(), s.end());
	vector<vector<int>> g(max(n, k));
	for (int i=0; i<n; i++)
		g[c[i]].push_back(i);
	for (auto& gr : g) {
		for (int i : gr)
			p[sz++] = i;
		gr.clear();
	}
	for (int h=1; h<n; h*=2) {
		vector<int> pnew(n), cnew(n);
		for (int j : p) {
			int jp = (j+n-h)%n;
			g[c[jp]].push_back(jp);
		}
		sz = 0;
		for (auto& gr : g) {
			for (int i : gr)
				pnew[sz++] = i;
			gr.clear();
		}
		cnew[pnew[0]] = 0;
		int numc = 1;
		for (int i=1; i<n; i++) {
			int s0 = pnew[i-1], s1 = pnew[i];
			if (c[s1] == c[s0] && c[(s1+h)%n] == c[(s0+h)%n])
				cnew[s1] = numc-1;
			else
				cnew[s1] = numc++;
		}
		swap(c, cnew);
		swap(p, pnew);
	}
	return p;
}

vector<int> sarray_scs(const string& s) {
	vector<int> v = scs_faster(s + '\0');
	v.erase(v.begin());
	return v;
}

pair<vector<int>, vector<int>> lcp_array(const string& s, const vector<int>& p) {
	int n = s.size(), k = 0;
	vector<int> q(n-1), r(n);
	for (int i=0; i<n; i++)
		r[p[i]] = i;
	for (int i=0; i<n; i++) {
		if (r[i] != n-1) {
			int j = p[r[i] + 1];
			while (i+k < n && j+k < n && s[i+k] == s[j+k])
				k++;
			q[r[i]] = k;
			k = max(0, k-1);
		} else {
			k = 0;
		}
	}
	return {q, r};
}

struct hole {
	int f;
	int o;
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n;
	cin >> n;

	vector<string> a(n);
	for (auto& s : a) {
		cin >> s;
		for (char& c : s) {
			c = c - 'a' + 1;
		}
	}

	vector<mint> ol(a[0].size() + 1, 1);
	for (int i=0; i<n-1; i++) {
		string s = a[i] + a[i+1];
		int m1 = a[i].size(), m2 = a[i+1].size();
		auto p = sarray_scs(s);
		auto [q, r] = lcp_array(s, p);
		sparse_table t(q, int(1e9), [](int x, int y) { return min(x, y); });

		auto lcp = [&](int i, int j) {
			i = r[i];
			j = r[j];
			return t(min(i, j), max(i, j));
		};

		auto cmp = [&](hole u, hole v) {
			int useg[2][2], vseg[2][2];
			useg[0][0] = u.f*m1;
			useg[0][1] = useg[0][0] + u.o;
			useg[1][0] = useg[0][1] + 1;
			useg[1][1] = u.f ? m1+m2 : m1;

			// korekcija
			useg[1][0] = min(useg[1][0], useg[1][1]);

			vseg[0][0] = v.f*m1;
			vseg[0][1] = vseg[0][0] + v.o;
			vseg[1][0] = vseg[0][1] + 1;
			vseg[1][1] = v.f ? m1+m2 : m1;

			// korekcija
			vseg[1][0] = min(vseg[1][0], vseg[1][1]);

			int ui = 0, vi = 0, ud = 0, vd = 0;
			while (ui < 2 && vi < 2) {
				int maxlen = min(useg[ui][1] - useg[ui][0] - ud, vseg[vi][1] - vseg[vi][0] - vd);
				int len = 0;

				if (maxlen) {
					len = lcp(useg[ui][0] + ud, vseg[vi][0] + vd);
				}

				if (len < maxlen) {
					return s[useg[ui][0] + ud + len] < s[vseg[vi][0] + vd + len];
				} else {
					ud += maxlen;
					vd += maxlen;
					while (ui < 2 && ud == useg[ui][1] - useg[ui][0]) ui++, ud = 0;
					while (vi < 2 && vd == vseg[vi][1] - vseg[vi][0]) vi++, vd = 0;
				}
			}

			if (ui == vi) {
				return u.f < v.f;
			} else {
				return ui > vi;
			}
		};

		vector<hole> vh;
		for (int j=0; j<=m1; j++) vh.push_back({0, j});
		for (int j=0; j<=m2; j++) vh.push_back({1, j});
		sort(begin(vh), end(vh), cmp);

		vector<mint> nu(m2 + 1);

		mint rs = 0;
		for (auto [f, o] : vh) {
			if (f == 0) rs += ol[o];
			else nu[o] += rs;
		}

		swap(ol, nu);
	}

	cout << accumulate(begin(ol), end(ol), mint(0))() << '\n';
}