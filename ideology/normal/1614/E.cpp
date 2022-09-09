#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

using namespace std;

using ll = long long;
using ull = unsigned long long;

// const int P = 1000000007;

// int norm(int x) { return x >= P ? x - P : x; }
// void add(int& x, int y) { if ((x += y) >= P) x -= P; }
// void sub(int& x, int y) { if ((x -= y) < 0) x += P; }

// int mpow(int x, int k) {
// 	if (k == 0) return 1;
// 	int ret = mpow(x * (ull)x % P, k >> 1);
// 	if (k & 1) ret = x * (ull)ret % P;
// 	return ret;
// }

const int _ = 200010, MOD = 1e9 + 1, X = 1e9;

struct Node {
	int l, r, ls, rs, lazy;
} P[_ * 140];

int top;

int create(int l, int r) {
	++top; P[top].l = l; P[top].r = r;
	return top;
}

void upd(int o) {
	P[o].l = P[P[o].ls].l;
	P[o].r = P[P[o].rs].r;
}

void add(int o, int x) {
	P[o].l += x; P[o].r += x; P[o].lazy += x;
}

void pd(int o) {
	if (P[o].lazy) {
		add(P[o].ls, P[o].lazy);
		add(P[o].rs, P[o].lazy);
		P[o].lazy = 0;
	}
}

int loc(int o, int l, int r, int x) {
	if (P[o].l >= x) return l;
	if (x > P[o].r) return r + 1;
	if (P[o].r - P[o].l == r - l) return x + l - P[o].l;
	pd(o);
	int mid = (l + r) / 2;
	return (P[P[o].ls].r >= x) ? loc(P[o].ls, l, mid, x) : loc(P[o].rs, mid + 1, r, x);
}

int roc(int o, int l, int r, int x) {
	if (P[o].r <= x) return r;
	if (x < P[o].l) return l - 1;
	if (P[o].r - P[o].l == r - l) return x + l - P[o].l;
	pd(o);
	int mid = (l + r) / 2;
	return (P[P[o].rs].l <= x) ? roc(P[o].rs, mid + 1, r, x) : roc(P[o].ls, l, mid, x);
}

void add(int o, int l, int r, int ql, int qr, int x) {
	if (l == ql && r == qr) {
		add(o, x); return;
	}
	int mid = (l + r) / 2;
	if (!P[o].ls) {
		P[o].ls = create(l, mid);
		P[o].rs = create(mid + 1, r);
	}
	pd(o);
	if (qr <= mid) add(P[o].ls, l, mid, ql, qr, x);
	else if (ql > mid) add(P[o].rs, mid + 1, r, ql, qr, x);
	else {
		add(P[o].ls, l, mid, ql, mid, x);
		add(P[o].rs, mid + 1, r, mid + 1, qr, x);
	}
	upd(o);
	// cerr << P[o].l << ' ' << P[o].r << " <- " << l << ' ' << r << '\n';
}

int qry(int o, int l, int r, int k) {
	if (l == r) return P[o].l;
	if (r - l == P[o].r - P[o].l) return k - l + P[o].l;
	pd(o);
	int mid = (l + r) / 2;
	return (k <= mid) ? qry(P[o].ls, l, mid, k) : qry(P[o].rs, mid + 1, r, k);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int rt = create(0, X);

	int N; cin >> N;
	int ans = 0;
	while (N--) {
		int T; cin >> T;
		{
			int pL = loc(rt, 0, X, T), pR = roc(rt, 0, X, T);
			// cerr << "EQL " << pL << ' ' << pR << '\n';
			if (pL > 0) add(rt, 0, X, 0, pL - 1, 1);
			if (pR < X) add(rt, 0, X, pR + 1, X, -1);
			// cerr << P[rt].l << " " << P[rt].r << '\n';
		}
		int K; cin >> K;
		while (K--) {
			int x; cin >> x; x = (x + ans) % MOD;
			// cerr << "ASK " << x << '\n';
			cout << (ans = qry(rt, 0, X, x)) << '\n';
		}
	}

	return 0;
}