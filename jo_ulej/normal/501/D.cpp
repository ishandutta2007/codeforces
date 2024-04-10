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
const int MAXN = (int)2e5 + 7;
int P[MAXN], Q[MAXN], R[MAXN], n;
int a[MAXN];
struct Fenwick {
	int* F = nullptr;
	int sz;
	Fenwick(int _sz): sz(_sz) {
		F = new int[sz];
		memset(F, 0, sizeof(F[0]) * sz);
	}
	~Fenwick() {
		delete[] F;
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
	int kth(int k) {
		DBG(k);
		int low = 0, high = sz - 1;
		if(get(low) == k) return low;
		assert(get(high) >= k);
		while(high - low > 1) {
			int mid = (low + high) / 2;
			if(get(mid) >= k) {
				high = mid;
			} else {
				low = mid;
			}
		}
		DBG(high);
		return high;
	}
};
void calc(int* perm) {
	Fenwick fenv(MAXN);
	for(int i = 0; i < n; ++i) fenv.add(i, 1);
	for(int i = 0; i < n; ++i) {
		int val = perm[i];
		fenv.add(val, -1);
		a[n - i - 1] += fenv.get(val);
		dout << max(1, n - i - 1) << "! * " << fenv.get(val) << '\n';
	}
	assert(a[0] == 0);
}
void restore() {
	Fenwick fenv(MAXN);
	for(int i = 0; i < n; ++i) fenv.add(i, 1);
	for(int i = 0; i < n; ++i) {
		int val = fenv.kth(a[n - i - 1] + 1);
		R[i] = val;
		fenv.add(val, -1);
	}
}
void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> P[i];
	for(int i = 0; i < n; ++i) cin >> Q[i];
	calc(P);
	calc(Q);
	for(int i = 1; i <= n; ++i) {
		a[i + 1] += a[i] / (i + 1);
		a[i] %= (i + 1);
	}
	a[n] = 0;
	ll pos = 0, f = 1;
	for(int i = 1; i <= n; ++i) {
		f *= i;
		pos += f * a[i];
	}
	DBG(pos);
	restore();
	for(int i = 0; i < n; ++i) cout << R[i] << ' ';
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}