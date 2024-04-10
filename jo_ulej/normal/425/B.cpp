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
const int MAXN = 107;
int A[MAXN][MAXN], n, m, k;
int p[MAXN];
int find() {
	int rez = 0;
	for(int j = 0; j < m; ++j) {
		int cnt1 = 0, cnt2 = 0;
		for(int i = 0; i < n; ++i) {
			int v = A[i][j];
			cnt1 += (p[i] != v);
			cnt2 += (p[i] == v);
		}
		rez += min(cnt1, cnt2);
	}
	return rez;
}
void solve() {
	cin >> n >> m >> k;
	if(n <= m) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) A[i][j] = fetch<char>() - '0';
		}
	} else {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) A[j][i] = fetch<char>() - '0';
		}
		swap(n, m);
	}
	int answ = k + 1;
	if(m <= 12) {
		SAY("SLOW");
		for(int msk = 0; msk < (1 << n); ++msk) {
			for(int i = 0; i < n; ++i) p[i] = (msk>>i)&1;
			answ = min(answ, find());
		}
	} else {
		SAY("FAST");
		for(int j = 0; j < m; ++j) {
			for(int i = 0; i < n; ++i) p[i] = A[i][j];
			answ = min(answ, find());
		}
	}
	if(answ > k) answ = NIL;
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}