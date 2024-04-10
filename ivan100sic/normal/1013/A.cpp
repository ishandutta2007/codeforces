#include <bits/stdc++.h>
using namespace std;

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
typedef long double ld;
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

	iint n;
	vector<iint> a(n);
	vector<iint> b(n);
	cout << (accumulate(be(a), 0) >= accumulate(be(b), 0) ? "Yes\n" : "No\n");
}