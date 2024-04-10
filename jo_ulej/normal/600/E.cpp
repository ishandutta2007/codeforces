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
const int MAXN = (int)1e5 + 7;
const int T    = 316;
vector<int> G[MAXN];
int a[MAXN], n;
ll sum[MAXN], blockSum[MAXN];
void change(int pos, ll val) {
	sum[pos] += val;
	blockSum[pos / T] += val;
}
ll get() {
	for(int i = (MAXN - 1) / T - 1; i >= 0; --i) {
		if(blockSum[i] > 0) {
			for(int j = (i + 1) * T - 1; j >= i * T; --j) {
				if(sum[j] > 0) return sum[j];
			}
		}	
	}
	return 0;
}
int ord[MAXN], ordSz = 0;
struct Query {
	int l, r, v;
	bool operator<(const Query& other) const {
		return make_pair(l / T, r) < make_pair(other.l / T, other.r);
	}
};
Query queries[MAXN];
void dfs(int v, int pa) {
	ord[ordSz++] = v;
	int l = ordSz - 1;
	for(auto& u: G[v]) if(u != pa) dfs(u, v);
	int r = ordSz - 1;
	queries[v] = {l, r, v};
}
int cnt[MAXN];
void insert(int c) {
	if(cnt[c] > 0) change(cnt[c], -c);
	++cnt[c];
	change(cnt[c], +c);
}
void erase(int c) {
	change(cnt[c], -c);
	--cnt[c];
	if(cnt[c] > 0) change(cnt[c], +c);
}
void insertVertex(int v) {
	insert(a[v]);
}
void eraseVertex(int v) {
	erase(a[v]);
}
ll answ[MAXN];
void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].emplace_back(u);
		G[u].emplace_back(v);
	}
	dfs(0, NIL);
	sort(queries, queries + n);
	int L = 0, R = 0;
	for(int i = 0; i < n; ++i) {
		auto& q = queries[i];
		while(L > q.l) insertVertex(ord[--L]);
		while(R < q.r + 1) insertVertex(ord[R++]);
		while(L < q.l) eraseVertex(ord[L++]);
		while(R > q.r + 1) eraseVertex(ord[--R]);
		answ[q.v] = get();
	}
	for(int v = 0; v < n; ++v) cout << answ[v] << ' ';
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}