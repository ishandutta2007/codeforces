#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i64 = long long;
const int inf = 1e9 + 7;
const i64 linf = 1e18 + 7;

const int mxsz = 1 << 23;

inline char get_char() {
	static char ibuf[mxsz], *iend = ibuf + mxsz, *ipos = iend;
	if (ipos == iend) iend = (ipos = ibuf) + fread(ibuf, 1, mxsz, stdin);
	return *ipos ++;
}

inline void read(int &x) {
	x = 0; char c = get_char();
	while (!isdigit(c)) c = get_char();
	while (isdigit(c)) x = x * 10 + c - 48, c = get_char();
}

inline void read(char *s) {
	while (isspace(*s = get_char()));
	while (!isspace(*++ s = get_char()));
	*s = 0;
}

inline void write(i64 x) {
	if (x >= 10) write(x / 10);
	putchar(x % 10 + 48);
}

const int mxn = 1 << 19, mxlg = 19;
const bool B = 0, R = 1;

struct segment_tree_count {
	struct item {
		int a0, a1;
	};

	bool tag[mxn << 1];
	item sum[mxn << 1];

	inline void push(int x) {
		tag[x] ^= 1;
		std::swap(sum[x].a0, sum[x].a1);
	}

	inline void pushdown(int x) {
		if (tag[x]) {
			push(x << 1);
			push(x << 1 | 1);
			tag[x] = 0;
		}
	}

	inline void pushup(int x) {
		sum[x].a0 = sum[x << 1].a0 + sum[x << 1 | 1].a0;
		sum[x].a1 = sum[x << 1].a1 + sum[x << 1 | 1].a1;
	}

	inline void init(int n, char s[]) {
		memset(tag, 0, sizeof(tag));
		rep(i, mxn) sum[i + mxn].a0 = sum[i + mxn].a1 = 0;
		rep(i, n) sum[i + mxn].a0 = s[i] == 'B', sum[i + mxn].a1 = s[i] == 'R';
		for (int i = mxn - 1; i; -- i) pushup(i);
	}

	inline void update(int l, int r) {
		l += mxn, r += mxn;
		for (int i = mxlg; i; -- i) {
			if (((l >> i) << i) != l) pushdown(l >> i);
			if (((r >> i) << i) != r) pushdown(r >> i);
		}
		int l0 = l, r0 = r;
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) push(l ++);
			if (r & 1) push(-- r);
		}
		for (int i = 1; i <= mxlg; ++ i) {
			if (((l0 >> i) << i) != l0) pushup(l0 >> i);
			if (((r0 >> i) << i) != r0) pushup(r0 >> i);
		}
	}

	inline int get(int x) {
		x += mxn;
		for (int i = mxlg; i; -- i) pushdown(x >> i);
		return sum[x].a0 ? 0 : 1;
	}
} LF, RG, UP, DN;

struct trans {
	int a00, a01, a10, a11;

	trans(): a00(), a01(inf), a10(inf), a11() {}
	trans(int _a00, int _a01, int _a10, int _a11):
		a00(_a00), a01(_a01), a10(_a10), a11(_a11) {}

	trans operator * (const trans &oth) const {
		return trans(
			std::min(a00 + oth.a00, a01 + oth.a10),
			std::min(a00 + oth.a01, a01 + oth.a11),
			std::min(a10 + oth.a00, a11 + oth.a10),
			std::min(a10 + oth.a01, a11 + oth.a11)
		);
	}

	friend inline trans rev(trans x) {
		trans y(x.a11, x.a10, x.a01, x.a00);
		return y;
	}
};

struct segment_tree_ans {
	struct node {
		trans t00, t01;

		node(): t00(), t01() {}
		node(const trans &_t00, const trans &_t01):
			t00(_t00), t01(_t01) {}
	} t[mxn << 1];
	bool tagl[mxn << 1], tagr[mxn << 1];

	inline void pushl(int x) {
		tagl[x] ^= 1;
		trans t00 = rev(t[x].t01);
		trans t01 = rev(t[x].t00);
		t[x] = node(t00, t01);
	}

	inline void pushr(int x) {
		tagr[x] ^= 1;
		std::swap(t[x].t00, t[x].t01);
	}

	inline void pushdown(int x) {
		if (tagl[x]) {
			pushl(x << 1);
			pushl(x << 1 | 1);
			tagl[x] = 0;
		}
		if (tagr[x]) {
			pushr(x << 1);
			pushr(x << 1 | 1);
			tagr[x] = 0;
		}
	}

	inline void pushup(int x) {
		t[x].t00 = t[x << 1].t00 * t[x << 1 | 1].t00;
		t[x].t01 = t[x << 1].t01 * t[x << 1 | 1].t01;
	}

