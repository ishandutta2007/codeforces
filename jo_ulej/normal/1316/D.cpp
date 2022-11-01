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
const int MAXN = 1007;
pii fin[MAXN][MAXN];
string A[MAXN];
int n;
pii Q[MAXN * MAXN];
int head = 0;
inline int valid(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < n;
}
inline void fail() {
	cout << "INVALID\n";
	exit(0);
}
void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) A[i].resize(n, '%');
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
		cin >> fin[i][j].first >> fin[i][j].second;
		if(fin[i][j].first != NIL) --fin[i][j].first;
		if(fin[i][j].second != NIL) --fin[i][j].second;
	}
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
		if(fin[i][j] == make_pair(i, j)) {
			Q[head++] = make_pair(i, j);
			A[i][j] = 'X';
		}
	}
	for(int ptr = 0; ptr < head; ++ptr) {
		auto PR = Q[ptr];
		int i = PR.first, j = PR.second;
		if(valid(i - 1, j) && A[i - 1][j] == '%' && fin[i - 1][j] == fin[i][j]) {
			A[i - 1][j] = 'D';
			Q[head++] = make_pair(i - 1, j);
		}
		if(valid(i + 1, j) && A[i + 1][j] == '%' && fin[i + 1][j] == fin[i][j]) {
			A[i + 1][j] = 'U';
			Q[head++] = make_pair(i + 1, j);
		}
		if(valid(i, j - 1) && A[i][j - 1] == '%' && fin[i][j - 1] == fin[i][j]) {
			A[i][j - 1] = 'R';
			Q[head++] = make_pair(i, j - 1);
		}
		if(valid(i, j + 1) && A[i][j + 1] == '%' && fin[i][j + 1] == fin[i][j]) {
			A[i][j + 1] = 'L';
			Q[head++] = make_pair(i, j + 1);
		}
	}
	//for(int i = 0; i < n; ++i) dout << A[i] << '\n';
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
		if(A[i][j] == '%') {
			if(fin[i][j] != make_pair(NIL, NIL)) fail();
			int fnd = 0;
			if(valid(i - 1, j) && fin[i - 1][j] == make_pair(NIL, NIL)) {
				A[i][j] = 'U';
				fnd = 1;
			}
			if(valid(i + 1, j) && fin[i + 1][j] == make_pair(NIL, NIL)) {
				A[i][j] = 'D';
				fnd = 1;
			}
			if(valid(i, j - 1) && fin[i][j - 1] == make_pair(NIL, NIL)) {
				A[i][j] = 'L';
				fnd = 1;
			}
			if(valid(i, j + 1) && fin[i][j + 1] == make_pair(NIL, NIL)) {
				A[i][j] = 'R';
				fnd = 1;
			}
			if(!fnd) fail();
		}
	}
	//for(int i = 0; i < n; ++i) dout << A[i] << '\n';
	cout << "VALID\n";
	for(int i = 0; i < n; ++i) cout << A[i] << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}