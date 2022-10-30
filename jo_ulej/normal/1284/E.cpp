#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <sstream>
#include <bitset>
#include <cassert>
#include <fstream>
#include <queue>

#define len(X) ((int)(X).size())

#ifdef __LOCAL
	#define DBG(X) cout << #X << "=" << (X) << '\n';
	#define SAY(X) cout << (X) << '\n';
#else
	#define DBG(X)
	#define SAY(X)
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

struct Vector {
	ll x, y;
	Vector(): x(0), y(0) {}
	Vector(ll _x, ll _y): x(_x), y(_y) {}

	Vector operator+(const Vector& other) const {
		return Vector(x + other.x, y + other.y);
	}

	Vector operator-(const Vector& other) const {
		return Vector(x - other.x, y - other.y);
	}

	ll operator%(const Vector& other) const {
		return x * other.x + y * other.y;
	}

	ll operator^(const Vector& other) const {
		return x * other.y - y * other.x;
	}
};

istream& operator>>(istream& is, Vector& vec) {
	is >> vec.x >> vec.y;
	return is;
}

ostream& operator<<(ostream& os, const Vector& vec) {
	os << '[' << vec.x << ';' << vec.y << ']';
	return os;
}

int halfplane(const Vector& v) {
	if(v.y == 0) {
		return (v.x > 0 ? 1 : 2);
	} else {
		return (v.y > 0 ? 1 : 2);
	}
}

bool Vector_compare(const Vector& lhs, const Vector& rhs) {
	if(halfplane(lhs) != halfplane(rhs)) return halfplane(lhs) < halfplane(rhs);
	return (lhs ^ rhs) > 0;
}

const int MAXK = 5;
const int MAXN = 3077;
ll mem[MAXK][MAXN];
int used[MAXK][MAXN];

ll choose(ll k, ll n) {
	if(k > n) return 0;
	if(!used[k][n]) {
		mem[k][n] = 1;
		for(ll i = 0; i < k; ++i) mem[k][n] *= n - i;
		for(ll i = 1; i <= k; ++i) mem[k][n] /= i;
	}

	return mem[k][n];
}

void solve() {
	int n = fetch<int>();
	vector<Vector> a = fetch_vec<Vector>(n);
	ll answ = 0;

	for(int id = 0; id < n; ++id) {
		int sz = n - 1;
		ll local = choose(4, sz);
		vector<Vector> pts; pts.reserve(sz);
		for(int j = 0; j < n; ++j) {
			if(j == id) continue;
			pts.push_back(a[j] - a[id]);
		}

		sort(pts.begin(), pts.end(), Vector_compare);
		DBG(pts);
		vector<Vector> pts2(2 * sz);
		for(int i = 0; i < sz; ++i) {
			pts2[i] = pts[i];
			pts2[sz + i] = pts[i];
		}

		int j = 0;
		for(int i = 0; i < sz; ++i) {
			if(j <= i) j = i + 1;
			while((pts2[i] ^ pts2[j]) > 0) ++j;
#ifdef __LOCAL
			assert(j < 2 * sz);
#endif

			int cnt = i + sz - j;
			local -= choose(3, cnt);
		}

		DBG(local);
		answ += local;
	}

	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}