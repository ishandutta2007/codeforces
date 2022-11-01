#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,mmx,sse,sse2")

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
const int MAXN = (int)1e5 + 7;
const int MAXT = 357;
int T;
ll a[MAXN];
vector<int> S[MAXN], H, L;
int Hpos[MAXN];
int n, m, q;
ll sum[MAXN], add[MAXN];
int commonWithHeavy[MAXN][MAXT];
int in[MAXN];
void solve() {
	cin >> n >> m >> q;
	T = sqrt(n); DBG(T);
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int id = 0; id < m; ++id) {
		int cnt = fetch<int>();
		S[id].resize(cnt);
		if(cnt <= T) {
			L.emplace_back(id);
		} else {
			H.emplace_back(id);
			Hpos[id] = len(H) - 1;
		}
		for(auto& pos: S[id]) {
			pos = fetch<int>() - 1;
			sum[id] += a[pos];
		}
	}
	int cntH = len(H);
	/*for(int id = 0; id < m; ++id) {
		for(auto& pos: S[id]) cur[pos] = 1;
		for(int j = 0; j < cntH; ++j) {
			commonWithHeavy[id][j] = (cur & in[j]).count();
		}
		for(auto& pos: S[id]) cur[pos] = 0;
	}*/
	for(int j = 0; j < cntH; ++j) {
		int hID = H[j];
		for(auto& pos: S[hID]) in[pos] = 1;
		for(int id = 0; id < m; ++id) {
			for(auto& pos: S[id]) {
				commonWithHeavy[id][j] += in[pos];
			}
		}
		for(auto& pos: S[hID]) in[pos] = 0;
	}
	for(int curque = 0; curque < q; ++curque) {
		char cmd = fetch<char>();
		int  id = fetch<int>() - 1;
		int sz = len(S[id]);
		if(cmd == '?') {
			ll answ = 0;
			if(sz <= T) {
				for(auto& pos: S[id]) answ += a[pos];
				for(int j = 0; j < cntH; ++j) {
					int hID = H[j];
					answ += commonWithHeavy[id][j] * add[hID];
				}
			} else {
				answ = sum[id];
				//int j = Hpos[id];
				//for(int id = 0; id < m; ++id) answ += commonWithHeavy[id][j] * add[id];
			}
			cout << answ << '\n';
		} else if(cmd == '+') {
			ll x = fetch<ll>();
			add[id] += x;
			if(sz <= T) {
				for(auto& pos: S[id]) a[pos] += x;
			}
			for(int j = 0; j < cntH; ++j) {
				int hID = H[j];
				sum[hID] += x * commonWithHeavy[id][j];
			}
		} else {
			assert(false);
		}	
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}