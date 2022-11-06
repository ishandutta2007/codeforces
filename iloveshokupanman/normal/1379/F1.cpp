#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
#include<complex>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
ll MOD;
const ll MAX = 4000001;
const long double eps = 1E-14;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};

class mint {
	long long x;
public:
	mint(long long x = 0) : x((x% MOD + MOD) % MOD) {}
	mint operator-() const {
		return mint(-x);
	}
	mint& operator+=(const mint& a) {
		if ((x += a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator-=(const mint& a) {
		if ((x += MOD - a.x) >= MOD) x -= MOD;
		return *this;
	}
	mint& operator*=(const  mint& a) {
		(x *= a.x) %= MOD;
		return *this;
	}
	mint operator+(const mint& a) const {
		mint res(*this);
		return res += a;
	}
	mint operator-(const mint& a) const {
		mint res(*this);
		return res -= a;
	}
	mint operator*(const mint& a) const {
		mint res(*this);
		return res *= a;
	}

	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t >> 1);
		a *= a;
		if (t & 1) a *= *this;
		return a;
	}

	// for prime MOD
	mint inv() const {
		return pow(MOD - 2);
	}
	mint& operator/=(const mint& a) {
		return (*this) *= a.inv();
	}
	mint operator/(const mint& a) const {
		mint res(*this);
		return res /= a;
	}

	friend ostream& operator<<(ostream& os, const mint& m) {
		os << m.x;
		return os;
	}
};

mint pw(mint a, ll b) {
	if (b == 0) { return 1; }
	mint ret = pw(a, b >> 1);
	ret *= ret;
	if (b & 1) { ret *= a; }
	return ret;
}

typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;

typedef vector<mint> vmint;
typedef vector<vector<mint>> vvmint;
typedef vector<vector<vector<mint>>> vvvmint;

/////////////////////////////////////
template<typename T>
struct Segment_Tree {
	typedef function<T(T, T)> F;

	ll n;
	F f;//()
	T unit;//

	ll size;
	vector<T> seg;

	Segment_Tree(ll n0, F f0, T unit0) {
		n = n0;
		f = f0;
		unit = unit0;

		size = 1;
		while (size < n) {
			size *= 2;
		}
		seg.assign(2 * size, unit);
	}


	void update(ll k, T x) {//kx
		k += size - 1;
		seg[k] = x;
		while (k > 1) {
			k /= 2;
			seg[k] = f(seg[2 * k], seg[2 * k + 1]);
		}
	}



	T query_prep(ll a, ll b, ll k, ll l, ll r) {//[a,b)k[l,r)
		if (b <= l || a >= r) { return unit; }
		if (a <= l && r <= b) { return seg[k]; }

		T v1 = query_prep(a, b, 2 * k, l, (l + r) / 2);
		T v2 = query_prep(a, b, 2 * k + 1, (l + r) / 2, r);
		return f(v1, v2);

	}

	T query(ll a, ll b) {
		return query_prep(a, b, 1, 1, size + 1);
	}

};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	ll N, M, Q;
	cin >> M >> N >> Q;

	vector<set<ll>> ulis(M + 1);
	vector<set<ll>> dlis(M + 1);
	Segment_Tree<ll> U(M, [](ll a, ll b) {return max(a, b); }, 0);
	Segment_Tree<ll> D(M, [](ll a, ll b) {return min(a, b); }, N+1);


	vector<pair<ll, ll>> uq, dq;


	repn(q, Q) {
		ll i, j;
		cin >> i >> j;
		
		ll x = (i + 1) / 2;
		ll y = (j + 1) / 2;

		//cout << x << " " << y << endl;

		if (i % 2 == 0) {
			if (ulis[x].count(y)) {
				ulis[x].erase(y);
				if (!ulis[x].empty()) { U.update(x, *(--ulis[x].end())); }
				else { U.update(x, 0); }
			}
			else {
				uq.push_back({ x,y });
			}
		}
		else {
			if(dlis[x].count(y)) {
				dlis[x].erase(y);
				if (!dlis[x].empty()) { D.update(x, *dlis[x].begin()); }
				else { D.update(x, N + 1); }
			}
			else {
			dq.push_back({ x,y });
			}
		}

		while (!uq.empty()) {
			auto p = uq[uq.size() - 1];
			ll x = p.first;
			ll y = p.second;

			//cout <<"U"<<" "<< x << " " << y << endl;
			
			ll z = D.query(1, x + 1);
			if (z <= y) { break; }
			uq.pop_back();
			
			ulis[x].insert(y);
			U.update(x, *(--ulis[x].end()));
		}
		while (!dq.empty()) {
			auto p = dq[dq.size() - 1];
			ll x = p.first;
			ll y = p.second;

			//cout << "D" << " " << x << " " << y << endl;

			ll z = U.query(x, M + 1);
			if (z >= y) { break; }
			dq.pop_back();

			dlis[x].insert(y);
			D.update(x, *dlis[x].begin());
		}

		if (uq.empty() && dq.empty()) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
}