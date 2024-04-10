#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1 << 18;

int n, m, q;
std::set <int> su[mxn], sd[mxn];

struct item {
	int ub, db;
	bool res;
} t[mxn << 1];

inline item operator + (item a, item b) {
	item c;
	c.ub = std::max(a.ub, b.ub);
	c.db = std::min(a.db, b.db);
	c.res = a.res & b.res & (a.db > b.ub);
	return c;
}

inline item G(int x) {
	item a;
	a.ub = !su[x].empty() ? *su[x].rbegin() : -1;
	a.db = !sd[x].empty() ? *sd[x].begin() : m;
	a.res = a.ub < a.db;
	return a;
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < mxn; ++ i) t[i + mxn] = G(i);
	for (int i = mxn - 1; i; -- i) t[i] = t[i << 1] + t[i << 1 | 1];
	while (q --) {
		int x, y;
		scanf("%d %d", &x, &y);
		-- x, -- y;
		if (x & 1) {
			if (su[x >> 1].find(y >> 1) == su[x >> 1].end())
				su[x >> 1].insert(y >> 1);
			else
				su[x >> 1].erase(y >> 1);
		} else {
			if (sd[x >> 1].find(y >> 1) == sd[x >> 1].end())
				sd[x >> 1].insert(y >> 1);
			else
				sd[x >> 1].erase(y >> 1);
		}
		int p = x >> 1;
		t[p + mxn] = G(p);
		for (p += mxn; p >>= 1; t[p] = t[p << 1] + t[p << 1 | 1]);
		puts(t[1].res ? "YES" : "NO");
	}
	return 0;
}