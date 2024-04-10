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
const int MAXN = 207;
string S;
int n;
int color[MAXN], del[MAXN];
void solve() {
	cin >> n >> S; for(int i = 0; i < n; ++i) color[i] = NIL;
	for(int ph = 0; ph < n; ++ph) {
		int cur = NIL;
		for(int i = 0; i < n; ++i) if(!del[i]) {
			if(cur == NIL || S[i] < S[cur]) cur = i;
		}
		DBG(cur);
		vector<int> cnt(2, 0);
		for(int i = 0; i < cur; ++i) {
			if(color[i] != NIL && !del[i]) ++cnt[color[i]];
		}
		if(color[cur] == NIL) {
			int v = NIL;
			if(cnt[0]==0) v = 0;
			if(cnt[1]==0) v = 1;
			if(v == NIL) {
				cout << "NO\n";
				return;
			}
			color[cur] = v;
		}
		int ok = 1;
		for(int i = 0; i < cur; ++i) if(!del[i]) {
			if(color[i] == NIL) {
				color[i] = color[cur] ^ 1;
			}
			if(color[i] == color[cur]) {
				cout << "NO\n";
				return;
			}
		}
		del[cur] = 1;
	}
	cout << "YES\n";
	for(int i = 0; i < n; ++i) cout << color[i];
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}