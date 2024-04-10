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
const int A = 3;
struct Trie {
	struct Node {
		int go[A];
		int cnt;
		Node(): cnt(0) {
			memset(go, NIL, sizeof(go));
		}
	};
	vector<Node> tree;
	int root = NIL;
	int create() {
		tree.emplace_back();
		return len(tree) - 1;
	}
	Trie() {
		root = create();
	}
	int count(const string& s) {
		int v = root;
		for(auto& ch: s) {
			int code = ch - 'a';
			v = tree[v].go[code];
			if(v == NIL) return 0;
		}
		return tree[v].cnt;
	}
	void insert(const string& s) {
		int v = root;
		for(auto& ch: s) {
			int code = ch - 'a';
			if(tree[v].go[code] == NIL) {
				int nv = create();
				tree[v].go[code] = nv;
			}
			v = tree[v].go[code];
		}
		++tree[v].cnt;
	}
};
void solve() {
	int n = fetch<int>();
	int k = fetch<int>();
	auto S = fetch_vec<string>(n);
	for(auto& s: S) {
		for(auto& ch: s) {
			if(ch == 'S') ch = 'a';
			if(ch == 'E') ch = 'b';
			if(ch == 'T') ch = 'c';
		}
	}
	Trie trie;
	for(auto& s: S) trie.insert(s);
	int answ = 0;
	string p(k, '%');
	for(int i = 0; i < n; ++i) for(int j = 0; j < i; ++j) {
		for(int pos = 0; pos < k; ++pos) {
			if(S[i][pos] == S[j][pos]) {
				p[pos] = S[i][pos];
			} else {
				p[pos] = 'a' ^ 'b' ^ 'c' ^ S[i][pos] ^ S[j][pos];
			}
		}
		answ += trie.count(p);
	}
	answ /= 3;
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}