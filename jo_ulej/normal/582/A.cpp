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
void solve() {
	int n = fetch<int>();
	auto a = fetch_vec<int>(n * n);
	auto b = a;
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	DBG(len(b));
	map<int, int> cntPairs;
	for(int i = 0; i < n * n; ++i) {
		int v = a[i];
		for(auto& x: b) {
			if(v % x == 0) {
				++cntPairs[x];
			}
		}
	}
	map<int, int> cntElems;
	for(auto& PR: cntPairs) {
		int x = PR.first;
		int y = PR.second;
		int low = 0, high = 1e4;
		DBG(x);
		while(high - low > 1) {
			int mid = (low + high) / 2;
			if(mid * mid > y) {
				high = mid;
			} else {
				low = mid;
			}
		}
		cntElems[x] = low;
		DBG(low);
	}
	vector<int> answ;
	reverse(b.begin(), b.end());
	for(auto& x: b) {
		int y = cntElems[x];
		for(auto& z: b) if(z % x == 0 && z != x) y -= cntElems[z];
		cntElems[x] = y;
		for(int i = 0; i < y; ++i) answ.emplace_back(x);
	}
	sort(answ.begin(), answ.end());
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}