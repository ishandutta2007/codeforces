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
const int MAXN = (int)1000 + 7;
int n;
string S[MAXN], T[MAXN], A[MAXN], B[MAXN];
int answ[MAXN];
set<string> used;
void solve() {
	n = fetch<int>(); for(int i = 0; i < n; ++i) {
		S[i] = fetch<string>();
		T[i] = fetch<string>();
		A[i] = S[i].substr(0, 3);
		B[i] = S[i].substr(0, 2) + T[i].substr(0, 1);
	}
	for(int i = 0; i < n; ++i) {
		int flag = 0;
		for(int j = 0; j < n; ++j) {
			if(A[j] == A[i] && i != j) {
				flag = 1;
				break;
			}
		}
		if(flag) {
			answ[i] = 2;
			if(used.count(B[i])) {
				cout << "NO\n";
				return;
			}
			used.insert(B[i]);
		}
	}
	int ch = 1;
	while(ch) {
		ch = 0;
		for(int i = 0; i < n; ++i) if(!answ[i]) {
			if(used.count(A[i])) {
				answ[i] = 2;
				if(used.count(B[i])) {
					cout << "NO\n";
					return;
				}
				used.insert(B[i]);
				ch = 1;
			}
		}
	}
	for(int i = 0; i < n; ++i) if(!answ[i]) {
		answ[i] = 1;
		if(used.count(A[i])) {
			assert(false);
		}
		used.insert(A[i]);
	}
	cout << "YES\n";
	for(int i = 0; i < n; ++i) cout << (answ[i] == 1 ? A[i] : B[i]) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}