	inline void init(int n, int m, char sl[], char sr[]) {
		memset(tagl, 0, sizeof(tagl));
		memset(tagr, 0, sizeof(tagr));
		rep(i, mxn) t[i + mxn] = node();
		rep(i, n) if (i) {
			static trans a[2][2];
			rep(fl, 2) rep(fr, 2) {
				int cl = (sl[i] == 'B' ? B : R) ^ fl;
				int cr = (sr[i] == 'B' ? B : R) ^ fr;
				a[fl][fr] = trans(0, 0, 0, 0);
				a[fl][fr].a01 += m;
				a[fl][fr].a10 += m;
				a[fl][fr].a00 += (cl != 0) + (cr != 0);
				a[fl][fr].a10 += (cl != 0) + (cr != 0);
				a[fl][fr].a01 += (cl != 1) + (cr != 1);
				a[fl][fr].a11 += (cl != 1) + (cr != 1);
			}
			t[i + mxn].t00 = a[0][0];
			t[i + mxn].t01 = a[0][1];
		}
		for (int i = mxn - 1; i; -- i) pushup(i);
	}

	inline void updatel(int l, int r) {
		l += mxn, r += mxn;
		for (int i = mxlg; i; -- i) {
			if (((l >> i) << i) != l) pushdown(l >> i);
			if (((r >> i) << i) != r) pushdown(r >> i);
		}
		int l0 = l, r0 = r;
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) pushl(l ++);
			if (r & 1) pushl(-- r);
		}
		for (int i = 1; i <= mxlg; ++ i) {
			if (((l0 >> i) << i) != l0) pushup(l0 >> i);
			if (((r0 >> i) << i) != r0) pushup(r0 >> i);
		}
	}

	inline void updater(int l, int r) {
		l += mxn, r += mxn;
		for (int i = mxlg; i; -- i) {
			if (((l >> i) << i) != l) pushdown(l >> i);
			if (((r >> i) << i) != r) pushdown(r >> i);
		}
		int l0 = l, r0 = r;
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) pushr(l ++);
			if (r & 1) pushr(-- r);
		}
		for (int i = 1; i <= mxlg; ++ i) {
			if (((l0 >> i) << i) != l0) pushup(l0 >> i);
			if (((r0 >> i) << i) != r0) pushup(r0 >> i);
		}
	}
} LR, UD;

int n, m, q;
char lf[mxn], rg[mxn], up[mxn], dn[mxn];

inline i64 query_lr() {
	i64 a[2][2];
	a[0][0] = LR.t[1].t00.a00;
	a[0][1] = LR.t[1].t00.a01;
	a[1][0] = LR.t[1].t00.a10;
	a[1][1] = LR.t[1].t00.a11;
	i64 ans = linf;
	rep(cl, 2) rep(cr, 2) {
		i64 cur = a[cl][cr];
		cl ? cur += UP.sum[1].a0 : cur += UP.sum[1].a1;
		cr ? cur += DN.sum[1].a0 : cur += DN.sum[1].a1;
		cur += LF.get(0) != cl;
		cur += RG.get(0) != cl;
		ans = std::min(ans, cur);
	}
	return ans;
}

inline i64 query_ud() {
	i64 a[2][2];
	a[0][0] = UD.t[1].t00.a00;
	a[0][1] = UD.t[1].t00.a01;
	a[1][0] = UD.t[1].t00.a10;
	a[1][1] = UD.t[1].t00.a11;
	i64 ans = linf;
	rep(cu, 2) rep(cd, 2) {
		i64 cur = a[cu][cd];
		cu ? cur += LF.sum[1].a0 : cur += LF.sum[1].a1;
		cd ? cur += RG.sum[1].a0 : cur += RG.sum[1].a1;
		cur += UP.get(0) != cu;
		cur += DN.get(0) != cu;
		ans = std::min(ans, cur);
	}
	return ans;
}

inline i64 query() {
	return std::min(query_lr(), query_ud());
}

int main() {
	read(n), read(m), read(q);
	read(lf), read(rg), read(up), read(dn);
	LF.init(n, lf);
	RG.init(n, rg);
	UP.init(m, up);
	DN.init(m, dn);
	LR.init(n, m, lf, rg);
	UD.init(m, n, up, dn);
	write(query()); putchar(10);
	while (q --) {
		char tp[5]; int l, r;
		read(tp), read(l), read(r);
		-- l;
		if (tp[0] == 'L') LF.update(l, r), LR.updatel(l, r);
		if (tp[0] == 'R') RG.update(l, r), LR.updater(l, r);
		if (tp[0] == 'U') UP.update(l, r), UD.updatel(l, r);
		if (tp[0] == 'D') DN.update(l, r), UD.updater(l, r);
		write(query()); putchar(10);
	}
	return 0;
}