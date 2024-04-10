#include <bits/stdc++.h>
using namespace std;

template<unsigned long long m>
struct modint {

	unsigned long long x;

	modint() : x(0) {}

	modint(long long arg) {
		arg %= m;
		if (arg < 0) {
			x = arg + m;
		} else {
			x = arg;
		}
	}

	

	modint& operator+= (const modint& other) {
		x += other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint& operator*= (const modint& other) {
		x = (x * other.x) % m;
		return *this;
	}

	modint& operator-= (const modint& other) {
		x += m - other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint operator+ (const modint& other) const {
		modint tmp = *this;
		tmp += other;
		return tmp;
	}

	modint operator- (const modint& other) const {
		modint tmp = *this;
		tmp -= other;
		return tmp;
	}

	modint operator* (const modint& other) const {
		modint tmp = *this;
		tmp *= other;
		return tmp;
	}

	explicit operator unsigned long long () const {
		return x;
	}

	modint& operator++ () {
		++x;
		if (x == m) {
			x = 0;
		}
		return *this;
	}

	modint& operator-- () {
		if (x == 0) {
			x = m-1;
		} else {
			--x;
		}
		return *this;
	}

	modint operator++ (int) {
		modint tmp = *this;
		++*this;
		return tmp;
	}

	modint operator-- (int) {
		modint tmp = *this;
		--*this;
		return tmp;
	}

	bool operator== (const modint& other) const {
		return x == other.x;
	}

	bool operator!= (const modint& other) const {
		return x != other.x;
	}

	modint operator^ (unsigned long long arg) const {
		if (arg == 0) {
			return 1;
		}
		if (arg == 1) {
			return x;
		}
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1) {
			t *= *this;
		}
		return t;
	}

	modint inv(unsigned long long exp = m - 2) const {
		return *this ^ exp;
	}
};

const unsigned long long MOD = 1'000'000'007;
const int HI = 17;

typedef modint<MOD> mint;
typedef array<mint, 1 << HI> state;

mint fib[1 << HI];
int n;
int a[1000005];

mint brut[1 << HI];

void xot(state& a, int l = 0, int r = 1 << HI) {
	if (r-l == 1) {
		return;
	}

	int m = (l+r) / 2;
	int h = r - m;

	xot(a, l, m);
	xot(a, m, r);

	vector<mint> tmp(a.begin()+l, a.begin()+r);

	for (int i=0; i<h; i++) {
		a[l + i] = tmp[i] + tmp[i + h];
		a[l + i + h] = tmp[i] - tmp[i + h];
	}
}

void wot(state& a, int l = 0, int r = 1 << HI) {
	if (r-l == 1) {
		return;
	}

	int m = (l+r) / 2;
	int h = r - m;

	wot(a, l, m);
	wot(a, m, r);

	vector<mint> tmp(a.begin()+l, a.begin()+r);

	for (int i=0; i<h; i++) {
		a[l + i] = tmp[i] + tmp[i + h];
		a[l + i + h] = tmp[i + h];
	}
}

void lot(state& a, int l = 0, int r = 1 << HI) {
	if (r-l == 1) {
		return;
	}

	int m = (l+r) / 2;
	int h = r - m;

	lot(a, l, m);
	lot(a, m, r);

	vector<mint> tmp(a.begin()+l, a.begin()+r);

	for (int i=0; i<h; i++) {
		a[l + i] = tmp[i] - tmp[i + h];
		a[l + i + h] = tmp[i + h];
	}
}

void debug_state(state& a) {
	for (int i=0; i< (1 << HI); i++) {
		cerr << a[i].x << ' ';
	}
	cerr << '\n';
}

state init_pure_state() {
	state b;
	for (int i=0; i<n; i++) {
		b[a[i]] += 1;
	}
	return b;
}

state init_fib_state() {
	state b;
	for (int i=0; i<n; i++) {
		b[a[i]] += fib[a[i]];
	}
	return b;
}

state pointwise_multiply(state& a, state& b) {
	state c;
	for (int i=0; i<(1<<HI); i++) {
		c[i] = a[i] * b[i];
	}
	return c;
}

void divhi(state& a) {
	mint ml = mint(1 << HI).inv();
	for (int i=0; i<(1<<HI); i++) {
		a[i] *= ml;
	}
}

state state_xor(state a, state b) {
	xot(a);
	xot(b);
	a = pointwise_multiply(a, b);
	xot(a);
	divhi(a);
	return a;
}

state state_and(state a, state b) {
	wot(a);
	// cerr << "Special\n";
	// debug_state(a);
	wot(b);
	a = pointwise_multiply(a, b);
	lot(a);
	return a;
}

state state_self_or(state a) {
	state b;

	for (int mask=0; mask<(1<<HI); mask++) {
		for (int sub=mask; sub; sub=(sub-1)&mask) {
			b[mask] += a[sub] * a[mask - sub];
		}
		b[mask] += a[0] * a[mask];
	}

	return b;
}

state apply_fib(state a) {
	state b;

	for (int i=0; i<(1<<HI); i++) {
		b[i] = fib[i] * a[i];
	}

	return b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	fib[1] = 1;
	for (int i=2; i < (1<<HI); i++) {
		fib[i] = fib[i-1] + fib[i-2];
	}

	auto s = init_pure_state();
	auto sc = apply_fib(s);

	auto sde = apply_fib(state_xor(s, s));
	auto scde = state_and(sc, sde);

	auto sab = state_self_or(s);
	auto sol = state_and(scde, apply_fib(sab));

	/*
	debug_state(s);
	debug_state(sc);
	debug_state(sde);
	debug_state(scde);
	debug_state(sab);
	debug_state(sol);
	*/

	mint o;

	for (int i=0; i<HI; i++) {
		o += sol[1 << i];
	}

	cout << o.x;
}

/*
  a b c d
A 0 0 0 0
B 0 1 0 1
C 0 0 2 2
D 0 1 2 3

0: Aa+Ab+Ac+Ad+Ba+Bc+Ca+Cb+Da = (A+B+C+D)(a+b+c+d) - #1 - #2 + #3
1: Bb+Bd+Db = (B+D)(b+d) - Dd
2: Cc+Cd+Dc = (C+D)(c+d) - Dd
3: Dd

(A B) -> (A-B B)

P Q R S -> P-Q-R+S Q-S R-S S
(P-Q Q) (R-S S)

P-Q-R+S Q-S R-S S



jos samo TRUE OR

  a b c d
A 0 1 2 3
B 1 . 3 .
C 2 3 . .
D 3 . . .

0: Aa
1: Ba + Ab
2: Ca + Ac
D: Da + Cb + Bc + Ad

*/