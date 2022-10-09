// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
int a[200005], l[200005], r[200005];

void kompresuj() {
	vector<int> b(a, a+n);
	sort(begin(b), end(b));
	for (int i=0; i<n; i++)
		a[i] = lower_bound(begin(b), end(b), a[i]) - begin(b);
}

const int maxn = 262144;

struct segtree_max {
	vector<int> a;

	segtree_max() : a(2*maxn, -1) {}

	int get(int l, int r, int node=1, int nl=0, int nr=maxn-1) {
		if (r < nl || nr < l)
			return -1;
		if (l <= nl && nr <= r)
			return a[node];
		int nm = (nl + nr) >> 1;
		return max(get(l, r, 2*node, nl, nm), get(l, r, 2*node+1, nm+1, nr));
	}

	void add(int pos, int val) {
		pos += maxn;
		a[pos] = max(a[pos], val);
		while (pos > 1) {
			pos >>= 1;
			a[pos] = max(a[2*pos], a[2*pos+1]);
		}
	}

	// najvece l takvo da je max[l, r] >= v
	int seek(int r, int v, int x=1, int xl=0, int xr=maxn-1) {
		if (xl > r) {
			// celi smo desno, nema sta da trazimo
			return -1;
		}

		int xm = (xl+xr) >> 1;

		if (xr <= r) {
			// celi upadamo, to je sto je
			if (a[x] < v)
				return -1;
			if (xl == xr)
				return xl;
			if (a[2*x+1] >= v)
				return seek(r, v, 2*x+1, xm+1, xr);
			else
				return seek(r, v, 2*x, xl, xm);
		}

		int w = seek(r, v, 2*x+1, xm+1, xr);
		if (w != -1)
			return w;
		return seek(r, v, 2*x, xl, xm);
	}
};

struct pers_segtree {
	struct node {
		int l, r, v;
		node() : l(-1), r(-1), v(-1) {}
	};
 
	vector<node> a;
	int last;
 
	pers_segtree() : last(-1) {}
 
	int add(int p, int v, int x, int xl, int xr) {
		int x2 = a.size();
		a.emplace_back();
		if (x != -1)
			a[x2] = a[x];
		a[x2].v = max(a[x2].v, v);
		if (xl < xr) {
			int xm = (xl+xr) >> 1;
			if (p <= xm)
				a[x2].l = add(p, v, a[x2].l, xl, xm);
			else
				a[x2].r = add(p, v, a[x2].r, xm+1, xr);
		}
		return x2;
	}
 
	int get(int l, int r, int x, int xl=0, int xr=maxn-1) {
		if (x == -1 || r < xl || xr < l)
			return -1;
		if (l <= xl && xr <= r)
			return a[x].v;
		int xm = (xl+xr) >> 1;
		return max(get(l, r, a[x].l, xl, xm), get(l, r, a[x].r, xm+1, xr));
	}
 
	int add(int p, int v) {
		return last = add(p, v, last, 0, maxn-1);
	}
};

void rv(vector<int>& a, bool rev) {
	if (!rev) return;
	for (int& x : a)
		x = n-1-x;
	reverse(begin(a), end(a));
}

vector<vector<int>> e3[200005], e4[200005];
vector<int> ans[200005];
vector<int> qi[200005];

void dod3(vector<int> a, bool rev) {
	rv(a, rev);
	e3[a.back()].push_back(a);
}

void dod4(vector<int> a, bool rev) {
	rv(a, rev);
	e4[a.back()].push_back(a);
}

void proc3(bool rev) {
	pers_segtree drvo;
	vector<int> stanje(n, -1);
	for (int i=0; i<n; i++) {
		stanje[i] = drvo.last;

		// ok ajde
		{
			int u = drvo.get(0, a[i]-1, stanje[i]);
			int v = drvo.get(a[i]+1, 123123123, stanje[i]);
			if (u >= 0 && v >= 0) {
				dod3({min(u, v), max(u, v), i}, rev);
			}
		}

		// 2 1 2
		int lo = drvo.get(0, a[i]-1, stanje[i]);
		if (lo >= 0) {
			int p = drvo.get(a[i], 123123123, stanje[lo]);
			if (p >= 0) {
				dod3({p, lo, i}, rev);
			}
		}

		// 2 3 2
		lo = drvo.get(a[i]+1, 123123123, stanje[i]);
		if (lo >= 0) {
			int p = drvo.get(0, a[i], stanje[lo]);
			if (p >= 0) {
				dod3({p, lo, i}, rev);
			}
		}

		drvo.add(a[i], i);
	}
}

void proc4(bool rev) {
	segtree_max drvo_pok;
	segtree_max drvo_mali;
	set<pair<int, int>> nepokriveni;
	vector<int> pokrivac(n);
	for (int i=0; i<n; i++) {
		while (nepokriveni.size() && a[i] > nepokriveni.begin()->first) {
			auto [x, y] = *nepokriveni.begin();
			nepokriveni.erase(nepokriveni.begin());
			drvo_pok.add(y, x);
			pokrivac[y] = i;
		}
		nepokriveni.insert({a[i], i});
	
		// seek
		int j = drvo_mali.get(0, a[i]-1);
		if (j >= 0) {
			int k = drvo_pok.seek(j-1, a[i]);
			if (k >= 0) {
				vector<int> v4 = {i, j, k, pokrivac[k]};
				sort(begin(v4), end(v4));
				dod4(v4, rev);
			}
		}

		drvo_mali.add(a[i], i);
	}
}

void proc(bool rev) {
	proc3(rev);
	proc4(rev);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=0; i<n; i++)
		cin >> a[i];
	kompresuj();

	for (int i=0; i<q; i++)
		cin >> l[i] >> r[i], l[i]--, r[i]--, qi[r[i]].push_back(i);

	proc(false);
	reverse(a, a+n);
	proc(true);

	// resi
	vector<int>* p3 = nullptr;
	vector<int>* p4 = nullptr;
	for (int i=0; i<n; i++) {
		// dodaj sve
		for (auto& v : e3[i]) {
			if (!p3 || v[0] > p3->at(0))
				p3 = &v;
		}

		for (auto& v : e4[i]) {
			if (!p4 || v[0] > p4->at(0))
				p4 = &v;
		}

		// resi sve
		for (int j : qi[i]) {
			if (p4 && p4->at(0) >= l[j]) {
				ans[j] = *p4;
			} else if (p3 && p3->at(0) >= l[j]) {
				ans[j] = *p3;
			}
		}
	}

	for (int i=0; i<q; i++) {
		cout << ans[i].size() << '\n';
		for (int x : ans[i])
			cout << x+1 << ' ';
		cout << '\n';
	}
}

// I will still practice daily...