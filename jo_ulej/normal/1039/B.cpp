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
	#define DEBUG_OUTPUT_ENABLED 1
	#define DBG(X) dout << #X << "=" << (X) << '\n';
	#define SAY(X) dout << (X) << '\n';
#else
	#define DEBUG_OUTPUT_ENABLED 0
	#define DBG(X) 42;
	#define SAY(X) 42;
#endif

#define dout   debug::instance

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
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				cout << value;
				return DebugStream(false);
			};

			template<typename T> DebugStream printArray(T* l, T* r) {
				assert(DEBUG_OUTPUT_ENABLED);
				if(is_first) cout << "[DBG] ";
				while(l != r) {
					cout << (*l);
					++l;
					if(l == r) {
						cout << '\n';
					} else {
						cout << ' ';
					}
				}
				return DebugStream(false);
			}
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
ll n, k, cur, ops;
inline int Ask(ll L, ll R) {
#ifdef __LOCAL
	++ops;
	int fl = (L <= cur && cur <= R);
	if(fl && L == R) {
		SAY("WIN");
		DBG(ops);
		exit(0);
	}
	dout << "@LR: " << L << ' ' << R << '\n';
	dout << "@cur: " << cur << '\n';
	cur += randint(-k, k);
	cur = max(1LL, cur);
	cur = min(n, cur);
	return fl;
#else
	cout << L << ' ' << R << '\n';
	string resp = fetch<string>();
	int fl = (resp == "Yes");
	if(fl && L == R) exit(0);
	return fl;
#endif
}
void solve() {
	ll L = 1;
	ll R = (n = fetch<ll>());
	k = fetch<ll>();
	cur = n / 2;
	while(true) {
		while(L < R) {
			ll old = R - L;
			ll M = (L + R) / 2;
			if(Ask(L, M)) {
				R = M;
			} else {
				L = M + 1;
			}
			L = max(1LL, L - k);
			R = min(n, R + k);
			if(R - L >= old) break;
		}
		ll x = randint(L, R);
		Ask(x, x);
		L = max(1LL, L - k);
		R = min(n, R + k);
	}
}

int main() {
	//fast_io();
	solve();

	return 0;
}