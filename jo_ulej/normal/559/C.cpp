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
const int MOD  = (int)1e9 + 7;
int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
void radd(int& x , int y) {
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
int binpow(int x, int y) {
	if(x == 1 || y == 0) return 1;
	if(x == 0) return 0;
	int rez = binpow(x, y>>1);
	rez = mult(rez, rez);
	if(y&1) rez = mult(rez, x);
	return rez;
}
int divide(int x, int y) {
	return mult(x, binpow(y, MOD - 2));
}
const int MAXN = (int)3e5 + 7;
pii pts[MAXN];
int dp[MAXN];
int f[MAXN], revf[MAXN];
int H, W, n;
void init() {
	f[0] = 1;
	for(int i = 1; i < MAXN; ++i) f[i] = mult(i, f[i - 1]);
	revf[MAXN - 1] = divide(1, f[MAXN - 1]);
	for(int i = MAXN - 2; i >= 0; --i) revf[i] = mult(i + 1, revf[i + 1]);
}
int choose(int n, int k) {
	if(k > n) return 0;
	int rez = f[n];
	rez = mult(rez, revf[k]);
	rez = mult(rez, revf[n - k]);
	return rez;
}
int count(int dx, int dy) {
	if(dx < 0 || dy < 0) return 0;
	return choose(dx+dy, dx);
}
void solve() {
	init();
	cin >> H >> W >> n;
	for(int i = 0; i < n; ++i) cin >> pts[i].first >> pts[i].second;
	sort(pts, pts + n);
	for(int i = 0; i < n; ++i) {
		dp[i] = count(pts[i].first-1, pts[i].second-1);
		for(int j = 0; j < i; ++j) {
			int w = dp[j];
			rmult(w, count(pts[i].first-pts[j].first, pts[i].second-pts[j].second));
			rsub(dp[i], w);
		}
		//dout << i + 1 << ": " << dp[i] << '\n';
		//dout << count(H-pts[i].first, W-pts[i].second) << '\n';;
	}
	int answ = count(H-1, W-1);
	//dout << "ini: " << answ << '\n';
	for(int i = 0; i < n; ++i) rsub(answ, mult(dp[i], count(H-pts[i].first, W-pts[i].second)));
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}