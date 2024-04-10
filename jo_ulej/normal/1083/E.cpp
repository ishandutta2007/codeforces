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
const ll MAXC = (int)1e9 + 789;
struct LiChao {
	struct Line {
		ll a, b;
		Line(): a(0), b(-LL_INF) {}
		Line(ll _a, ll _b): a(_a), b(_b) {}
		ll get(ll pt) {
			return a * pt + b;
		}
	};
	struct Node {
		Line line;
		int left = NIL, right = NIL;
	};
	vector<Node> tree;
	int create() {
		tree.emplace_back();
		return len(tree) - 1;
	}
	#define check(X) if((X) == NIL) { int nv = create(); X = nv; }
	int rootik = NIL;
	LiChao() {
		rootik = create();
	}
	void insertLine(int v, ll tl, ll tr, Line line) {
		while(true) {
			ll tm = (tl + tr) / 2LL;
			int betterOnL = line.get(tl) > tree[v].line.get(tl);
			int betterOnM = line.get(tm) > tree[v].line.get(tm);
			int betterOnR = line.get(tr) > tree[v].line.get(tr);
			if(!betterOnL && !betterOnR) break;
			if(betterOnL && betterOnR) {
				tree[v].line = line;
				break;
			}
			if(betterOnL && betterOnM) {
				swap(tree[v].line, line);
				tl = tm + 1;
				check(tree[v].right);
				v = tree[v].right;
			} else if(betterOnR && betterOnM) {
				swap(tree[v].line, line);
				tr = tm;
				check(tree[v].left);
				v = tree[v].left;
			} else if(betterOnL) {
				tr = tm;
				check(tree[v].left);
				v = tree[v].left;
			} else if(betterOnR) {
				tl = tm + 1;
				check(tree[v].right);
				v = tree[v].right;
			} else {
				assert(false);
			}
		}
	}
	ll getOpt(int v, ll tl, ll tr, ll pt) {
		ll best = -LL_INF;
		while(v != NIL) {
			best = max(best, tree[v].line.get(pt));
			if(tl == tr) break;
			ll tm = (tl + tr) / 2LL;
			if(pt <= tm) {
				tr = tm;
				v = tree[v].left;
			} else {
				tl = tm + 1;
				v = tree[v].right;
			}
		}
		return best;
	}
	void insertLine(Line line) {
		insertLine(rootik, 0, MAXC - 1, line);
	}
	ll getOpt(ll pt) {
		return getOpt(rootik, 0, MAXC - 1, pt);
	}
};
const int MAXN = (int)1e6 + 7;
struct SQ {
	ll x, y, a;
	bool operator<(const SQ& other) const {
		return x < other.x;
	}
};
SQ arr[MAXN];
int n;
ll dp[MAXN];
void solve() {
	cin >> n; for(int i = 0; i < n; ++i) cin >> arr[i].x >> arr[i].y >> arr[i].a;
	sort(arr, arr + n); ll answ = 0;
	LiChao lichao;
	for(int i = 0; i < n; ++i) {
		dp[i] = arr[i].x * arr[i].y;
		/*for(int j = 0; j < i; ++j) {
			dp[i] = max(dp[i], dp[j] + arr[i].y * (arr[i].x - arr[j].x));
		}*/
		dp[i] = max(dp[i], lichao.getOpt(arr[i].y) + arr[i].x * arr[i].y);
		dp[i] -= arr[i].a;
		answ = max(answ, dp[i]);
		lichao.insertLine(LiChao::Line(-arr[i].x, dp[i]));
		//dout << i << ' ' << dp[i] << '\n';
	}
	cout << answ << '\n';
}
using Line = LiChao::Line;
void stress() {
	vector<Line> lines;
	LiChao lichao;
	for(int i = 0; i < 1000; ++i) {
		lines.emplace_back(randint(0, 100), randint(0, 100));
		lichao.insertLine(lines.back());
		for(ll pt = 0; pt <= 100; ++pt) {
			ll mx = -LL_INF;
			for(auto& line: lines) mx = max(mx, line.get(pt));
			ll mx2 = lichao.getOpt(pt);
			if(mx != mx2) {
				for(auto& line: lines) {
					dout << line.a << ' ' << line.b << '\n';
				}
				DBG(pt); DBG(mx); DBG(mx2);
				assert(false);
			}
		}
	}
	SAY("STRESS SUCC");
}
int main() {
	fast_io();
	//stress();
	solve();

	return 0;
}