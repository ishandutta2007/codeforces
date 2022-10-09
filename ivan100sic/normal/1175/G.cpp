#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct line {
	int k, b;

	line() : k(0), b(1e9) {}

	line(int k, int b) : k(k), b(b) {}

	int operator* (int x) const {
		return k*x+b;
	}

	int presek(line t) {
		int p = t.b - b;
		int q = k - t.k;
		if (p < 0)
			return p/q;
		else
			return (p+q-1) / q;
	}
};

struct lcnode {
	int l, r;
	line v;
};

lcnode b[600005]; int bsz;

int lcnew() {
	b[++bsz] = b[0];
	return bsz;
}

int lcadd(int x, line c, int xl=0, int xr=20000) {
	if (b[x].v*xl <= c*xl && b[x].v*xr <= c*xr)
		return x;
	b[++bsz] = b[x];
	x = bsz;
	if (b[x].v*xl >= c*xl && b[x].v*xr >= c*xr) {
		b[x].v = c;
		return x;
	}

	if (c*xl < b[x].v*xl)
		swap(c, b[x].v);
	int xm = (xl+xr) >> 1;
	b[x].l = lcadd(b[x].l, c, xl, xm);
	b[x].r = lcadd(b[x].r, c, xm+1, xr);
	return x;
}

int lcget(int x, int p, int xl=0, int xr=20000) {
	if (!x) return 1e9;
	int z = b[x].v * p;
	int xm = (xl+xr) >> 1;
	if (p <= xm)
		z = min(z, lcget(b[x].l, p, xl, xm));
	else
		z = min(z, lcget(b[x].r, p, xm+1, xr));
	return z;
}

void lcreset() {
	bsz = 0;
}

int lcroot[20005];

int n, k;
int a[20005];
int dp[105][20005];

struct segment {
	line v;
	int st;
	bool operator< (const segment& b) const {
		if (v.k != b.v.k)
			return v.k > b.v.k;
		return v.b < b.v.b;
	}
};

typedef vector<segment> vse;

void spoji(vse& a, vse& b, vse& d) {
	vse c(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
	for (segment s : c) {
		if (d.size() && d.back().v.k == s.v.k)
			continue;
		while (d.size()) {
			int pr = d.back().v.presek(s.v);
			if (pr <= d.back().st)
				d.pop_back();
			else
				break;
		}
		int pr = 0;
		if (d.size() > 0)
			pr = d.back().v.presek(s.v);
		d.push_back({s.v, pr});
	}
}

const int maxn = 32768;
struct tourn {
	vector<vse> v;
	vector<int> pos;

	tourn() : v(2*maxn), pos(2*maxn, 0) {}

	void add(int x, line l) {
		v[x+maxn] = {{l, 0}};
	}

	void finish() {
		for (int i=maxn-1; i; i--) {
			spoji(v[2*i], v[2*i+1], v[i]);
		}
	}
	
	int seek(int i, int x) {
		if (v[i].size() == 0)
			return 1e9;
		while (pos[i]+1 < (int)v[i].size() && v[i][pos[i]+1].st <= x)
			pos[i]++;
		return v[i][pos[i]].v * x;
	}

	int query(int l, int r, int t, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l)
			return 1e9;
		if (l <= xl && xr <= r)
			return seek(x, t);
		int xm = (xl+xr) >> 1;
		return min(query(l, r, t, 2*x, xl, xm), query(l, r, t, 2*x+1, xm+1, xr));
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	int z = 0;

	dp[1][0] = 1e9;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		z = max(z, a[i]);
		dp[1][i] = z*i;
	}

	for (int i=2; i<=k; i++) {
		dp[i][0] = 1e9;
		lcreset();
		lcroot[0] = lcnew();
		tourn tr;
		for (int j=i; j<=n; j++)
			tr.add(j, line(1-j, dp[i-1][j-1]));
		tr.finish();
		basic_string<int> st;
		for (int j=1; j<=n; j++) {
			int x = a[j];
			while (st.size() && x >= a[st.back()])
				st.pop_back();
			int l = st.size() ? st.back() + 1 : 1;
			st += j;
			int trans = tr.query(l, j, x);
			// cerr << "trans " << l << ' ' << j << ' ' << x << " -> " << trans << '\n';
			// cerr << "imma " << l-1 << ' ' << j << ' ' << x << ' ' << trans << '\n';
			lcroot[j] = lcadd(lcroot[l-1], line(x, trans));
			dp[i][j] = lcget(lcroot[j], j);
		}
	}

	// for (int i=1; i<=k; i++) {
	// 	for (int j=1; j<=n; j++) {
	// 		cerr << dp[i][j] << " \n"[j == n];
	// 	}
	// }

	cout << dp[k][n] << '\n';
}