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
struct PresistentTree {
	struct Node {
		int sum = 0, left = NIL, right = NIL;
	};
	int sz;
	vector<Node> tree;
	PresistentTree(int _sz): sz(_sz) {
		tree.reserve(20 * sz);
	}
	inline int create() {
		tree.emplace_back();
		return len(tree) - 1;
	}
	inline int clone(int v) {
		int nv = create();
		if(v != NIL) tree[nv] = tree[v];
		return nv;
	}
	inline int read(int v) {
		return v == NIL ? 0 : tree[v].sum;
	}
	inline void relax(int v) {
		if(v != NIL) tree[v].sum = read(tree[v].left) + read(tree[v].right);
	}
	int change(int v, int tl, int tr, int pos, int val) {
		if(pos<tl||pos>tr) return v;
		v = clone(v);
		if(tl == tr) {
			tree[v].sum = val;
		} else {
			int tm = (tl+tr)/2;
			int nLeft = change(tree[v].left, tl, tm, pos, val);
			int nRight = change(tree[v].right, tm + 1, tr, pos, val);
			tree[v].left = nLeft;
			tree[v].right = nRight;
			relax(v);
		}
		return v;
	}
	int get(int v, int tl, int tr, int l, int r) {
		if(l<tl) l = tl;
		if(r>tr) r = tr;
		if(l>r) return 0;
		if(tl==l&&tr==r) {
			return read(v);
		} else {
			int tm = (tl+tr)/2;
			return get(tree[v].left, tl, tr, l, r) + get(tree[v].right, tm + 1, tr, l, r);
		}
	}
	inline int change(int v, int pos, int val) {
		return change(v, 0, sz - 1, pos, val);
	}
	inline int get(int v, int l, int r) {
		return get(v, 0, sz - 1, l, r);
	}
	int find(int v, int tl, int tr, int pos, int& k) {
		if(pos>tr||k<0) return 0;
		//DBG(v); DBG(tl); DBG(tr); DBG(pos); DBG(k);
		int cursum = read(v);
		if(pos<=tl&&cursum<=k) {
			k -= cursum;
			return tr - tl + 1;
		} else {
			if(tl == tr) return 0;
			int tm = (tl+tr)/2;
			if(pos > tm) {
				return find(v == NIL ? NIL : tree[v].right, tm + 1, tr, pos, k);
			}
			int Sz = tm-max(tl, pos)+1;
			int Left = find(v == NIL ? NIL : tree[v].left, tl, tm, pos, k);
			if(Left<Sz||k<0) return Left;
			int Right = find(v == NIL ? NIL : tree[v].right, tm + 1, tr, pos, k);
			return Left+Right;
		}
	}
	int findNext(int v, int pos, int k) {
		return pos + find(v, 0, sz - 1, pos, k);
	}
};
const int MAXN = (int)1e5 + 7;
int a[MAXN], n;
PresistentTree versionManager(MAXN);
int prv[MAXN], version[MAXN];
void solve() {
	cin >> n; for(int i = 0; i < n; ++i) cin >> a[i];
	memset(prv, NIL, sizeof(NIL));
	version[n] = NIL;
	//SAY("STARTED BUILDING SHIT");
	for(int i = n - 1; i >= 0; --i) {
		int c = a[i];
		version[i] = version[i + 1];
		if(prv[c] != NIL) {
			version[i] = versionManager.change(version[i], prv[c], 0);
		}
		version[i] = versionManager.change(version[i], i, 1);
		prv[c] = i;
	}
	//SAY("FINISHED BUILDING THE SHIT");
	for(int k = 1; k <= n; ++k) {
		int answ = 0;
		for(int i = 0; i < n; i = versionManager.findNext(version[i], i, k)) {
			//DBG(i);
			++answ;
		}
		cout << answ << ' ';
	}
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}