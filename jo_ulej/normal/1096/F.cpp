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
	#define DEBUG_OUTPUD_ENABLED 1
#else
	#define DEBUG_OUTPUD_ENABLED 0
#endif

#define dout   debug::instance
#define DBG(X) dout << #X << "=" << (X) << '\n';
#define SAY(X) dout << (X) << '\n';

using namespace std;

template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace debug {
	struct DebugStream {
		private:
			bool is_first;
		public:
			DebugStream(bool _is_first): is_first(_is_first) {}
			template<typename T> DebugStream operator<<(const T& value) const {
				if(DEBUG_OUTPUD_ENABLED) {
					if(is_first) cout << "[DBG] ";
					cout << value;
				}
				return DebugStream(false);
			};
	};
	DebugStream instance(true);
};

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
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
const int MOD = 998244353;
const int INV2 = (MOD + 1) / 2;
int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
void radd(int& x, int y) {
	x = add(x, y);
}
int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}
int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}
int binpow(int x, int y) {
	if(x == 1 || y == 0) return 1;
	if(x == 0) return 0;
	int rez = binpow(x, y>>1);
	rez = mult(rez, rez);
	if(y&1) rez = mult(rez, x);
	return rez;
}
int divide(int x, int y) {
	return mult(x, binpow(y, MOD - 2));
}
const int MAXN = (int)2e5 + 7;
int P[MAXN], n;
int used[MAXN];
int good[MAXN], cntGood = 0;
int answ = 0;
int pairs(int x) {
	int rez = mult(x, sub(x, 1));
	rez = mult(rez, INV2);
	return rez;
}
struct Fenwick {
	int* F = nullptr;
	int sz;
	Fenwick(int _sz): sz(_sz) {
		F = new int[sz];
		memset(F, 0, sizeof(int) * sz);
	}
	void add(int pos, int val) {
		for(; pos < sz; pos |= pos + 1) {
			F[pos] += val;
		}
	}
	int get(int r) {
		int rez = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1) {
			rez += F[r];
		}
		return rez;
	}
};
void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> P[i];
		if(P[i] != NIL) {
			--P[i];
			used[P[i]] = 1;
		}
	}
	for(int i = 0; i < n; ++i) if(!used[i]) {
		good[cntGood++] = i;
	}
	/*for(int i = 0; i < n; ++i) {
		if(P[i] == NIL) continue;
		for(int j = 0; j < i; ++j) {
			if(P[j] == NIL) continue;
			if(P[i] < P[j]) radd(answ, 1);
		}
	}*/
	Fenwick fenvichek(MAXN);
	for(int i = n - 1; i >= 0; --i) {
		if(P[i] == NIL) continue;
		radd(answ, fenvichek.get(P[i]));
		fenvichek.add(P[i], +1);
	}
	int cntNILs = 0;
	for(int i = 0; i < n; ++i) {
		if(P[i] == NIL) {
			++cntNILs;
		} else {
			int pos = upper_bound(good, good + cntGood, P[i]) - good;
			int prob = divide(cntGood - pos, cntGood);
			radd(answ, mult(cntNILs, prob));
		}
	}
	cntNILs = 0;
	for(int i = n - 1; i >= 0; --i) {
		if(P[i] == NIL) {
			++cntNILs;
		} else {
			int pos = upper_bound(good, good + cntGood, P[i]) - good;
			int prob = divide(pos, cntGood);
			radd(answ, mult(cntNILs, prob));
		}
	}
	cntNILs = 0;
	for(int i = 0; i < n; ++i) cntNILs += (P[i] == NIL);
	radd(answ, mult(pairs(cntNILs), INV2));
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}