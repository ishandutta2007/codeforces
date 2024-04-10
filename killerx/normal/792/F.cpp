#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

using i128 = __int128;

std::ostream &operator << (std::ostream &o, i128 x) {
	if (x < 0) return o << "-" << -x;
	if (x >= 10) o << x / 10;
	return o << char(x % 10 + 48);
}

const i128 linf = i128(1) << 60;

i128 M;

i128 gcd(i128 a, i128 b) {
	return !b ? a : gcd(b, a % b);
}

i128 abs(i128 x) {
	return x >= 0 ? x : -x;
}

struct real {
	i128 a, b;

	real(i128 _a = 0, i128 _b = 1): a(_a), b(_b) { }

	real operator * (const real &oth) const { return real(a * oth.a, b * oth.b); }
	real operator + (const real &oth) const { return real(oth.b * a + b * oth.a, b * oth.b); }
	bool operator < (const real &oth) const { return a * oth.b < oth.a * b; }
};

std::ostream &operator << (std::ostream &o, const real &x) {
	return o << x.a << "/" << x.b;
}

std::mt19937 rng;

struct Node {
	i128 k, b;
	real L, R;
	i128 siz;
	unsigned fix;
	Node *ls, *rs;

	Node(i128 _k, i128 _b): k(_k), b(_b), siz(1), fix(rng()), ls(), rs() {}
};

using node = Node *;

node at(node a, i128 k) {
	i128 lsz = a->ls ? a->ls->siz : 0;
	if (k <= lsz) return at(a->ls, k);
	else if (k == lsz + 1) return a;
	else return at(a->rs, k - lsz - 1);
}

void pushup(node x) {
	x->siz = 1 + (x->ls ? x->ls->siz : 0) + (x->rs ? x->rs->siz : 0);
}

node merge(node a, node b) {
	if (!a || !b) return a ? a : b;
	if (a->fix < b->fix) return a->rs = merge(a->rs, b), pushup(a), a;
	else return b->ls = merge(a, b->ls), pushup(b), b;
}

void split(node x, i128 k, node &a, node &b) {
	if (!x) return a = b = nullptr, void();
	if (x->k < k) a = x, split(x->rs, k, a->rs, b), pushup(a);
	else b = x, split(x->ls, k, a, b->ls), pushup(b);
}

void splitk(node x, i128 k, node &a, node &b) {
	if (!x) return a = b = nullptr, void();
	i128 lsz = x->ls ? x->ls->siz : 0;
	if (lsz + 1 <= k) a = x, splitk(x->rs, k - lsz - 1, a->rs, b), pushup(a);
	else b = x, splitk(x->ls, k, a, b->ls), pushup(b);
}

inline void pop_front(node &x) { node A, B; splitk(x, 1, A, B); delete A; x = B; }
inline void pop_back(node &x) { node A, B; splitk(x, x->siz - 1, A, B); delete B; x = A; }

i128 n;
i128 last;

node root;

template <typename T> inline void read(T &x) {
	x = 0; char c = getchar();
	while (c <= 32) c = getchar();
	while (c > 32) x = x * 10 + c - 48, c = getchar();
}

bool can(node A, node B, node C) {
	return (A->b - B->b) * (C->k - B->k) < (B->b - C->b) * (B->k - A->k);
}

// min ax + by
real traverse(node x, i128 a, i128 b) {
	if (!x) return real(linf);
	if (x->R < real(0)) return traverse(x->rs, a, b);
	real L = x->L, R = x->R;
	if (x->L < real(0)) L = 0;
	real vL = L * a + (L * x->k + x->b) * b;
	real vR = R * a + (R * x->k + x->b) * b;
	if (vL < vR) return std::min(traverse(x->ls, a, b), vL);
	else return std::min(traverse(x->rs, a, b), vR);
}

int main() {
	read(n), read(M);
	last = 0;
	root = new Node(0, 0);
	root->L = -1e6, root->R = 1e6;
	for (i128 tc = 1; tc <= n; ++ tc) {
		i128 tp, a, b;
		read(tp), read(a), read(b);
		a = (a + last) % 1000000 + 1;
		b = (b + last) % 1000000 + 1;
		if (tp == 1) {
			node A, B;
			split(root, -b, A, B);
			node w = new Node(-b, a);
			if (A && B && !can(at(A, A->siz), w, at(B, 1))) {
				delete w;
				root = merge(A, B);
				continue;
			}
			if (B && at(B, 1)->k == -b) {
				if (at(B, 1)->b < a) pop_front(B);
				else {
					root = merge(A, B);
					continue;
				}
			}
			while (A && A->siz >= 2 && !can(at(A, A->siz - 1), at(A, A->siz), w)) pop_back(A);
			while (B && B->siz >= 2 && !can(w, at(B, 1), at(B, 2))) pop_front(B);
			if (A) {
				node L = at(A, A->siz);
				L->R = w->L = real(L->b - w->b, w->k - L->k);
			}
			else w->L = -1e6;
			if (B) {
				node R = at(B, 1);
				R->L = w->R = real(w->b - R->b, R->k - w->k);
			}
			else w->R = 1e6;
			root = merge(merge(A, w), B);
		} else {
			// eprintf("					%d %d\n", a, b);
			real ans = traverse(root, M, a);
			// std::cerr << ans << std::endl;
			if (ans.a >= b * ans.b) puts("YES"), last = tc;
			else puts("NO");
		}
	}
	return 0;
}