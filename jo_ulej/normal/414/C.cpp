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
				if(DEBUG_OUTPUT_ENABLED) {
					if(is_first) cout << "[DBG] ";
					cout << value;
				}
				return DebugStream(false);
			};

			template<typename T> DebugStream printArray(T* l, T* r) {
				if(DEBUG_OUTPUT_ENABLED) {
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
const int MAXN = (1<<20) + 7567;
const int LOG  = 30;
int n, m;
int a[MAXN];
ll P[LOG], Q[LOG];
vector<int> lvl[2 * MAXN];
vector<int> glue(const vector<int>& left, const vector<int>& right) {
	vector<int> rez;
	int i = 0, j = 0;
	int L = len(left), R = len(right);
	while(i < L && j < R) {
		if(left[i] < right[j]) {
			rez.emplace_back(left[i++]);
		} else {
			rez.emplace_back(right[j++]);
		}
	}
	while(i < L) rez.emplace_back(left[i++]);
	while(j < R) rez.emplace_back(right[j++]);
	return rez;
}
ll countInv(const vector<int>& left, const vector<int>& right) {
	int L = len(left), R = len(right);
	int ptr = 0;
	ll rez = 0;
	for(int i = 0; i < R; ++i) {
		while(ptr < L && left[ptr] <= right[i]) ++ptr;
		rez += L - ptr;
	}
	return rez;
}
void build(int v, int l, int r, int d) {
	if(l == r) {
		lvl[v].emplace_back(a[l]);
	} else {
		int m = (l+r)/2;
		build(2*v+1, l, m, d + 1);
		build(2*v+2, m + 1, r, d + 1);
		lvl[v] = glue(lvl[2*v+1], lvl[2*v+2]);
		P[d] += countInv(lvl[2*v+1], lvl[2*v+2]);
		Q[d] += countInv(lvl[2*v+2], lvl[2*v+1]);
	}
	//dout << l << ' ' << r << ": " << lvl[v] << '\n';
}
void solve() {
	cin >> n;
	for(int i = 0; i < (1<<n); ++i) cin >> a[i];
	build(0, 0, (1<<n) - 1, 0);
	cin >> m;
	while(m--) {
		int q = n - fetch<int>();
		for(int i = q; i < LOG; ++i) swap(P[i], Q[i]);
		ll answ = 0;
		for(int i = 0; i < LOG; ++i) answ += P[i];
		cout << answ << '\n';
	}
}
int main() {
	fast_io();
	solve();

	return 0;
}