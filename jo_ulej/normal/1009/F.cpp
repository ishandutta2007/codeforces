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
const int MAXN = (int)1e6 + 7;
vector<int> G[MAXN];
int n;
struct Data {
	map<int, int> cnt;
	set<pii> ord;
	int getSz() {
		return len(cnt);
	}
	int getAnsw() {
		assert(!ord.empty());
		auto iter = ord.begin();
		return iter->second;
	}
};
Data* glue(Data* lhs, Data* rhs) {
	if(lhs == nullptr) return rhs;
	if(rhs == nullptr) return lhs;
	if(lhs->getSz() > rhs->getSz()) swap(lhs, rhs);
	for(auto& pr: lhs->cnt) {
		int depth = pr.first;
		int count = pr.second;
		rhs->cnt[depth] += count;
		rhs->ord.emplace(-(rhs->cnt[depth]), depth);
	}
	delete lhs;
	return rhs;
}
int answ[MAXN];
Data* dfs(int v, int pa, int level) {
	Data* rez = nullptr;
	for(auto& u: G[v]) if(u != pa) {
		rez = glue(rez, dfs(u, v, level + 1));
	}
	if(rez == nullptr) rez = new Data();
	rez->cnt[level] += 1;
	rez->ord.emplace(-rez->cnt[level], level);
	answ[v] = rez->getAnsw() - level;
	return rez;
}
void solve() {
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		G[v].push_back(u);
		G[u].push_back(v);
	}
	dfs(0, NIL, 0);
	for(int v = 0; v < n; ++v) {
		cout << answ[v] << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}