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
	};
	template<typename T> void printArray(T* l, T* r) {
		if(DEBUG_OUTPUT_ENABLED) {
			while(l != r) {
				cout << (*l);
				++l;
				if(l == r) cout << '\n';
				if(l != r) cout << ' ';
			}
		}
	}
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
const int MAXN = (int)1e5 + 7;
const int TIE  = (int)700;
int a[MAXN], b[MAXN], n, d;
ll x;
ll getNextX() {
	x = (37 * x + 10007) % 1000000007;
	return x;
}
void initAB() {
	for(int i = 0; i < n; ++i){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; ++i){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; ++i){
        if (i < d) {
            b[i] = 1;
		} else {
            b[i] = 0;
		}
    }
    for(int i = 0; i < n; ++i){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}
int answ[MAXN], shifts[MAXN], cntShifts = 0;
pii pts[MAXN];
void solve() {
	cin >> n >> d >> x; initAB();
	for(int i = 0; i < n; ++i) if(b[i]) {
		shifts[cntShifts++] = i;
	}
	for(int i = 0; i < n; ++i) {
		pts[i] = make_pair(a[i], i);
	}
	debug::printArray(a, a + n);
	debug::printArray(b, b + n);
	sort(pts, pts + n);
	reverse(pts, pts + n);
	int cur = n;
	for(int i = 0; i < n; ++i) {
		if(cur <= TIE) break;
		int val = pts[i].first;
		int pos = pts[i].second;
		for(int j = 0; j < cntShifts; ++j) {
			int p = pos + shifts[j];
			if(p >= n) break;
			if(answ[p] == 0) {
				answ[p] = val;
				--cur;
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		if(answ[i]>0) continue;
		for(int j = 0; j < cntShifts; ++j) {
			int s = shifts[j];
			if(s>i) break;
			answ[i] = max(answ[i], a[i-s]);
		}
	}
	for(int i = 0; i < n; ++i) cout << answ[i] << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}