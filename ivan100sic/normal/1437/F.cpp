// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<int m>
struct modint {
	unsigned x;

	modint() : x(0) {}
	modint(long long arg) : x((arg %= m) < 0 ? arg + m : arg) {}

	modint operator+ (const modint& b) const {
		auto t = *this; t.x = (t.x += b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator- (const modint& b) const {
		auto t = *this; t.x = (t.x += m-b.x) >= m ? t.x-m : t.x; return t;
	}

	modint operator* (const modint& b) const {
		auto t = *this; t.x = ll(t.x) * b.x % m; return t;
	}

	template<class T> modint operator^ (T n) const {
		modint t;
		if (n == 0) return t.x = 1, t;
		if (n == 1) return t.x = x, t;
		t = *this ^ (n >> 1); t *= t;
		return n & 1 ? *this * t : t;
	}

	modint& operator+= (const modint& b) { return *this = *this + b; }
	modint& operator-= (const modint& b) { return *this = *this - b; }
	modint& operator*= (const modint& b) { return *this = *this * b; }
	modint& operator++ () { if (++x == m) x = 0; return *this; }
	modint& operator-- () { if (x-- == 0) x = m-1; return *this; }
	modint operator++ (int) { modint tmp = *this; ++*this; return tmp; }
	modint operator-- (int) { modint tmp = *this; --*this; return tmp; }
	bool operator== (const modint& other) const { return x == other.x; }
	bool operator!= (const modint& other) const {	return x != other.x; }
	int operator() () const { return x; }
	template<class T> modint operator^= (T n) { return *this = *this ^ n; }
	modint inv() const { return *this ^ (m-2); }
};

const int mod = 998'244'353;
typedef modint<mod> mint;

int n;
int a[5005];

int b[5005];
void find_b() {
	for (int i=0; i<n; i++) {
		if (i) b[i] = b[i-1];
		while (a[b[i]] >= 2*a[i]) {
			b[i]++;
		}
	}
}

mint invs[5005];
void find_invs() {
	for (int i=1; i<5005; i++) {
		invs[i] = mint(i).inv();
	}
}

struct desc {
	mint mali = 0;
	mint* tail = 0;
	mint tail_lazy = 1;
	mint tail_lazy_inv = 1;
	mint tail_sum = 0;

	void mul(int x) {
		tail_lazy *= x;
		tail_lazy_inv *= invs[x];
		tail_sum *= x;
	}

	void tail_inc(int i, mint v) {
		tail[i] += v * tail_lazy_inv;
		tail_sum += v;
	}

	void tail_clear(int i) {
		tail_sum -= tail[i] * tail_lazy;
		tail[i] = 0;
	}

	mint tail_get(int i) {
		if (!tail) return 0;
		return tail[i] * tail_lazy;
	}
};

desc d[2][5005];

mint fast() {
	d[1][0] = desc{
		0,
		new mint[n],
		1,
		1,
		1,
	};
	d[1][0].tail[0] = 1;

	for (int i=1; i<n; i++) {
		auto ol = d[i%2];
		auto nu = d[1-i%2];

		nu[i] = desc();
		nu[0] = desc();
		nu[i].tail = new mint[n];

		for (int k=1; k<i; k++) {
			nu[k] = ol[k];
			nu[k].mali = 0;
			nu[k].mul(i-k);
		}

		mint nu1inc = 0;

		for (int k=0; k<i; k++) {
			mint t = ol[k].mali;
			nu1inc += t;
			nu[k].mali += t * (i-k);
			nu[k+1].mali += t * k;

			for (int j=b[i-1]; j<b[i]; j++) {
				mint t = ol[k].tail_get(j);
				nu1inc += t;
				nu[k].mali += t * (i-k);
				nu[k+1].mali += t * k;
			}
		}

		nu[1].tail_inc(i, nu1inc);

		for (int k=1; k<i; k++) {
			for (int j=b[i-1]; j<b[i]; j++) {
				nu[k].tail_clear(j);
			}
		}
	}

	mint sol = 0;
	for (int j=0; j<n; j++) {
		sol += d[n%2][j].tail_sum;
		sol += d[n%2][j].mali;
	}

	return sol;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	sort(a, a+n, greater<int>());
	find_b();
	find_invs();

	cout << fast()() << '\n';
}