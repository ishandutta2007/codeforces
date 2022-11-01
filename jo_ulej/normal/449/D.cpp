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
const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}
const int N  = 20;
const int FMSK = (1 << N) - 1;
const int SZ = (1 << N) + 7;
int freq[SZ], answ = 0, n;
int pw2[SZ];
void solve() {
	pw2[0] = 1; for(int i = 1; i < SZ; ++i) pw2[i] = add(pw2[i - 1], pw2[i - 1]);
	cin >> n; for(int i = 0; i < n; ++i) {
		int msk = fetch<int>();
		++freq[msk ^ FMSK];
	}
	for(int j = 0; j < N; ++j) {
		int bit = 1<<j;
		for(int msk = 0; msk <= FMSK; ++msk) {
			if(msk&bit) {
				freq[msk] += freq[msk^bit];
			}
		}
	}
	for(int msk = 0; msk <= FMSK; ++msk) {
		int flag = 0;
		for(int i = 0; i < N; ++i) flag ^= (msk>>i)&1;
		if(flag) {
			answ = sub(answ, pw2[freq[msk ^ FMSK]]);
		} else {
			answ = add(answ, pw2[freq[msk ^ FMSK]]);
		}
	}
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}