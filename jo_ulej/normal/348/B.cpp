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
const ll  MX   = 1LL << 50LL;
const ld  MX2  = (ld)MX;
vector<int> G[MAXN];
int n, root;
ll a[MAXN];
ll GCD(ll x, ll y) {
	return (x == 0 ? y : GCD(y%x, x));
}
int check(ll lhs, ll rhs) {
	return ((ld)lhs) * ((ld)rhs) < MX2;
}
ll findDiv(int v, int prv) {
	ll rez = 1, w = 0;
	for(auto& u: G[v]) if(u != prv) {
		++w;
		ll rez2 = findDiv(u, v);
		if(rez2 == MX) return MX;
		ll g = GCD(rez, rez2);
		if(check(rez, rez2/g)) {
			rez = rez*(rez2/g);
		} else {
			return MX;
		}
	}
	if(w > 1) {
		if(check(rez, w)) {
			rez *= w;
		} else {
			return MX;
		}
	}
	return rez;
}
int dfsCheck(int v, int prv, ll cur) {
	int cnt = 0;
	for(auto& u: G[v]) if(u != prv) {
		++cnt;
	}
	if(cnt == 0) {
		return cur <= a[v];
	} else {
		if(cur % cnt != 0) return 0;
		for(auto& u: G[v]) if(u != prv) {
			int rez = dfsCheck(u, v, cur/cnt);
			if(!rez) return rez;
		}
		return 1;
	}
}
void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].emplace_back(u);
		G[u].emplace_back(v);
	}
	root = 0;
	ll d = findDiv(root, NIL);
	DBG(d);
	ll sum = 0;
	for(int i = 0; i < n; ++i) sum += a[i];
	if(d == MX) {
		cout << sum << '\n';
		return;
	}
	ll low = 0, high = sum / d + 1;
	while(high - low > 1) {
		ll mid = (low + high) / 2;
		if(dfsCheck(root, NIL, mid * d)) {
			low = mid;
		} else {
			high = mid;
		}
	}
	DBG(sum); DBG(low);
	cout << sum - low * d << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}