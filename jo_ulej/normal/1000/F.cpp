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
struct Tree {
	pii* tree = nullptr;
	int sz;
	Tree(int _sz): sz(_sz) {
		tree = new pii[2 * sz];
		for(int i = 0; i < 2 * sz; ++i) tree[i] = make_pair(INT_INF, INT_INF);
	}
	void change(int pos, pii val) {
		pos += sz;
		for(tree[pos] = val; pos > 1; pos /= 2) tree[pos/2] = min(tree[pos], tree[pos^1]);
	}
	pii get(int l, int r) {
		pii rez = make_pair(INT_INF, INT_INF);
		l += sz;
		r += sz + 1;
		while(l < r) {
			if(l&1) rez = min(rez, tree[l++]);
			if(r&1) rez = min(rez, tree[--r]);
			l /= 2, r /= 2;
		}
		return rez;
	}
};
const int MAXN = (int)5e5 + 7;
int a[MAXN], n, q;
int rez[MAXN], prv[MAXN];
vector<pii> Q[MAXN];
Tree tree(MAXN);
void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	memset(prv, NIL, sizeof(prv));
	cin >> q;
	for(int i = 0; i < q; ++i) {
		int l = fetch<int>() - 1;
		int r = fetch<int>() - 1;
		Q[r].emplace_back(l, i);
	}
	for(int i = 0; i < n; ++i) {
		int v = a[i];
		int j = prv[v];
		if(j != NIL) tree.change(j, {INT_INF, INT_INF});
		tree.change(i, {prv[v], v});
		prv[v] = i;
		for(auto& que: Q[i]) {
			int l = que.first;
			int id = que.second;
			auto PR = tree.get(l, i);
			if(PR.first < l) rez[id] = PR.second;
		}
	}
	for(int i = 0; i < q; ++i) cout << rez[i] << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}