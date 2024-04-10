#include <bits/stdc++.h>

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

char ibuf[1 << 25], *ipos = ibuf;
char obuf[1 << 25], *opos = obuf;

char get_char() { return *ipos ++; }
void put_char(char c) { *opos ++ = c; }

int get_int() {
	int x = 0, c = get_char();
	while (c <= 32) c = get_char();
	while (c > 32) x = x * 10 + c - '0', c = get_char();
	return x;
}

void put_int(long long x) {
	if (x < 0) put_char('-'), x *= -1;
	if (x >= 10) put_int(x / 10);
	put_char(x % 10 + '0');
}

void put_int_ln(long long x) {
	put_int(x);
	put_char('\n');
}

typedef long long ll;

const int lg = 21;
const int mxn = 1 << lg;

struct SegmentTree {
	int tagk[mxn << 1];
	int maxk[mxn << 1];
	ll tagb[mxn << 1];
	ll maxb[mxn << 1];

	SegmentTree() {
		memset(tagk, 0, sizeof(tagk));
		memset(maxk, 0, sizeof(maxk));
		memset(tagb, 0, sizeof(tagb));
		memset(maxb, 0, sizeof(maxb));
	}

	void push(int x, int k, ll b) {
		tagk[x] += k;
		maxk[x] += k;
		tagb[x] += b;
		maxb[x] += b;
	}

	void pushdown(int x) {
		push(x << 1, tagk[x], tagb[x]);
		push(x << 1 | 1, tagk[x], tagb[x]);
		tagk[x] = tagb[x] = 0;
	}

	void pushup(int x) {
		maxk[x] = std::max(maxk[x << 1], maxk[x << 1 | 1]);
		maxb[x] = std::max(maxb[x << 1], maxb[x << 1 | 1]);
	}

	void update(int l, int r, int k, ll b) {
		l += mxn, r += mxn;
		for (int i = lg; i; -- i) {
			if (((l >> i) << i) != l) pushdown(l >> i);
			if (((r >> i) << i) != r) pushdown(r >> i);
		}
		int l0 = l, r0 = r;
		for (; l < r; l >>= 1, r >>= 1) {
			if (l & 1) push(l ++, k, b);
			if (r & 1) push(-- r, k, b);
		}
		for (int i = 1; i <= lg; ++ i) {
			if (((l0 >> i) << i) != l0) pushup(l0 >> i);
			if (((r0 >> i) << i) != r0) pushup(r0 >> i);
		}
	}

	void get(int x, int &k, ll &b) {
		x += mxn;
		for (int i = lg; i; -- i)
			pushdown(x >> i);
		k = maxk[x];
		b = maxb[x];
	}

	int bsearch(int v) {
		int x = 1;
		while (x < mxn) {
			pushdown(x);
			if (maxk[x << 1 | 1] >= v)
				x = x << 1 | 1;
			else
				x = x << 1;
		}
		return x - mxn;
	}
} F, G;

const int S = 1 << (lg - 1);
const int bound = 1;

int n, m;
int q;
int va[mxn], vb[mxn];
ll sa, sb;
std::multiset <int> sta, stb;
std::multiset <int> st;

int getz() {
	return *st.begin();
}

