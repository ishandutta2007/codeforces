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
string find(const string& T) {
	string rez;
	for(int cnt = len(T); cnt > 0; --cnt) {
		int ok = 1;
		int i = 0, j = cnt - 1;
		while(i < j) {
			if(T[i] != T[j]) {
				ok = 0;
				break;
			}
			++i;
			--j;
		}
		if(ok) {
			for(int i = 0; i < cnt; ++i) rez.push_back(T[i]);
			break;
		}
	}
	return rez;
}
void solve() {
	auto S = fetch<string>();
	int n = len(S);
	int l = 0, r = n - 1;
	while(l < r) {
		if(S[l] == S[r]) {
			++l;
			--r;
		} else {
			break;
		}
	}
	string rez;
	for(int i = 0; i < l; ++i) rez.push_back(S[i]);
	if(l <= r) {
		string T, best1, best2;
		for(int i = l; i <= r; ++i) T.push_back(S[i]);
		best1 = find(T);
		reverse(T.begin(), T.end());
		best2 = find(T);
		if(len(best1) < len(best2)) swap(best1, best2);
		for(auto& ch: best1) rez.push_back(ch);
	}
	for(int i = r + 1; i < n; ++i) rez.push_back(S[i]);
	cout << rez << '\n';
}

int main() {
	fast_io();
	int T = fetch<int>();
	while(T--) {
		solve();
	}

	return 0;
}