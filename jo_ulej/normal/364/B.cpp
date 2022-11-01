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
const int MAXN = (int)5e5 + 7777;
bitset<MAXN> can;
int n, d;
int a[MAXN];
pii tree[2 * MAXN];
void change(int pos, pii val) {
	pos += MAXN;
	if(val > tree[pos]) {
		tree[pos] = val;
		for(; pos > 1; pos >>= 1) tree[pos >> 1] = max(tree[pos], tree[pos ^ 1]);
	}
}
pii get(int l, int r) {
	l += MAXN, r += MAXN + 1;
	pii rez = make_pair(-INT_INF, -INT_INF);
	while(l < r) {
		if(l & 1) rez = max(rez, tree[l++]);
		if(r & 1) rez = max(rez, tree[--r]);
		l >>= 1, r >>= 1;
	}
	return rez;
}
void solve() {
	cin >> n >> d;
	for(int i = 0; i < n; ++i) cin >> a[i];
	can[0] = 1;
	for(int i = 0; i < n; ++i) can |= can << a[i];
	for(int i = 0; i < 2 * MAXN; ++i) tree[i] = make_pair(-INT_INF, -INT_INF);
	for(int i = MAXN - 1; i >= 0; --i) {
		if(!can[i]) continue;
		change(i, make_pair(i, -0));
		int l = i + 1, r = min(i + d, MAXN - 1);
		if(l <= r) {
			auto x = get(l, r);
			--x.second;
			change(i, x);
		}
	}
	//for(int i = 0; i < 20; ++i) dout << i << ": " << get(i, i) << '\n';
	auto answ = get(0, 0);
	cout << answ.first << ' ' << -answ.second << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}