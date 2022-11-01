#pragma GCC optimize("Ofast,unroll-loops")

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
const int LOG = 30;
struct Trie {
	struct Node {
		int go[2];
		int cnt = 0;
	};
	Node* tree = nullptr;
	int treeSz = 0;
	inline int create() {
		tree[treeSz].go[0] = tree[treeSz].go[1] = NIL;
		return treeSz++;
	}
	int rootik = NIL;
	Trie(int Sz) {
		tree = new Node[LOG * Sz];
		rootik = create();
	}
	inline void change(int val, int x) {
		int v = rootik;
		tree[v].cnt += x;
		for(int j = LOG - 1; j >= 0; --j) {
			int bit = (val>>j)&1;
			if(tree[v].go[bit] == NIL) tree[v].go[bit] = create();
			v = tree[v].go[bit];
			tree[v].cnt += x;
		}
	}
	inline int getCnt(int v) {
		return v == NIL ? 0 : tree[v].cnt;
	}
	inline int getMn(int val) {
		int v = rootik;
		int rez = 0;
		for(int j = LOG - 1; j >= 0; --j) {
			if(getCnt(v) == 0) break;
			int bit = (val>>j)&1;
			if(getCnt(tree[v].go[bit])) {
				v = tree[v].go[bit];
			} else {
				rez |= 1<<j;
				v = tree[v].go[bit^1];
			}
		}
		return rez;
	}
	inline void setZero() {
		for(int i = 0; i < treeSz; ++i) {
			tree[i].cnt = 0;
		}
	}
};
struct DSU {
	int* pa = nullptr;
	int* cnt = nullptr;
	int sz = 0;
	DSU(int _sz): sz(_sz) {
		pa = new int[sz];
		cnt = new int[sz];
		for(int i = 0; i < sz; ++i) {
			pa[i] = i;
			cnt[i] = 1;
		}
	}	
	int getParent(int v) {
		return (pa[v] == v ? v : pa[v] = getParent(pa[v]));
	}
	inline int connect(int v, int u) {
		v = getParent(v);
		u = getParent(u);
		if(v == u) return 0;
		if(cnt[v] > cnt[u]) swap(v, u);
		pa[v] = u;
		cnt[u] += cnt[v];
		return 1;
	}
};
const int MAXN = (int)2e5 + 77;
int W[MAXN], n;
pii a[MAXN];
inline void solve() {
	cin >> n; for(int i = 0; i < n; ++i) {
		cin >> W[i];
	}
	sort(W, W + n);
	ll answ = 0;
	DSU dsu(n);
	vector<pair<int, pii>> S;
	S.resize(n);
	Trie tr(MAXN);
	for(int i = 0; i < n; ++i) tr.change(W[i], +1);
	tr.setZero();
	while(true) {
		for(int i = 0; i < n; ++i) {
			a[i] = make_pair(dsu.getParent(i), i);
		}
		sort(a, a + n);
		if(a[0].first == a[n - 1].first) break;
		int i = 0;
		S.clear();
		for(int i = 0; i < n; ++i) {
			tr.change(W[i], +1);
			S.emplace_back(W[i], make_pair(dsu.getParent(i), i));
		}
		sort(S.begin(), S.end());
		S.erase(unique(S.begin(), S.end()), S.end());
		for(int c = 0; c < n; ++c) {
			DBG(c);
			while(i < n && a[i].first < c) ++i;
			if(i < n && a[i].first == c) {
				int bestCost = INT_INF;
				int bestV = NIL, bestU = NIL;
				int j = i;
				while(j < n && a[j].first == c) {
					int p = a[j].second;
					tr.change(W[p], -1);
					++j;
				}
				j = i;
				while(j < n && a[j].first == c) {
					int p = a[j].second;
					int rez = tr.getMn(W[p]);
					if(rez < bestCost) {
						bestCost = rez;
						bestV = p;
					}
					++j;
				}
				j = i;
				while(j < n && a[j].first == c) {
					int p = a[j].second;
					tr.change(W[p], +1);
					++j;
				}
				i = j;
				int Wj = bestCost^W[bestV];
				auto iter = lower_bound(S.begin(), S.end(), make_pair(Wj, make_pair(NIL, NIL)));
				if(iter->second.first == c) {
					if(iter == S.end()) --iter;
					else ++iter;
				}
				//assert(iter->second.first != c);
				bestU = iter->second.second;
				if(dsu.connect(bestV, bestU)) {
					answ += bestCost;
				}
			}
		}
		tr.setZero();
	}
	cout << answ << '\n';
}
int main() {
	fast_io();
	solve();

	return 0;
}