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
const int LOG = 61;
void solve() {
	ll n = fetch<ll>();
	int sz = fetch<int>();
	auto a = fetch_vec<ll>(sz);
	ll sum = 0;
	for(auto& x: a) sum += x;
	if(sum < n) {
		cout << "-1\n";
		return;
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());
	int rez = 0;
	while(n > 0) {
		//DBG(a);
		if(n&1LL) {
			while(a.back() != 1LL) {
				ll last = a.back(); a.pop_back();
				a.push_back(last/2LL);
				a.push_back(last/2LL);
				++rez;
			}
			n -= a.back();
			a.pop_back();
		}
		n /= 2LL;
		int cntOnes = 0;
		while(!a.empty() && a.back() == 1LL) {
			a.pop_back();
			++cntOnes;
		}
		for(auto& x: a) x /= 2LL;
		for(int i = 0; i < cntOnes/2; ++i) a.push_back(1LL);
	}
	cout << rez << '\n';
}

int main() {
	fast_io();
	int T = fetch<int>();
	while(T--) {
		solve();
	}

	return 0;
}