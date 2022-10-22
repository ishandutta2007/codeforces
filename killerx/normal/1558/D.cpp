#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 4e5 + 5;
const int mod = 998244353;

inline int qpow(int x, int n) {
	int ans = 1;
	for (; n; n >>= 1, x = 1LL * x * x % mod)
		if (n & 1) ans = 1LL * ans * x % mod;
	return ans;
}

namespace FFT {
	int N, r[mxn], w[mxn];

	void init(int n) {
		N = n;
		for (int i = 1; i < n - 1; ++ i) r[i] = r[i >> 1] >> 1 | (i & 1 ? n >> 1 : 0);
		for (int h = 1; h < n; h <<= 1) {
			int temp = qpow(3, (mod - 1) / (h << 1));
			rep(i, h) w[h + i] = i ? 1LL * temp * w[h + i - 1] % mod : 1;
		}
	}

	void fft(int a[], int n, bool flag = false) {
		if (N != n) init(n);
		for (int i = 1; i < n - 1; ++ i) if (i < r[i]) std::swap(a[i], a[r[i]]);
		for (int h = 1; h < n; h <<= 1) {
			for (int i = 0; i < n; i += h << 1) {
				for (int j = 0, *ai = a + i, *aj = a + i + h, *wi = w + h;
						j < h; ++ j, ++ ai, ++ aj, ++ wi) {
					int v = 1LL * *aj * *wi % mod;
					*aj = *ai - v >= 0 ? *ai - v : *ai + mod - v;
					*ai = *ai + v < mod ? *ai + v : *ai + v - mod;
				}
			}
		}
		if (flag) {
			std::reverse(a + 1, a + n);
			int in = qpow(n, mod - 2);
			rep(i, n) a[i] = 1LL * a[i] * in % mod;
		}
	}
} // FFT

struct Poly : std::vector <int> {
	Poly(int n) { clear(); assign(n, 0); }

	Poly(std::initializer_list <int> v) { clear(); for (int x : v) push_back(x); }

	friend Poly operator * (const Poly &a, const Poly &b) {
		Poly c(a.size() + b.size() - 1);
		// if (1LL * a.size() * b.size() <= 64LL * c.size()) {
		if (false) {
			rep(i, a.size()) rep(j, b.size()) c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % mod;
		} else {
			int sz = 1;
			while (sz < c.size()) sz <<= 1;
			static int A[mxn], B[mxn];
			rep(i, sz) A[i] = i < a.size() ? a[i] : 0;
			rep(i, sz) B[i] = i < b.size() ? b[i] : 0;
			FFT::fft(A, sz); FFT::fft(B, sz);
			rep(i, sz) A[i] = 1LL * A[i] * B[i] % mod;
			FFT::fft(A, sz, true);
			rep(i, c.size()) c[i] = A[i];
		}
		return c;
	}
};

int fac[mxn], ifac[mxn];

