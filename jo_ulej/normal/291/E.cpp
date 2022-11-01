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
const int MAXN = (int)3e5 + 7;
const int A    = 26;
string P;
int piFunc[MAXN], go[MAXN][A];
void calc() {
	int sz = len(P);
	P.push_back('#');
	for(int i = 1; i < sz; ++i) {
		int j = piFunc[i - 1];
		while(j > 0 && P[j] != P[i]) {
			j = piFunc[j - 1];
		}
		piFunc[i] = (P[j] == P[i]) + j;
	}
	for(int p = 0; p <= sz; ++p) for(int code = 0; code < A; ++code) {
		char ch = 'a' + code;
		if(P[p] == ch) {
			go[p][code] = p + 1;
		} else if(p > 0) {
			go[p][code] = go[piFunc[p - 1]][code];
		} else {
			go[p][code] = 0;
		}
		//dout << p << ' ' << ch << ' ' << go[p][code] << '\n';
	}
	P.pop_back();
}
int St[MAXN], head = 0;
void append(char ch) {
	//dout << "@apennd: " << ch << '\n';
	int code = ch - 'a';
	int last = St[head - 1];
	St[head++] = go[last][code];
}
void undo() {
	//dout << "@undo:\n";
	--head;
}
vector<pair<int, char>> G[MAXN];
int n, rootik = NIL;
int answ = 0;
void dfsik(int v) {
	if(St[head-1]==len(P)) ++answ;
	for(auto& ed: G[v]) {
		int u = ed.first;
		char ch = ed.second;
		append(ch);
		dfsik(u);
		undo();
	}
}
void solve() {
	cin >> n;
	int oldN = n;
	for(int i = 1; i < oldN; ++i) {
		int v = i;
		int pa = fetch<int>() - 1;
		auto str = fetch<string>();
		while(len(str)>1) {
			char ch = str.back(); str.pop_back();
			int nv = n++;
			G[nv].emplace_back(v, ch);
			v = nv;
		}
		G[pa].emplace_back(v, str.back());
	}
	cin >> P;
	calc();
	St[head++] = 0;
	rootik = 0;
	dfsik(rootik);
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}