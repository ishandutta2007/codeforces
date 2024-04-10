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
const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
void radd(int& x, int y) {
	x = add(x, y);
}
int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}
void rsub(int& x, int y) {
	x = sub(x, y);
}
int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}
void rmult(int& x, int y) {
	x = mult(x, y);
}
const int MAXN = (int)1e6 + 7;
int a[MAXN], dp[MAXN], n;
int lst[MAXN];
struct Fenwick {
	int* F = nullptr;
	int sz;
	Fenwick(int _sz): sz(_sz) {
		F = new int[sz];
		memset(F, 0, sizeof(int) * sz);
	}
	void add(int pos, int val) {
		for(; pos < sz; pos |= pos + 1) {
			radd(F[pos], val);
		}
	}
	int get(int r) {
		int rez = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1) {
			radd(rez, F[r]);
		}
		return rez;
	}
	int get(int l, int r) {
		return sub(get(r), get(l - 1));
	}
	
};
void solve() {
	cin >> n; for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) lst[a[i]] = NIL;
	Fenwick fenv(MAXN);
	for(int i = 0; i < n; ++i) {
		int v = a[i];
		int old = fenv.get(v, v);
		int ndp = 1;
		radd(ndp, fenv.get(v));
		rmult(ndp, v);
		//rsub(ndp, old);
		fenv.add(v, sub(ndp, old));
		dout << v << ' ' << ndp << '\n';
	}
	cout << fenv.get(MAXN - 1) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}