inline int comb(int n, int m) {
	return m < 0 || m > n ? 0 : 1LL * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

struct INIT {
	INIT() {
		rep(i, mxn) fac[i] = i ? 1LL * i * fac[i - 1] % mod : 1;
		ifac[mxn - 1] = qpow(fac[mxn - 1], mod - 2);
		for (int i = mxn - 1; i; -- i) ifac[i - 1] = 1LL * i * ifac[i] % mod;
	}
} ___;

std::mt19937 rng;

struct Node {
	int l, r;
	int fix;
	int len, sum;
	Node *ls, *rs;

	Node(int _l, int _r) {
		l = _l; r = _r;
		fix = rng();
		len = sum = r - l + 1;
		ls = rs = nullptr;
	}
};

inline void pushup(Node *x) {
	x->sum = x->len + (x->ls ? x->ls->sum : 0) + (x->rs ? x->rs->sum : 0);
}

Node *merge(Node *a, Node *b) {
	if (!a || !b) return a ? a : b;
	if (a->fix < b->fix) return a->rs = merge(a->rs, b), pushup(a), a;
	else return b->ls = merge(a, b->ls), pushup(b), b;
}

void split(Node *x, int k, Node *&a, Node *&b) {
	if (!x) return a = b = nullptr, void();
	int lsz = x->ls ? x->ls->sum : 0;
	if (lsz + x->len <= k) return a = x, split(x->rs, k - lsz - x->len, a->rs, b), pushup(a), void();
	else if (lsz >= k) return b = x, split(x->ls, k, a, b->ls), pushup(b), void();
	else {
		Node *ls = x->ls, *rs = x->rs;
		a = merge(ls, new Node(x->l, x->l + (k - lsz) - 1));
		b = merge(new Node(x->r - (lsz + x->len - k) + 1, x->r), rs);
		delete x;
	}
}

int get_first(Node *x) {
	while (x->ls) x = x->ls;
	return x->l;
}

void traverse(Node *x, std::vector <std::pair <int, int> > &seq) {
	if (!x) return ;
	traverse(x->ls, seq);
	seq.emplace_back(x->l, x->r);
	traverse(x->rs, seq);
}

int pos[mxn];
int jmp[mxn];

struct BIT {
	int vis[mxn], tim;
	int s[mxn];

	void clear() {
		++ tim;
	}

	inline void visit(int x) {
		if (vis[x] != tim) {
			vis[x] = tim;
			s[x] = 0;
		}
	}

	void update(int x, int v) {
		for (++ x; x < mxn; x += x & -x) {
			visit(x);
			s[x] += v;
		}
	}

	int query(int x) {
		int ans = 0;
		for (++ x; x; x -= x & -x) {
			visit(x);
			ans += s[x];
		}
		return ans;
	}
} bit;

Poly conq(std::vector <int> &v, int l, int r) {
	if (l == r) return {1};
	if (l + 1 == r) {
		Poly p(v[l] + 1);
		p[0] = 1;
		p[v[l]] = mod - 1;
		return p;
	}
	int mid = (l + r) >> 1;
	return conq(v, l, mid) * conq(v, mid, r);
}

void Main() {
	int n, m;
	scanf("%d %d", &n, &m);
	Node *rt = new Node(1, 1);
	std::vector <std::pair <int, int> > vsp;
	std::set <int> spec;
	rep(i, m) {
		int x, y;
		scanf("%d %d", &x, &y);
		spec.insert(x);
		vsp.emplace_back(x, y);
		if (rt->sum + 1 < x) {
			rt = merge(rt, new Node(rt->sum + 1, x - 1));
		}
		Node *L, *R;
		split(rt, y - 1, L, R);
		jmp[x] = R ? get_first(R) : -1;
		rt = merge(merge(L, new Node(x, x)), R);
	}
	if (rt->sum + 1 <= n) {
		rt = merge(rt, new Node(rt->sum + 1, n));
	}
	std::vector <std::pair <int, int> > seq;
	traverse(rt, seq);
	/*
	rep(i, seq.size()) eprintf("[%d, %d]", seq[i].first, seq[i].second);
	eprintf("\n");
	*/
	int x = 1;
	rep(i, seq.size()) {
		pos[seq[i].first] = x;
		x += seq[i].second - seq[i].first + 1;
	}
	bit.clear();
	std::map <int, int> ovo;
	std::vector <int> vv;
	for (int i = (int) seq.size() - 1; ~i; -- i) {
		if (spec.find(seq[i].first) != spec.end()) {
			int a = pos[seq[i].first];
			int b = pos[jmp[seq[i].first]];
			if (bit.query(b - 1) - bit.query(a - 1)) continue;
			bit.update(a, 1);
			ovo[b - a] += 1;
			vv.push_back(b - a);
		}
	}
	// for (auto x : ovo) eprintf("%d %d\n", x.first, x.second);
	Poly p = conq(vv, 0, vv.size());
	int ans = 0;
	for (int i = std::max(1, n - (int) p.size() + 1); i <= n; ++ i) {
		ans = (ans + 1LL * p[n - i] * comb(n + i - 1, n - 1)) % mod;
	}
	printf("%d\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while (T --) Main();
	return 0;
}