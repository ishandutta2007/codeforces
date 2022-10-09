#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const unsigned mod = 3853518419u;
const unsigned base = 85429482u;

int n;
string s;
basic_string<int> e[300005];
int p[19][300005], du[300005];
unsigned bp[300005];
unsigned hu[19][300005], hd[19][300005];

void dfs(int x, int par) {
	p[0][x] = par;
	hu[0][x] = hd[0][x] = s[x];
	for (int i=1; i<19; i++) {
		int y = p[i-1][x];
		p[i][x] = p[i-1][y];
		hu[i][x] = (1ull * hu[i-1][x] * bp[1 << (i-1)] + hu[i-1][y]) % mod;
		hd[i][x] = (1ull * hd[i-1][y] * bp[1 << (i-1)] + hd[i-1][x]) % mod;
	}
	for (int y : e[x]) {
		if (y != par) {
			du[y] = du[x] + 1;
			dfs(y, x);
		}
	}
}

int dizi(int x, int k) {
	for (int i=0; i<19; i++) {
		if ((1 << i) & k) {
			x = p[i][x];
		}
	}
	return x;
}

int lca(int x, int y) {
	if (du[x] > du[y])
		swap(x, y);
	y = dizi(y, du[y] - du[x]);
	if (x == y)
		return x;
	for (int i=18; i>=0; i--) {
		int xx = p[i][x], yy = p[i][y];
		if (xx != yy) {
			x = xx;
			y = yy;
		}
	}
	return p[0][x];
}

int resi(int a, int b, int c, int d) {
	int p = lca(a, b), q = lca(c, d), l = 0;
	// prvi korak, penjemo se na gore
	int h = min(du[a] - du[p], du[c] - du[q]);
	for (int i=18; i>=0; i--) {
		if ((1 << i) <= h) {
			if (hu[i][a] == hu[i][c]) {
				l += 1 << i;
				h -= 1 << i;
				a = ::p[i][a];
				c = ::p[i][c];
			}
		}
	}
	if (h > 0)
		return l;

	// h=0 pa je a=p ili c=q

	if (a != p) {
		swap(a, c);
		swap(b, d);
		swap(p, q);
	}

	// sad je a = p, idemo u razlicitim smerovima sve
	// dok i drugi ne udari u svoj lca ili se ovaj spusti do kraja
	h = min(du[c] - du[q], du[b] - du[p]);
	for (int i=18; i>=0; i--) {
		if ((1 << i) <= h) {
			int t = dizi(b, du[b] - du[p] - (1 << i));
			if (hu[i][::p[0][t]] == hd[i][c]) {
				l += 1 << i;
				h -= 1 << i;
				p = t;
				c = ::p[i][c];
			}
		}
	}

	if (h > 0)
		return l;

	// istrosio sam a-b put
	if (b == p)
		return l + (s[p] == s[c]);

	// nisam istrosio put ali zato onaj lca jesam
	h = min(du[d] - du[q], du[b] - du[p]);
	for (int i=18; i>=0; i--) {
		if ((1 << i) <= h) {
			int t1 = dizi(b, du[b] - du[p] - (1 << i));
			int t2 = dizi(d, du[d] - du[q] - (1 << i));
			if (hu[i][::p[0][t1]] == hu[i][::p[0][t2]]) {
				l += 1 << i;
				h -= 1 << i;
				p = t1;
				q = t2;
			}
		}
	}

	if (h > 0)
		return l;

	return l + (s[p] == s[q]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	s = string(" ") + s;
	for (int i=0; i<n-1; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	bp[0] = 1;
	for (int i=1; i<300005; i++)
		bp[i] = bp[i-1] * 1ull * base % mod;
	dfs(1, 1);

	int q;
	cin >> q;
	while (q--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << resi(a, b, c, d) << '\n';
	}
}