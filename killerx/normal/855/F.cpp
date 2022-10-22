#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long i64;

const int lg = 17;
const int mxn = 1 << lg;

struct SegmentTree {
	int tagmx[mxn << 1], tag[mxn << 1];
	i64 sum[mxn << 1];
	int sz[mxn << 1], mx[mxn << 1], mxcnt[mxn << 1], se[mxn << 1];

	SegmentTree() {
		memset(tagmx, 0, sizeof(tagmx));
		memset(tag, 0, sizeof(tag));
		memset(sum, 0, sizeof(sum));
		memset(sz, 0, sizeof(sz));
		memset(mx, 0, sizeof(mx));
		memset(mxcnt, 0, sizeof(mxcnt));
		memset(se, 0, sizeof(se));
	}

	void push(int x, int vmx, int v) {
		tagmx[x] += vmx;
		tag[x] += v;
		sum[x] += 1LL * sz[x] * v + 1LL * mxcnt[x] * vmx;
		mx[x] += v + vmx;
		se[x] += v;
	}

	void pushdown(int x) {
		if (tagmx[x] || tag[x]) {
			push(x << 1, mx[x << 1] + tagmx[x] + tag[x] == mx[x] ? tagmx[x] : 0, tag[x]);
			push(x << 1 | 1, mx[x << 1 | 1] + tagmx[x] + tag[x] == mx[x] ? tagmx[x] : 0, tag[x]);
			tagmx[x] = tag[x] = 0;
		}
	}

	void pushup(int x) {
		sz[x] = sz[x << 1] + sz[x << 1 | 1];
		sum[x] = sum[x << 1] + sum[x << 1 | 1];
		mx[x] = std::max(mx[x << 1], mx[x << 1 | 1]);
		mxcnt[x] = 0;
		if (mx[x << 1] == mx[x]) mxcnt[x] += mxcnt[x << 1];
		if (mx[x << 1 | 1] == mx[x]) mxcnt[x] += mxcnt[x << 1 | 1];
		se[x] = std::max(se[x << 1], se[x << 1 | 1]);
		if (mx[x << 1] < mx[x]) se[x] = std::max(se[x], mx[x << 1]);
		if (mx[x << 1 | 1] < mx[x]) se[x] = std::max(se[x], mx[x << 1 | 1]);
	}

	void enable(int x, int v) {
		x += mxn;
		for (int i = lg; i; -- i) pushdown(x >> i);
		sz[x] = 1;
		mxcnt[x] = 1;
		mx[x] = v; 
		sum[x] = v;
		se[x] = 0;
		for (int i = 1; i <= lg; ++ i) pushup(x >> i);
	}

	int get(int x) {
		x += mxn;
		for (int i = lg; i; -- i) pushdown(x >> i);
		return sum[x];
	}

	void update(int l, int r, int v, int i = 1, int a = 0, int b = mxn) {
		if (l <= a && b <= r) {
			if (v > mx[i]) return ;
			if (v > se[i]) return push(i, v - mx[i], 0);
		}
		if (r <= a || b <= l) return ;
		pushdown(i);
		int m = (a + b) >> 1;
		update(l, r, v, i << 1, a, m);
		update(l, r, v, i << 1 | 1, m, b);
		pushup(i);
	}

	i64 query(int l, int r, int i = 1, int a = 0, int b = mxn) {
		if (l <= a && b <= r) return sum[i];
		if (r <= a || b <= l) return 0;
		pushdown(i);
		int m = (a + b) >> 1;
		return query(l, r, i << 1, a, m) + query(l, r, i << 1 | 1, m, b);
	}
} segu, segd, seguans, segdans;

std::set <int> setu, setd;
int flg[mxn];

void qwq(int x) {
	++ flg[x];
	if (flg[x] == 2) {
		seguans.enable(x, segu.get(x));
		segdans.enable(x, segd.get(x));
	}
}

void doit(std::set <int> &st, int l, int r) {
	std::set <int>::iterator it = st.lower_bound(l);
	while (it != st.end() && *it < r) {
		qwq(*it);
		it = st.erase(it);
	}
}

int main() {
	rep(i, mxn) {
		setu.insert(i);
		setd.insert(i);
		segu.enable(i, 0x3f3f3f3f);
		segd.enable(i, 0x3f3f3f3f);
	}
	int q; scanf("%d", &q);
	while (q --) {
		int tp; scanf("%d", &tp);
		if (tp == 1) {
			int l, r, k; scanf("%d %d %d", &l, &r, &k);
			(k > 0 ? segu : segd).update(l, r, k > 0 ? k : -k);
			doit(k > 0 ? setu : setd, l, r);
			(k > 0 ? seguans : segdans).update(l, r, k > 0 ? k : -k);
		} else {
			int l, r; scanf("%d %d", &l, &r);
			printf("%lld\n", seguans.query(l, r) + segdans.query(l, r));
		}
	}
	return 0;
}