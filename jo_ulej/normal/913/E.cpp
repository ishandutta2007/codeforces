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
const int T_VARX = 0;
const int T_VARY = 1;
const int T_VARZ = 2;
const int T_NOT  = 3;
const int T_AND  = 4;
const int T_OR   = 5;
struct Expr {
	int type;
	int left = NIL, right = NIL;
	int sz = NIL, msk = NIL;
};
vector<Expr> a;
int create(int type, int left, int right) {
	a.emplace_back();
	int v = len(a) - 1;
	a[v].type = type;
	a[v].left = left;
	a[v].right = right;
	if(type == T_VARX) {
		assert(left == NIL && right == NIL);
		a[v].msk = 0;
		a[v].sz = 1;
		for(int i = 0; i < 8; ++i) {
			int val = i>>2;
			if(val) a[v].msk |= 1<<i;
		}
	} else if(type == T_VARY) {
		assert(left == NIL && right == NIL);
		a[v].msk = 0;
		a[v].sz = 1;
		for(int i = 0; i < 8; ++i) {
			int val = (i>>1)&1;
			if(val) a[v].msk |= 1<<i;
		}
	} else if(type == T_VARZ) {
		assert(left == NIL && right == NIL);
		a[v].msk = 0;
		a[v].sz = 1;
		for(int i = 0; i < 8; ++i) {
			int val = i&1;
			if(val) a[v].msk |= 1<<i;
		}
	} else if(type == T_NOT) {
		assert(left != NIL && right == NIL);
		a[v].msk = 255 ^ a[left].msk;
		a[v].sz = a[left].sz + 1;
		if(a[left].type > type) a[v].sz += 2;
	} else if(type == T_AND || type == T_OR) {
		assert(left != NIL && right != NIL);
		a[v].msk = (type == T_AND ? a[left].msk&a[right].msk : a[left].msk|a[right].msk);
		a[v].sz = a[left].sz + 1 + a[right].sz;
		if(a[left].type > type) a[v].sz += 2;
		if(a[right].type > type) a[v].sz += 2;
	} else {
		assert(false);
	}
	return v;
}
int getSz(int v) {
	if(v == NIL) return INT_INF;
	return a[v].sz;
}
void toString(int v, string& out) {
	assert(v != NIL);
	int type = a[v].type;
	if(type == T_VARX) {
		out.push_back('x');
	} else if(type == T_VARY) {
		out.push_back('y');
	} else if(type == T_VARZ) {
		out.push_back('z');
	} else if(type == T_NOT) {
		int u = a[v].left;
		out.push_back('!');
		if(a[u].type > type) out.push_back('(');
		toString(u, out);
		if(a[u].type > type) out.push_back(')');
	} else if(type == T_AND || type == T_OR) {
		int l = a[v].left;
		int r = a[v].right;
		if(a[l].type > type) out.push_back('(');
		toString(l, out);
		if(a[l].type > type) out.push_back(')');
		out.push_back(type == T_AND ? '&' : '|');
		if(a[r].type > type) out.push_back('(');
		toString(r, out);
		if(a[r].type > type) out.push_back(')');
	}
}
int dp[256][6];
int lexcmp(int e, int o) {
	string s, t;
	toString(e, s);
	toString(o, t);
	return s < t;
}
int relax(int e) {
	if(e == NIL) return 0;
	int msk  = a[e].msk;
	int type = a[e].type;
	int sz   = a[e].sz;
	int old = dp[msk][type];
	int oldSz = getSz(old);
	if(sz < oldSz || (sz == oldSz && lexcmp(e, old))) {
		//dout << "update the msk=" << msk << '\n';
		dp[msk][type] = e;
		return 1;
	} else {
		return 0;
	}
}
void precalcDP() {
	for(int msk = 0; msk < 256; ++msk) for(int type = 0; type < 6; ++type) {
		dp[msk][type] = NIL;
	}
	for(auto& vart: {T_VARX, T_VARY, T_VARZ}) {
		int e = create(vart, NIL, NIL);
		relax(e);
	}
	int ch = 1;
	while(ch) {
		//SAY("PHASE");
		ch = 0;
		for(int msk = 0; msk < 256; ++msk) for(int type = 0; type < 6; ++type) {
			int e = dp[msk][type];
			if(e == NIL) continue;
			int ee = create(T_NOT, e, NIL);
			if(relax(ee)) ch = 1;
			for(int msk2 = 0; msk2 < 256; ++msk2) for(int type2 = 0; type2 < 6; ++type2) {
				int o = dp[msk2][type2];
				if(o == NIL) continue;
				int eo = create(T_AND, e, o);
				int oe = create(T_OR, e, o);
				if(relax(eo)) ch = 1;
				if(relax(oe)) ch = 1;
			}
		}
	}
	//SAY("FINISHED PRECALC");
}
void solve() {
	auto S = fetch<string>();
	assert(len(S) == 8);
	int msk = 0;
	for(int i = 0; i < 8; ++i) {
		if(S[i] == '1') msk |= 1<<i;
	}
	int best = NIL;
	for(int t = 0; t < 6; ++t) {
		if(dp[msk][t] == NIL) continue;
		int curBestSz = getSz(best);
		int newSz = getSz(dp[msk][t]);
		if(newSz < curBestSz || (newSz == curBestSz && lexcmp(dp[msk][t], best))) best = dp[msk][t];
	}
	string rez;
	toString(best, rez);
	cout << rez << '\n';
}

int main() {
	fast_io();
	precalcDP();
	int T = fetch<int>();
	while(T--) {
		solve();
	}

	return 0;
}