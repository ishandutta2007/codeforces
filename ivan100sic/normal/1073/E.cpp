#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int m>
struct modint {

	unsigned x;

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
		x = (x * 1ll * other.x) % m;
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

	explicit operator int () const {
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

	template<class T>
	modint operator^ (T arg) const {
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

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 998244353;
typedef modint<MOD> mint;

int a[20];
int n;

void to_digits(ll x) {
	for (int i=0; i<20; i++) {
		a[i] = x % 10;
		if (a[i] > 0)
			n = i;
		x /= 10;
	}
}

mint dp(int mask) {
	int cnt = 0;
	int sum = 0;
	for (int i=0; i<10; i++)
		if (mask & (1 << i)) {
			cnt += 1;
			sum += i;
		}

	mint curr_val = 0, sol = 0;

	for (int i=n; i>=0; i--) {
		for (int j=0; j<a[i]; j++) {
			if (!(mask & (1 << j)))
				continue;

			curr_val += (mint(10) ^ i) * j;

			mint broj = mint(cnt) ^ i;
			mint sm = mint(sum) * ((mint(10) ^ i) - 1) * mint(9).inv();
			sm *= broj * mint(cnt).inv();
			sol += broj * curr_val + sm;
			curr_val -= (mint(10) ^ i) * j;
		}

		curr_val += (mint(10) ^ i) * a[i];

		if (!(mask & (1 << a[i])))
			break;
	}

	// ad-hoc dodaj ove ostale ako treba
	if ((mask & 1) == 0) {
		for (int k=1; k<=n; k++) {
			mint broj = mint(cnt) ^ k;
			mint sm = mint(sum) * ((mint(10) ^ k) - 1) * mint(9).inv();
			sm *= broj * mint(cnt).inv();
			sol += sm;
		}
	}

	return sol;
}

mint sol[1024];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b;
	int k;

	cin >> a >> b >> k;
	to_digits(b+1);
	for (int mask=1; mask<1024; mask++)
		sol[mask] += dp(mask);
	to_digits(a);
	for (int mask=1; mask<1024; mask++)
		sol[mask] -= dp(mask);

	// cpsiid
	
	for (int i=0; i<10; i++) {
		int b = 1 << i;
		for (int j=0; j<1024; j++)
			if (j & b)
				sol[j] -= sol[j - b];
	}
	

	mint tot = 0;

	for (int mask=0; mask<1024; mask++) {
		if (__builtin_popcount(mask) <= k) {
			tot += sol[mask];
		}
	}

	cout << (int)tot << '\n';
}