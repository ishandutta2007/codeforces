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

#define dout   ___debug::instance

using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const multiset<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace ___debug {
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

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
void precalc() {
	for(ll n = 2; n <= 30; n += 2) {
		ll best = LL_INF;
		for(ll msk = 0; msk < (1LL << n); ++msk) {
			ll cur = 0, bal = 0;
			for(ll i = 0; i < n; ++i) {
				ll value = 1LL << (i + 1);
				if((msk >> i) & 1LL) cur += value, ++bal;
				else cur -= value, --bal;
			}
			DBG(cur);
			if(cur < 0) cur = -cur;
			if(bal == 0) best = min(best, cur);
		}
		cout << "if(n == " << n << ") cout << " << best << ";\n";
	}
}

void solve() {
ll n = fetch<ll>();
if(n == 2) cout << 2;
if(n == 4) cout << 6;
if(n == 6) cout << 14;
if(n == 8) cout << 30;
if(n == 10) cout << 62;
if(n == 12) cout << 126;
if(n == 14) cout << 254;
if(n == 16) cout << 510;
if(n == 18) cout << 1022;
if(n == 20) cout << 2046;
if(n == 22) cout << 4094;
if(n == 24) cout << 8190;
if(n == 26) cout << 16382;
if(n == 28) cout << 32766;
if(n == 30) cout << 65534;
cout << '\n';
}

int main() {
	fast_io();
	//precalc();
	int t = fetch<int>();
	while(t--) solve();

	return 0;
}