int main() {
	fread(ibuf, 1, 1 << 25, stdin);
	n = get_int();
	m = get_int();
	q = get_int();
	rep(i, n) {
		int x = get_int();
		va[i] = x;
		sa += x;
		sta.insert(x);
		st.insert(x);
	}
	rep(i, m) {
		int x = get_int();
		vb[i] = x;
		sb += x;
		stb.insert(x);
		st.insert(x);
	}
	F.update(getz() + S, mxn, n - 1, -ll(n - 1) * getz());
	rep(i, m) F.update(vb[i] + S, mxn, -1, vb[i]);
	G.update(getz() + S, mxn, n, -ll(n) * getz());
	rep(i, m) G.update(vb[i] + S, mxn, -1, vb[i]);
	while (q --) {
		int op = get_int();
		if (op == 1) {
			int p = get_int() - 1, x = get_int();
			F.update(getz() + S, mxn, -(n - 1), ll(n - 1) * getz());
			G.update(getz() + S, mxn, -n, ll(n) * getz());
			st.erase(st.find(va[p]));
			sta.erase(sta.find(va[p]));
			sa -= va[p];
			va[p] = x;
			sa += va[p];
			sta.insert(va[p]);
			st.insert(va[p]);
			G.update(getz() + S, mxn, n, -ll(n) * getz());
			F.update(getz() + S, mxn, n - 1, -ll(n - 1) * getz());
		}
		if (op == 2) {
			int p = get_int() - 1, x = get_int();
			F.update(vb[p] + S, mxn, 1, -vb[p]);
			F.update(getz() + S, mxn, -(n - 1), ll(n - 1) * getz());
			G.update(vb[p] + S, mxn, 1, -vb[p]);
			G.update(getz() + S, mxn, -n, ll(n) * getz());
			st.erase(st.find(vb[p]));
			stb.erase(stb.find(vb[p]));
			sb -= vb[p];
			vb[p] = x;
			sb += vb[p];
			stb.insert(vb[p]);
			st.insert(vb[p]);
			G.update(getz() + S, mxn, n, -ll(n) * getz());
			G.update(vb[p] + S, mxn, -1, vb[p]);
			F.update(getz() + S, mxn, n - 1, -ll(n - 1) * getz());
			F.update(vb[p] + S, mxn, -1, vb[p]);
		}
		if (op == 3) {
			int bas = get_int();
			ll ans = -0x3f3f3f3f3f3f3f3f;
			int p;
			std::multiset <int>::iterator it;
			p = F.bsearch(n - m) - S + bas;
			it = sta.lower_bound(p);
			rep(iter, bound) {
				if (it != sta.begin()) -- it;
			}
			rep(iter, bound * 2) {
				if (it == sta.end()) break;
				int k; ll b;
				F.get(*it - bas + S, k, b);
				ll cur = ll(*it - bas) * (k + (m - n)) + b + (sa - sb);
				ans = std::max(ans, cur);
				++ it;
			}
			it = sta.begin();
			int k; ll b;
			F.get(*it - bas + S, k, b);
			ll cur = ll(*it - bas) * (k + (m - n)) + b + (sa - sb);
			ans = std::max(ans, cur);
			it = -- sta.end();
			F.get(*it - bas + S, k, b);
			cur = ll(*it - bas) * (k + (m - n)) + b + (sa - sb);
			ans = std::max(ans, cur);
			p = G.bsearch(n - m) - S + bas;
			it = stb.lower_bound(p);
			rep(iter, bound) {
				if (it != stb.begin()) -- it;
			}
			rep(iter, bound * 2) {
				if (it == stb.end()) break;
				int k; ll b;
				G.get(*it - bas + S, k, b);
				ll cur = ll(*it - bas) * (k + (m - n)) + b + (sa - sb);
				ans = std::max(ans, cur);
				++ it;
			}
			it = stb.begin();
			G.get(*it - bas + S, k, b);
			cur = ll(*it - bas) * (k + (m - n)) + b + (sa - sb);
			ans = std::max(ans, cur);
			it = -- stb.end();
			G.get(*it - bas + S, k, b);
			cur = ll(*it - bas) * (k + (m - n)) + b + (sa - sb);
			ans = std::max(ans, cur);
			put_int_ln(ans);
		}
	}
	fwrite(obuf, 1, opos - obuf, stdout);
	return 0;
}

// F(t) = sum a - sum b + (m - n) t + (n - 1) max(0, t - z) - sum max(0, t - b[i])
// G(t) = sum a - sum b + (m - n) t + n max(0, t - z) - sum max(0, t - b[i])