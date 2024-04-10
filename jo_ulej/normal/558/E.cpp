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
struct Stupid {
	int* a = nullptr;
	int sz = 0;
	Stupid(int _sz): sz(_sz) {
		a = new int[sz];
		memset(a, 0, sizeof(a[0]) * sz);
	}
	void change(int l, int r, int x) {
		for(int i = l; i <= r; ++i) a[i] = x;
	}
	int get(int l, int r) {
		int rez = 0;
		for(int i = l; i <= r; ++i) rez += a[i];
		return rez;
	}
};
struct Tree {
	int* count = nullptr;
	int* mod = nullptr;
	int sz = 0;
	Tree(int _sz): sz(_sz) {
		count = new int[4 * sz];
		mod   = new int[4 * sz];
		memset(count, 0, sizeof(count[0]) * 4 * sz);
		memset(mod, NIL, sizeof(mod[0]) * 4 * sz);
	}
	inline int read(int v, int tl, int tr) {
		return mod[v] == NIL ? count[v] : (tr - tl + 1) * mod[v];
	}
	inline void push(int v, int tl, int tr) {
		if(mod[v] == NIL) return;
		count[v] = (tr - tl + 1) * mod[v];
		mod[2*v+1] = mod[v];
		mod[2*v+2] = mod[v];
		mod[v] = NIL;
	}
	inline void relax(int v, int tl, int tr, int tm) {
		count[v] = read(2*v+1, tl, tm) + read(2*v+2, tm + 1, tr);
	}
	void change(int v, int tl, int tr, int l, int r, int x) {
		if(l<tl) l = tl;
		if(r>tr) r = tr;
		if(l>r) return; 
		if(tl==l&&tr==r) {
			mod[v] = x;
		} else {
			int tm = (tl+tr)/2;
			push(v, tl, tr);
			change(2*v+1, tl, tm, l, r, x);
			change(2*v+2, tm + 1, tr, l, r, x);
			relax(v, tl, tr, tm);
		}
	}
	int get(int v, int tl, int tr, int l, int r) {
		if(l<tl) l = tl;
		if(r>tr) r = tr;
		if(l>r) return 0;
		if(tl==l&&tr==r) {
			return read(v, tl, tr);
		} else {
			int tm = (tl+tr)/2;
			push(v, tl, tr);
			return get(2*v+1, tl, tm, l, r) + get(2*v+2, tm + 1, tr, l, r);
		}
	}
	inline void change(int l, int r, int x) {
		change(0, 0, sz - 1, l, r, x);
	}
	inline int get(int l, int r) {
		return get(0, 0, sz - 1, l, r);
	}
};
const int MAXN = (int)1e5 + 7;
const int A    = 26;
int n, q;
string S;
vector<Tree> trees;
int cnt[A];
void solve() {
	cin >> n >> q >> S;
	for(int code = 0; code < A; ++code) {
		trees.emplace_back(MAXN);
		for(int i = 0; i < n; ++i) trees[code].change(i, i, S[i] - 'a' == code);
	}
	while(q--) {
		int l = fetch<int>() - 1;
		int r = fetch<int>() - 1;
		int t = fetch<int>();
		for(int code = 0; code < A; ++code) cnt[code] = trees[code].get(l, r);
		for(int code = 0; code < A; ++code) trees[code].change(l, r, 0);
		//(dout << "cnt: ").printArray(cnt, cnt + A);
		int pref = l;
		if(t) {
			for(int code = 0; code < A; ++code) {
				if(cnt[code] > 0) trees[code].change(pref, pref + cnt[code] - 1, 1);
				pref += cnt[code];
			}
		} else {
			for(int code = A - 1; code >= 0; --code) {
				if(cnt[code] > 0) trees[code].change(pref, pref + cnt[code] - 1, 1);
				pref += cnt[code];
			}
		}
		assert(pref == r + 1);
	}
	for(int code = 0; code < A; ++code) {
		for(int i = 0; i < n; ++i) if(trees[code].get(i, i)) S[i] = 'a' + code;
	}
	cout << S << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}