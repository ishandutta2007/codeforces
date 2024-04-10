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
#else
	#define DEBUG_OUTPUT_ENABLED 0
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

ll getMin(const multiset<ll>& setik) {
	return setik.empty() ? LL_INF : *(setik.begin());
}

ll removeMin(multiset<ll>& setik) {
	assert(!setik.empty());
	auto iter = setik.begin();
	ll x = *iter;
	setik.erase(iter);
	return x;
}

void solve() {
	multiset<ll> Free, Left, Right;
	int n = fetch<int>();
	while(n--) {
		ll x = fetch<ll>();
		/*if(x > getMin(Free)) {
			Left.insert(removeMin(Free));
			Right.insert(x);
		} else if(x > getMin(Right)) {
			Free.insert(removeMin(Right));
			Right.insert(x);
		} else {
			Free.insert(x);
		}*/
		ll A = x - getMin(Free);
		ll B = x - getMin(Right);
		if(A <= 0 && B <= 0) {
			Free.insert(x);
		} else if(A > B) {
			Left.insert(removeMin(Free));
			Right.insert(x);
		} else {
			Free.insert(removeMin(Right));
			Right.insert(x);
		}
	}
	ll answ = 0;
	for(auto& el: Left) answ -= el;
	for(auto& el: Right) answ += el;
	cout << answ << '\n';

	//for(auto& el: Left) DBG(-el);
	//for(auto& el: Right) DBG(el);
}

int main() {
	fast_io();
	solve();

	return 0;
}