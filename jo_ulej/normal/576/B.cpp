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
	#define DEBUG_OUTPUD_ENABLED 1
#else
	#define DEBUG_OUTPUD_ENABLED 0
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
				if(DEBUG_OUTPUD_ENABLED) {
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

const int MAXN = (int)1e5 + 7;
vector<int> cycles[MAXN];
int sz[MAXN];
int cntCycles = 0;
int P[MAXN], n;
int used[MAXN];
void solve() {
	cin >> n; for(int i = 0; i < n; ++i) P[i] = fetch<int>() - 1;
	for(int v = 0; v < n; ++v) if(!used[v]) {
		int j = v;
		while(!used[j]) {
			used[j] = 1;
			cycles[cntCycles].emplace_back(j);
			++sz[cntCycles];
			j = P[j];
		}
		++cntCycles;
	}
	for(int v = 0; v < n; ++v) {
		if(P[v] == v) {
			cout << "YES\n";
			for(int u = 0; u < n; ++u) {
				if(v != u) cout << v + 1 << ' ' << u + 1 << '\n';
			}
			return;
		}
	}
	int allEven = 1;
	for(int id = 0; id < cntCycles; ++id) {
		if(len(cycles[id])&1) {
			allEven = 0;
			break;
		}
	}
	if(allEven) {
		int master = 0;
		while(master < cntCycles && len(cycles[master]) != 2) ++master;
		if(master < cntCycles) {
			cout << "YES\n";
			cout << cycles[master].front() + 1 << ' ' << cycles[master].back() + 1 << '\n';
			for(int id = 0; id < cntCycles; ++id) {
				if(id == master) continue;
				for(int i = 0; i < len(cycles[id]); ++i) {
					int ii = i&1;
					cout << cycles[id][i] + 1 << ' ' << cycles[master][ii] + 1 << '\n';
				}
			}
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	fast_io();
	solve();

	return 0;
}