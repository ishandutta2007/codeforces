#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct suffix_automaton {
	struct node {
		int len, el, er;
		bool orig;
		map<char, int> next;
		vector<int> inv;
		int lnp[18];
		int& link() { return lnp[0]; }
		bool eh(int x) { return el <= x && x < er; }
	};

	int sz, last, n;
	vector<node> b;
	vector<int> endpos, pref;

	suffix_automaton() {}

	suffix_automaton(const string& s) {
		b.resize(2 * s.size() + 3);
		sz = 1;
		n = s.size();
		last = 0;
		b[0].len = 0;
		b[0].link() = -1;
		b[0].orig = false;
		pref.resize(n+1);
		for (char c : s)
			extend(c);
		finish();
	}

	void extend(char c) {
		int curr = sz++;
		b[curr].len = b[last].len + 1;
		pref[b[curr].len] = curr;
		b[curr].orig = true;
		int p = last;
		for (; p != -1 && !b[p].next.count(c); p = b[p].link())
			b[p].next[c] = curr;
		if (p == -1) {
			b[curr].link() = 0;
		} else {
			int q = b[p].next[c];
			if (b[p].len + 1 == b[q].len) {
				b[curr].link() = q;
			} else {
				int clone = sz++;
				b[clone].orig = false;
				b[clone].len = b[p].len + 1;
				b[clone].link() = b[q].link();
				b[clone].next = b[q].next;
				for (; p != -1 && b[p].next[c] == q; p = b[p].link())
					b[p].next[c] = clone;
				b[q].link() = b[curr].link() = clone;
			}
		}
		last = curr;
	}

	void dfs(int x, int& t) {
		for (int j=1; j<18; j++) {
			int y = b[x].lnp[j-1];
			if (y == -1)
				b[x].lnp[j] = y;
			else
				b[x].lnp[j] = b[y].lnp[j-1];
		}

		b[x].el = t;
		if (b[x].orig)
			endpos[t++] = b[x].len;
		for (int y : b[x].inv)
			dfs(y, t);
		b[x].er = t;
	}

	void finish() {
		endpos.resize(n);
		for (int i=1; i<sz; i++)
			b[b[i].link()].inv.push_back(i);
		int t = 0;
		dfs(0, t);
	}
};

const ull hmod = (1ull << 61) - 1;
const ull hbase = 3423419349879832ull;

inline ull hadd(ull x, ull y) {
	x += y;
	return x - hmod*(x >= hmod);
}

