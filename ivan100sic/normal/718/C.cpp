#include <iostream>
using namespace std;

const int mod = 1000000007;
const int MAXN = 131072;

struct mat2 {
	long long a, b;

	mat2(long long a = 0, long long b = 0) : a(a), b(b) {}

	mat2 operator+ (const mat2& x) const {
		mat2 tmp;
		tmp.a = (a + x.a) % mod;
		tmp.b = (b + x.b) % mod;
		return tmp;
	}

	mat2 operator* (const mat2& x) const {
		mat2 tmp;

		tmp.a = (a * x.a + b * x.b) % mod;
		tmp.b = (a * x.b + b * (x.a + x.b)) % mod;

		return tmp;
	}
};

mat2 zero() {
	return mat2(0, 0);
}

mat2 unit() {
	return mat2(1, 0);
}

mat2 fib() {
	return mat2(0, 1);
}

template<class T>
T raise(T val, int n) {
	if (n == 1) return val;
	T sq = raise(val, n / 2);
	sq = sq * sq;
	if (n & 1) sq = sq * val;
	return sq;
}

mat2 A[2 * MAXN], P[2 * MAXN];
int N, M;

void read() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		A[i + MAXN - 1] = raise(fib(), x);
	}
	for (int i = MAXN - 1; i; i--) {
		A[i] = A[2 * i] + A[2 * i + 1];
	}
	for (int i = 1; i<2 * MAXN; i++) P[i] = unit();
}

void push_down(int node) {
	A[node] = A[node] * P[node];
	if (node < MAXN) {
		P[2 * node] = P[2 * node] * P[node];
		P[2 * node + 1] = P[2 * node + 1] * P[node];
	}
	P[node] = unit();
}

void update(int l, int r, int nl, int nr, int node, mat2 v) {
	push_down(node);

	if (r < nl || nr < l) return;
	if (l <= nl && nr <= r) {
		P[node] = P[node] * v;
		push_down(node);
		return;
	}

	int mid = (nl + nr) / 2;
	update(l, r, nl, mid, 2 * node, v);
	update(l, r, mid + 1, nr, 2 * node + 1, v);

	A[node] = A[2 * node] + A[2 * node + 1];
}

mat2 sum(int l, int r, int nl, int nr, int node) {
	push_down(node);

	if (r < nl || nr < l) return zero();
	if (l <= nl && nr <= r) {
		return A[node];
	}

	int mid = (nl + nr) / 2;
	auto a1 = sum(l, r, nl, mid, 2 * node);
	auto a2 = sum(l, r, mid + 1, nr, 2 * node + 1);

	return a1 + a2;
}

void solve() {
	while (M--) {
		int t, l, r, x;
		cin >> t >> l >> r;
		if (t == 1) {
			cin >> x;
			update(l, r, 1, MAXN, 1, raise(fib(), x));
		} else {
			auto m = sum(l, r, 1, MAXN, 1);
			cout << m.b << endl;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	read();
	solve();

	return 0;
}