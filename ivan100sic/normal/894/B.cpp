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
typedef modint<MOD> mint;


template<class T, class U>
void operator+= (vector<T>& a, const U& b) {
	a.push_back(T(b));
}

template<class T>
struct in {
	T x;
	in () : x() { cin >> x; }
	in (const T& x) : x(x) {}
	in (T&& x) : x(x) {}
	operator T& () { return x; }
	operator const T& () const { return x; }
	auto begin() { return x.begin(); }
	auto end() { return x.end(); }
	auto begin() const { return x.begin(); }
	auto end() const { return x.end(); }
	auto size() const { return x.size(); }
};

template<class T>
struct out {
	T x;
	out () : x() {}
	out (const T& x) : x(x) {}
	out (T&& x) : x(x) {}
	operator T& () { return x; }
	operator const T& () const { return x; }
	~out() { cout << x << ' '; }
	auto begin() { return x.begin(); }
	auto end() { return x.end(); }
	auto begin() const { return x.begin(); }
	auto end() const { return x.end(); }
	auto size() const { return x.size(); }
};

typedef long long ll;
typedef unsigned long long ull;
typedef in<int> iint;
typedef out<int> oint;
typedef in<ll> ill;
typedef out<ll> oll;
typedef in<string> istr;
typedef out<string> ostr;
typedef vector<int> vi;
typedef vector<iint> ivi;
typedef vector<oint> ovi;

#define be(a) (a).begin(), (a).end()

template<class T>
struct rr_ {
	struct valit {
		T val;
		T operator* () const { return val; }
		T operator* () { return val; }
		valit& operator++ () {
			++val;
			return *this;
		}
		bool operator != (const valit& other) const {
			return val != other.val;
		}
	};

	const valit l, r;
	valit begin() { return l; }
	valit end() { return r; }
};

template<class T, class U>
rr_<T> rr(T a, U b) {
	return rr_<T>{a, b};
}

// END OF TEMPLATE CODE

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ill n, m, k;
	mint z = mint(2) ^ (n-1) ^ (m-1);
	if ((n-m) % 2 && k == -1) {
		z = 0;
	}
	oint(z.x);
}