#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,mmx,sse,sse2,tune=native")
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

#define dout   ___debug::instance

using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const multiset<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace ___debug {
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

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
const int MAXN = (int)1e6;
int w, n, m;
int cnt[MAXN], freq[MAXN];
int pw3[MAXN], mod3[MAXN];
void init() {
	pw3[0] = 1;
	for(int i = 1; i < 20; ++i) pw3[i] = 3 * pw3[i - 1];
	mod3[0] = 0;
	for(int i = 1; i < MAXN; ++i) mod3[i] = (mod3[i - 1] == 2 ? 0 : mod3[i - 1] + 1);
}
inline int getTrit(int msk, int pos) {
	return mod3[msk / pw3[pos]];
}
inline int setTrit(int msk, int pos, int val) {
	int cur = getTrit(msk, pos);
	msk += pw3[pos] * (val - cur);
	return msk;
}
inline string fmt(int msk, int sz) {
	string rez(sz, '?');
	for(int i = 0; i < sz; ++i) {
		int v = getTrit(msk, i);
		if(v) rez[i] = '0' + (v - 1);
	}
	return rez;
}
inline int get(char cmd, int a, int b) {
	if(cmd == 'A') return a & b;
	else if(cmd == 'O') return a | b;
	else if(cmd == 'X') return a ^ b;
	else if(cmd == 'a') return (a & b) ^ 1;
	else if(cmd == 'o') return (a | b) ^ 1;
	else if(cmd == 'x') return (a ^ b) ^ 1;
	else assert(false);
}
int dp[256][2];
void solve() {
	init();
	cin >> w >> n >> m;
	for(int i = 0; i < n; ++i) {
		int a = fetch<int>();
		int msk = 0;
		for(int i = 0; i < w; ++i) msk = setTrit(msk, i, ((a >> i) & 1) + 1);
		++cnt[msk];
		++freq[a];
	}
	int pw = 1;
	for(int j = 0; j < w; ++j) {
		for(int msk = 0; msk < pw3[w]; ++msk) {
			int v = mod3[msk / pw];
			if(v) {
				int msk2 = msk - pw * v;
				cnt[msk2] += cnt[msk];
			}
		}
		pw = pw + (pw << 1);
	}
	//for(int msk = 0; msk < pw3[w]; ++msk) dout << fmt(msk, w) << ": " << cnt[msk] << '\n';
	for(auto& cmd: string("AOXaox")) {
		int code = (int)cmd;
		for(int bt = 0; bt < 2; ++bt) {
			int zero = 0, one = 0;
			if(get(cmd, bt, 0) == 0) zero = 1;
			if(get(cmd, bt, 1) == 0) one = 1;
			if(zero && one) dp[code][bt] = 0;
			else if(zero)   dp[code][bt] = 1;
			else if(one)    dp[code][bt] = 2;
			else            dp[code][bt] = NIL;
		}
	}
	for(int que = 0; que < m; ++que) {
		auto func = fetch<string>();
		reverse(func.begin(), func.end());
		ll answ = 0;
		for(int a = 0; a < (1 << w); ++a) {
			if(!freq[a]) continue;
			int msk = 0, good = 1;
			int pw = 1;
			for(int j = 0; j < w; ++j) {
				int cur = dp[(int)func[j]][(a >> j) & 1];
				if(cur == NIL) {
					good = 0;
					break;
				}
				msk += cur * pw;
				pw = pw + (pw << 1);
			}
			if(good) answ += cnt[msk] * 1LL * freq[a];
		}
		cout << answ << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}