inline ull hmul(ull a, ull b) {
	ull l1 = (unsigned)a, h1 = a >> 32, l2 = (unsigned)b, h2 = b >> 32;
	ull l = l1*l2, m = l1*h2 + l2*h1, h=h1*h2;
	ull ret = (l&hmod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
	ret = (ret & hmod) + (ret >> 61);
	ret = (ret & hmod) + (ret >> 61);
	return ret - 1;
}

struct hasher {
	string s;
	int n;
	vector<ull> h, p;

	hasher() {}

	hasher(const string& s) {
		this->s = s;
		n = s.size();
		h.resize(n+1);
		p.resize(n+1);
		p[0] = 1;
		h[0] = 0;
		for (int i=0; i<n; i++) {
			p[i+1] = hmul(p[i], hbase);
			h[i+1] = hadd(hmul(h[i], hbase), s[i]);
		}
	}

	ull operator() (int l, int r) const {
		return hadd(h[r], hmod - hmul(h[l], p[r-l]));
	}
};

struct fractional_cascading {

	struct node {
		int l, r;
		vector<tuple<int, int, int>> ch;
	};

	vector<node> a;
	int n;

	int newnode() {
		a.emplace_back();
		return a.size() - 1;
	}

	int build(const vector<int>& b, int l, int r) {
		int x = newnode();

		if (r-l == 1) {
			a[x].l = a[x].r = -1;
			a[x].ch = {{b[l], -1, -1}};
		} else {
			int m = (l+r) >> 1;
			a[x].l = build(b, l, m);
			a[x].r = build(b, m, r);

			// merge (unique)
			int u = a[a[x].l].ch.size(), v = a[a[x].r].ch.size();
			a[x].ch.resize(u + v);
			int i = 0, j = 0;
			while (i < u || j < v) {
				bool left;
				if (i == u)
					left = false;
				else if (j == v)
					left = true;
				else
					left = a[a[x].l].ch[i] < a[a[x].r].ch[j];
				a[x].ch[i+j] = {get<0>(left ? a[a[x].l].ch[i] : a[a[x].r].ch[j]), i, j};
				(left ? i : j)++;
			}
		}
		return x;
	}

	fractional_cascading() {}

	fractional_cascading(const vector<int>& b) { // mora permutacija 1..n
		n = b.size();
		vector<int> binv(n);
		for (int i=0; i<n; i++)
			binv[b[i]-1] = i;
		a.reserve(2*n+5);
		build(binv, 0, n);
	}

	int md1(int x, int p, int c) {
		if (p == (int)a[x].ch.size())
			return a[c].ch.size();
		return get<1>(a[x].ch[p]);
	}

	int md2(int x, int p, int c) {
		if (p == (int)a[x].ch.size())
			return a[c].ch.size();
		return get<2>(a[x].ch[p]);
	}

	void rek(int x, int xl, int xr, int l, int r, int v, int c, int& p, int& q) {
		if (r <= xl || xr <= l)
			return;
		if (l <= xl && xr <= r) {
			if (c < (int)a[x].ch.size()) {
				// larger
				if (get<0>(a[x].ch[c]) == v) {
					if (c+1 < (int)a[x].ch.size())
						q = min(q, get<0>(a[x].ch[c+1]));
				} else {
					q = min(q, get<0>(a[x].ch[c]));
				}
			}

			if (c > 0) {
				// smaller
				p = max(p, get<0>(a[x].ch[c-1]));
			}
			return;
		}
		int xm = (xl+xr) >> 1;
		rek(a[x].l, xl, xm, l, r, v, md1(x, c, a[x].l), p, q);
		rek(a[x].r, xm, xr, l, r, v, md2(x, c, a[x].r), p, q);
	}

	// 1 <= l <= r <= n+1, 0 <= x < n
	pair<int, int> neighborhood(int l, int r, int x) {
		l--, r--;
		int p = -1e9;
		int q = 1e9;
		rek(0, 0, n, l, r, x, x, p, q);
		if (p == -1e9)
			p = -1;
		if (q == 1e9)
			q = -1;
		return {p, q};
	}
};

struct main_solver {

	struct dag_node {
		int dp;
		vector<int> ch;

		dag_node() : dp(-1) {}
	};

	int n;
	string s;
	hasher h;
	map<ull, int> id;
	vector<dag_node> w;
	suffix_automaton a;
	fractional_cascading c;

	int newnode() {
		w.emplace_back();
		return w.size() - 1;
	}

	int extend_left(int u, int v, int r) {
		if (r == u || r == v)
			return r;
		// mora da ima endpos > r, endpos <= v
		// duzina najvise r-u
		// ako je minlen > r-u to znaci da ne moze
		int x = a.pref[r];
		auto [p, q] = c.neighborhood(r+1, v+1, a.b[x].el);
		// da nisam ja samom sebi resenje?
		if ((a.b[x].eh(p) || a.b[x].eh(q)) &&
			(a.b[a.b[x].link()].len + 1 <= r-u))
		{
			return r - min(r-u, a.b[x].len);
		}

		// ako ne hvata onda ga popni
		for (int i=17; i>=0; i--) {
			int y = a.b[x].lnp[i];
			if (y > 0 && ((!a.b[y].eh(p) && !a.b[y].eh(q)) || 
				(a.b[a.b[y].link()].len + 1 > r-u)))
			{
				x = y;
			}
		}

		x = a.b[x].link();
		return r - min(r-u, a.b[x].len);
	}

	;

	void rek(int u, int v, int l, int r, int el, int er,
		vector<pair<int, int>>& rekrez)
	{
		if (l == r) {
			rekrez.emplace_back(er, r);
			return;
		}

		if (r-l <= 1) {
			rekrez.emplace_back(el, l);
			rekrez.emplace_back(er, r);
			return;
		}

		if (el == er) {
			rekrez.emplace_back(er, r);
			return;
		}

		int m = (l+r) >> 1;
		int em = extend_left(u, v, m);
		rek(u, v, l, m, el, em, rekrez);
		rek(u, v, m, r, em, er, rekrez);
	}

	int solve(int u, int v) {
		ull hh = h(u, v);
		if (id.count(hh))
			return id[hh];
		int x = newnode();
		// evaluirati extend_left za svako r in [u, v]
		// naci podelu na segmente gde su ove vrednosti jednake
		// iz svakog segmenta uzeti samo poslednje r
		vector<pair<int, int>> rez;
		rek(u, v, u, v, extend_left(u, v, u), extend_left(u, v, v), rez);
		sort(rez.begin(), rez.end(), [&](auto p, auto q) {
			if (p.first != q.first)
				return p.first < q.first;
			return p.second > q.second;
		});
		int last_l = -1, last_r = -1;
		for (auto [l, r] : rez) {
			if (l >= r)
				continue;
			if (r > last_r && l > last_l) {
				last_r = r;
				last_l = l;
				int t = solve(l, r);
				w[x].ch.push_back(t);
			}
		}
		return id[hh] = x;
	}

	void dfs(int x) {
		if (w[x].dp != -1)
			return;
		w[x].dp = 1;
		for (int y : w[x].ch) {
			dfs(y);
			w[x].dp = max(w[x].dp, w[y].dp + 1);
		}
	}

	main_solver() {
		cin >> n >> s;
		h = hasher(s);
		a = suffix_automaton(s);
		c = fractional_cascading(a.endpos);
		int x = solve(0, n);
		dfs(x);
		cout << w[x].dp << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	main_solver();
}