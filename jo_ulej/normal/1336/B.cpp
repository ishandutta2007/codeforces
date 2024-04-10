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
ll F(ll x, ll y, ll z) {
	return (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
}
void solve() {
	int n = fetch<int>();
	int m = fetch<int>();
	int k = fetch<int>();
	auto a = fetch_vec<ll>(n);
	auto b = fetch_vec<ll>(m);
	auto c = fetch_vec<ll>(k);
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	ll answ = F(a[0], b[0], c[0]);
	vector<vector<ll>> arrs = {a, b, c};
	vector<int> perm(3);
	for(int i = 0; i < 3; ++i) perm[i] = i;
	do {
		const auto& L = arrs[perm[0]];
		const auto& M = arrs[perm[1]];
		const auto& R = arrs[perm[2]];
		for(auto& mid: M) {
			auto iterHuge = lower_bound(R.begin(), R.end(), mid);
			if(iterHuge == R.end()) continue;
			auto iterSmall = upper_bound(L.begin(), L.end(), mid);
			if(iterSmall == L.begin()) continue;
			--iterSmall;
			ll huge = *iterHuge;
			ll small = *iterSmall;
			answ = min(answ, F(small, mid, huge));
		}
	} while(next_permutation(perm.begin(), perm.end()));
	cout << answ << '\n';
}

int main() {
	fast_io();
	int T = fetch<int>();
	while(T--) solve();

	return 0;
}