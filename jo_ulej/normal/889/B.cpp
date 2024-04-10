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
const int MAXN = (int)1e5 + 7;
const int A    = 26;
string S[MAXN];
int n;
vector<int> byChar[A];
int find(const string& str, char ch) {
	int j = 0;
	while(str[j] != ch) ++j;
	return j;
}
vector<pii> G[MAXN];
void add_edge(int v, int u, int d) {
	G[v].emplace_back(u, d);
}
int used[MAXN], a[MAXN], good = 1;
int comp[MAXN], compSz = 0;
void dfsik(int v) {
	used[v] = 1;
	comp[compSz++] = v;
	for(auto& ed: G[v]) {
		int u = ed.first;
		int d = ed.second;
		if(!used[u]) {
			a[u] = a[v] + d;
			dfsik(u);
		}
		if(a[u] != a[v] + d) good = 0;
	}
}
string parts[MAXN];
int cntParts = 0;
void solve() {
	cin >> n; for(int i = 0; i < n; ++i) {
		cin >> S[i];
	}
	for(int i = 0; i < n; ++i) {
		vector<int> cnt(A, 0);
		for(auto& ch: S[i]) {
			int code = ch - 'a';
			if(++cnt[code] > 1) {
				cout << "NO\n";
				return;
			}
			byChar[code].push_back(i);
		}
	}
	for(int code = 0; code < A; ++code) {
		char ch = 'a' + code;
		for(int i = 0; i < len(byChar[code]) - 1; ++i) {
			int p = byChar[code][i];
			int q = byChar[code][i + 1];
			int idxP = find(S[p], ch);
			int idxQ = find(S[q], ch);
			add_edge(p, q, idxP - idxQ);
			add_edge(q, p, idxQ - idxP);
		}
	}
	for(int v = 0; v < n; ++v) if(!used[v]) {
		compSz = 0;
		dfsik(v);
		if(good == 0) {
			cout << "NO\n";
			return;
		}
		int mn = 0;
		for(int ii = 0; ii < compSz; ++ii) {
			int u = comp[ii];
			mn = min(mn, a[u]);
		}
		int partSz = 0;
		for(int ii = 0; ii < compSz; ++ii) {
			int u = comp[ii];
			a[u] -= mn;
			partSz = max(partSz, a[u] + len(S[u]));
		}
		string part(partSz, '%');
		for(int ii = 0; ii < compSz; ++ii) {
			int u = comp[ii];
			for(int j = 0; j < len(S[u]); ++j) {
				if(part[a[u] + j] != '%' && part[a[u] + j] != S[u][j]) {
					cout << "NO\n";
					return;
				}

				part[a[u] + j] = S[u][j];
			}
		}
		parts[cntParts++] = part;
		DBG(part);
	}
	sort(parts, parts + cntParts);
	string rez; for(int i = 0; i < cntParts; ++i) rez += parts[i];
	cout << rez << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}