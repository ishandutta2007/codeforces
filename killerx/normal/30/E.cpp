#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < int(n); ++ i)

const int mxn = 1e5 + 5;
const int sz = 1 << 17;
int n;
char s[mxn], t[mxn << 1];
int z[mxn << 1];
int m[sz];
int suflen[mxn];
pair <int, int> mx[sz << 1];

void Z(char *s, int *z) {
	int n = strlen(s);
	int L = 0, R = 0;
	rep(i, n) if (i) {
		if (i <= R) z[i] = min(z[i - L], R - i + 1);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++ z[i];
		if (i + z[i] - 1 > R) L = i, R = i + z[i] - 1;
	}
}

void M(char *s, int *m) {
	int n = strlen(s);
	int L = 0, R = 0;
	rep(i, n) if (i) {
		if (i <= R) m[i] = min(m[L + (R - i)], R - i);
		while (i - m[i] - 1 >= 0 && i + m[i] + 1 < n && s[i - m[i] - 1] == s[i + m[i] + 1]) ++ m[i];
		if (i + m[i] > R) L = i - m[i], R = i + m[i];
	}
}

void build(int *m) {
	rep(i, sz) mx[i + sz] = mp(m[i], i);
	for (int i = sz - 1; i; -- i) mx[i] = max(mx[i << 1], mx[i << 1 | 1]);
}

pair <int, int> qry(int l, int r) {
	pair <int, int> ans;
	for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
		if (l & 1) ans = max(ans, mx[l ++]);
		if (r & 1) ans = max(ans, mx[-- r]);
	}
	return ans;
}

pair <int, pair <int, int> > solve(int l, int r) {
	if (l > r) return mp(0, mp(0, 0));
	int lb = 0, rb = (r - l + 1) / 2;
	while (lb < rb) {
		int md = (lb + rb + 1) >> 1;
		if (l + md <= r - md && qry(l + md, r - md + 1).first >= md) lb = md;
		else rb = md - 1;
	}
	pair <int, int> pr = qry(l + lb, r - lb + 1);
	return mp(lb * 2 + 1, mp(pr.second - lb, lb * 2 + 1));
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	int c = 0;
	for (int i = n - 1; ~i; -- i) t[c ++] = s[i];
	rep(i, n) t[c ++] = s[i];
	Z(t, z);
	rep(i, n) suflen[i] = max(i ? suflen[i - 1] : 0, z[i + n]);
	M(s, m);
	build(m);
	pair <int, vector <pair <int, int> > > ans;
	for (int l = 0; l * 2 <= n; ++ l) {
		int p = lower_bound(suflen, suflen + n, l) - suflen;
		if (p + l > n - l) break;
		int len = 2 * l;
		vector <pair <int, int> > v;
		if (l) v.pb(mp(p, l));
		int L = p + l;
		int R = n - l - 1;
		pair <int, pair <int, int> > pr = solve(L, R);
		if (pr.first) v.pb(pr.second), len += pr.first;
		else continue;
		if (l) v.pb(mp(n - l, l));
		ans = max(ans, mp(len, v));
	}
	printf("%d\n", (int) ans.second.size());
	rep(i, ans.second.size()) printf("%d %d\n", ans.second[i].first + 1, ans.second[i].second);
	return 0;
}