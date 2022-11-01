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
struct Node {
	int val = 0, prior = NIL, left = NIL, right = NIL;
	int sz = 1;
};
vector<Node> T;
int create(int value) {
	T.emplace_back();
	int v = len(T) - 1;
	T[v].val = value;
	T[v].prior = randint(0, INT_INF);
	return v;
}
int getsz(int v) {
	return v == NIL ? 0 : T[v].sz;
}
void upd(int v) {
	if(v != NIL) {
		T[v].sz = getsz(T[v].left) + 1 + getsz(T[v].right);
	}
}
int merge(int v, int u) {
	if(v == NIL) return u;
	if(u == NIL) return v;
	if(T[v].prior > T[u].prior) {
		T[v].right = merge(T[v].right, u);
		upd(v);
		return v;
	} else {
		T[u].left = merge(v, T[u].left);
		upd(u);
		return u;
	}
}
pii split(int v, int pref) {
	if(v == NIL) return make_pair(NIL, NIL);
	int lsz = getsz(T[v].left);
	if(pref <= lsz) {
		auto pr = split(T[v].left, pref);
		T[v].left = pr.second;
		upd(v);
		return make_pair(pr.first, v);
	} else {
		auto pr = split(T[v].right, pref - lsz - 1);
		T[v].right = pr.first;
		upd(v);
		return make_pair(v, pr.second);
	}
}
void _show(int v) {
	if(v == NIL) return;
	_show(T[v].left);
	cout << T[v].val;
	_show(T[v].right);
}
void show(int v) {
	_show(v);
	cout << '\n';
}
const int MAXN = (int)1e6 + 7;
int a[MAXN], q, n;
void solve() {
	int root = NIL;
	cin >> q >> n;
	for(int i = 0; i < n; ++i) a[i] = fetch<int>() - 1;
	a[n] = MAXN;
	for(int i = 0; i < q; ++i) {
		int val = fetch<int>();
		if(val != NIL) {
			root = merge(root, create(val));
		} else {
			int cnt = 0;
			int sz = getsz(root);
			while(a[cnt] < sz) ++cnt;
			while(cnt > 0) {
				int pos = a[--cnt];
				auto ABC = split(root, pos);
				auto BC = split(ABC.second, 1);
				int A = ABC.first;
				int C = BC.second;
				root = merge(A, C);
			}
		}
		//show(root);
	}
	if(root == NIL) {
		cout << "Poor stack!\n";
	} else {
		show(root);
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}