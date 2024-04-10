#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

typedef long long ll;

const int mxn = 2e5 + 5;
const ll linf = 1LL << 60;

int n, q;

struct Jew {
	int a, v, w, i;

	inline bool operator < (const Jew &oth) const {
		return v != oth.v ? v > oth.v : w < oth.w;
	}
} vjew[mxn];

int rid[mxn];

ll lim[17];
int val[17][mxn];

struct SEG1 {
	static const int mxn = 1 << 18;

	ll sw[mxn << 1], sv[mxn << 1];

	void update(int x, int v) {
		int id = x;
		for (x += mxn; x; x >>= 1) {
			sw[x] += 1LL * v * vjew[id].w;
			sv[x] += 1LL * v * vjew[id].v;
		}
	}

	int query(int x, ll c) {
		ll nww = 0;
		int ox = x;
		for (x += mxn; x > 1; x >>= 1) {
			if (x & 1) {
				if (nww + sw[x] > c) break;
				nww += sw[x];
				++ x;
			}
		}
		if (ox != 0 && x == 1) return mxn;
		while (x < mxn) {
			if (nww + sw[x << 1] <= c) {
				nww += sw[x << 1];
				x = x << 1 | 1;
			} else {
				x = x << 1;
			}
		}
		return x - mxn;
	}

	std::pair <ll, ll> querysum(int l, int r) {
		ll w = 0, v = 0;
		for (l += mxn, r += mxn; l < r; l >>= 1, r >>= 1) {
			if (l & 1) w += sw[l], v += sv[l], ++ l;
			if (r & 1) -- r, w += sw[r], v += sv[r];
		}
		return {w, v};
	}
} seg1[17];

struct SEG2 {
	static const int mxn = 1 << 18;

	ll mn[mxn << 1], tag[mxn << 1];

	SEG2() { memset(mn, 0x3f, sizeof(mn)); memset(tag, 0, sizeof(tag)); }

	inline void push(int x, ll v) { mn[x] += v, tag[x] += v; }

	inline void pushdown(int x) { if (tag[x]) push(x << 1, tag[x]), push(x << 1 | 1, tag[x]), tag[x] = 0; }

	inline void pushup(int x) { mn[x] = std::min(mn[x << 1], mn[x << 1 | 1]); }

	void update(int l, int r, ll v) {
		l += mxn, r += mxn;
		for (int i = 18; i; -- i) {
			if (((l >> i) << i) != l) pushdown(l >> i);
			if (((r >> i) << i) != r) pushdown(r >> i);
		}
		int l0 = l, r0 = r;
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) push(l ++, v);
			if (r & 1) push(-- r, v);
		}
		for (int i = 1; i <= 18; ++ i) {
			if (((l0 >> i) << i) != l0) pushup(l0 >> i);
			if (((r0 >> i) << i) != r0) pushup(r0 >> i);
		}
	}

	int query(int x, ll c) {
		int ox = x;
		x += mxn;
		for (int i = 18; i; -- i) pushdown(x >> i);
		for (; x > 1; x >>= 1) {
			if (x & 1) {
				if (mn[x] <= c) break;
				++ x;
			}
		}
		if (ox != 0 && x == 1) return -1;
		if (mn[x] > c) return -1;
		for (; x < mxn; ) {
			pushdown(x);
			if (mn[x << 1] <= c) {
				x = x << 1;
			} else {
				x = x << 1 | 1;
			}
		}
		return x - mxn;
	}

	void set(int x, ll v) {
		x += mxn;
		for (int i = 18; i; -- i) pushdown(x >> i);
		mn[x] = v;
		for (int i = 1; i <= 18; ++ i) pushup(x >> i);
	}
} seg2[17];

void init(int n) {
}

void update(int x, int v) {
	rep(lv, 17) if (vjew[x].w < lim[lv]) {
		val[lv][x] += v;
		seg1[lv].update(x, v);
		if (lv) seg2[lv - 1].update(x + 1, mxn, 1LL * v * vjew[x].w);
		if (lv + 1 < 17 && vjew[x].w >= lim[lv + 1]) {
			if (!val[lv][x]) seg2[lv].set(x, linf);
			else seg2[lv].set(x, vjew[x].w + seg1[lv + 1].querysum(0, x).first);
		}
	}
}

ll query(int lv, int p, ll c) {
	if (lv == 17 || p >= n || c == 0) return 0;
	int np = std::min(n, seg1[lv].query(p, c));
	int op = p;
	int mp = lv ? seg2[lv - 1].query(p, c + seg1[lv].querysum(0, p).first) : -1;
	if (mp != -1) {
		c -= seg1[lv].querysum(p, mp).first + vjew[mp].w;
		return seg1[lv].querysum(op, mp).second + vjew[mp].v + query(lv + 1, mp + 1, c);
	}
	ll ans = 0;
	std::pair <ll, ll> pr = seg1[lv].querysum(op, np);
	ans += pr.second;
	c -= pr.first;
	if (np < n) {
		ll x = c / vjew[np].w;
		ans += x * vjew[np].v;
		c -= x * vjew[np].w;
		++ p;
	}
	return ans + query(lv + 1, np, c);
}

int main() {
	rep(i, 17) lim[i] = 1LL << (17 - i);
	scanf("%d %d", &n, &q);
	rep(i, n) scanf("%d %d %d", &vjew[i].a, &vjew[i].w, &vjew[i].v), vjew[i].i = i;
	std::sort(vjew, vjew + n);
	rep(i, n) rid[vjew[i].i] = i;
	init(n);
	rep(i, n) update(i, +vjew[i].a);
	while (q --) {
		int tp;
		scanf("%d", &tp);
		if (tp == 1) {
			int v, x;
			scanf("%d %d", &v, &x);
			x = rid[-- x];
			vjew[x].a += v;
			update(x, +v);
		} else if (tp == 2) {
			int v, x;
			scanf("%d %d", &v, &x);
			x = rid[-- x];
			vjew[x].a -= v;
			update(x, -v);
		} else if (tp == 3) {
			ll c;
			scanf("%lld", &c);
			printf("%lld\n", query(0, 0, c));
		}
	}
	return 0;
}