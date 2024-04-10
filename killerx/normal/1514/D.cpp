#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct Node {
	int x, c;

	Node operator + (const Node &oth) const {
		if (x == oth.x) return {x, c + oth.c};
		else return {c >= oth.c ? x : oth.x, std::abs(c - oth.c)};
	}
};

struct SegmentTree {
	static const int mxn = 1 << 19;
	Node t[mxn << 1];

	void build(int n, int a[]) {
		rep(i, n) t[i + mxn] = {a[i], 1};
		for (int i = n; i < mxn; ++ i) t[i + mxn] = {-1, 0};
		for (int i = mxn - 1; i; -- i) t[i] = t[i << 1] + t[i << 1 | 1];
	}

	Node query(int l, int r) {
		Node ansl = {-1, 0}, ansr = {-1, 0};
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ansl = ansl + t[l ++];
			if (r & 1) ansr = t[-- r] + ansr;
		}
		return ansl + ansr;
	}
} seg;

const int mxn = 3e5 + 5;

int n, q;
int a[mxn];
std::vector <int> vec[mxn];

int main() {
	scanf("%d %d", &n, &q);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) vec[a[i]].push_back(i);
	seg.build(n, a);
	while (q --) {
		int l, r; scanf("%d %d", &l, &r); -- l;
		Node s = seg.query(l, r);
		int len = r - l;
		int c = std::lower_bound(vec[s.x].begin(), vec[s.x].end(), r) -
				std::lower_bound(vec[s.x].begin(), vec[s.x].end(), l);
		if (c > (len + 1) / 2) printf("%d\n", c - (len - c));
		else printf("%d\n", 1);
	}
	return 0;
}