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
const int N = 8;
const int M = 5;
const int D = 500;
const int SZ = 250 * 1000;
vector<int> decks[D];
int go[D][N][M];
int cntDecks = 0, cntStates = NIL;
int co[M];
void gen(int val) {
	int sum = 0;
	for(int i = 0; i < val; ++i) sum += co[i];
	if(sum > N) return;
	if(val == M) {
		if(sum != N) return;
		for(int i = 0; i < M; ++i) {
			for(int j = 0; j < co[i]; ++j) decks[cntDecks].push_back(i);
		}
		++cntDecks;
		return;
	}
	for(co[val] = 0; co[val] <= N; ++co[val]) {
		gen(val + 1);
	}
}
int G[SZ][N][N], out[SZ], in[SZ], ptr[SZ], dp[SZ];
int* H[SZ];
inline int find(vector<int> de) {
	sort(de.begin(), de.end());
	auto iter = lower_bound(decks, decks + cntDecks, de);
	if(iter == decks + cntDecks || *iter != de) assert(false);
	return iter - decks;
}
inline int convert(int i, int j) {
	return cntDecks * i + j;
}
int Q[SZ], head = 0;
void init() {
	gen(0);
	sort(decks, decks + cntDecks);
	//(dout << "decks: ").printArray(decks, decks + cntDecks);
	cntStates = cntDecks * cntDecks;
	//DBG(cntDecks); DBG(cntStates);
	for(int i = 0; i < cntDecks; ++i) {
		for(int pos = 0; pos < N; ++pos) {
			for(int add = 0; add < M; ++add) {
				auto cpy = decks[i];
				cpy[pos] += add;
				cpy[pos] %= M;
				go[i][pos][add] = find(cpy);
			}
		}
	}
	for(int i = 0; i < cntDecks; ++i) for(int j = 0; j < cntDecks; ++j) {
		int v = convert(i, j);
		H[v] = nullptr;
		for(int pos = 0; pos < N; ++pos) for(int qos = 0; qos < N; ++qos) {
			G[v][pos][qos] = NIL;
		}
	}
	int cntEdges = 0;
	for(int i = 0; i < cntDecks; ++i) {
		for(int j = 0; j < cntDecks; ++j) {
			int v = convert(i, j);
			assert(v >= 0 && v < cntStates);
			for(int pos = 0; pos < N; ++pos) {
				for(int qos = 0; qos < N; ++qos) {
					if(decks[i][pos] == 0 || decks[j][qos] == 0) continue;
					int add = decks[j][qos];
					int i2 = go[i][pos][add];
					int j2 = j;
					swap(i2, j2);
					int u = convert(i2, j2);
					G[v][pos][qos] = u;
					++out[v]; ++in[u];
					++cntEdges;
				}
			}
		}
	}
	for(int v = 0; v < cntStates; ++v) if(in[v]) {
		H[v] = new int[in[v]];
	}
	for(int v = 0; v < cntStates; ++v) for(int pos = 0; pos < N; ++pos) for(int qos = 0; qos < N; ++qos) {
		int u = G[v][pos][qos];
		if(u == NIL) continue;
		int& ii = ptr[u];
		H[u][ii++] = v;
	}
	//DBG(cntEdges);
	for(int i = 0; i < cntDecks; ++i) for(int j = 0; j < cntDecks; ++j) {
		int v = convert(i, j);
		if(i == 0 && j == 0) continue;
		if(i == 0) dp[v] = +1;
		if(j == 0) dp[v] = -1;
		if(dp[v] != 0) Q[head++] = v;
	}
	for(int j = 0; j < head; ++j) {
		int v = Q[j];
		if(dp[v] == +1) {
			for(int ii = 0; ii < in[v]; ++ii) {
				int u = H[v][ii];
				--out[u];
				if(out[u] == 0 && dp[u] == 0) {
					dp[u] = -1;
					Q[head++] = u;
				}
			}
		} else if(dp[v] == -1) {
			for(int ii = 0; ii < in[v]; ++ii) {
				int u = H[v][ii];
				if(dp[u] == 0) {
					dp[u] = +1;
					Q[head++] = u;
				}
			}
		}
	}
	/*int cntWin = 0, cntLose = 0, cntDraw = 0;
	for(int v = 0; v < cntStates; ++v) {
		int i = v / cntDecks;
		int j = v % cntDecks;
		if(i == 0 || j == 0) continue;
		if(dp[v] == -1) ++cntLose;
		if(dp[v] == 0) ++cntDraw;
		if(dp[v] == +1) ++cntWin;
		int mx = -1;
		for(int pos = 0; pos < N; ++pos) for(int qos = 0; qos < N; ++qos) {
			int u = G[v][pos][qos];
			if(u == NIL) continue;
			mx = max(mx, -dp[u]);
		}
		if(mx != dp[v]) {
			DBG(v);
			DBG(i); DBG(j);
			DBG(decks[i]); DBG(decks[j]);
			DBG(dp[v]); DBG(mx); DBG(out[v]);
		}
		assert(mx == dp[v]);
	}*/
	//DBG(cntWin); DBG(cntDraw); DBG(cntLose);
	//SAY("FINISHED INIT");
}
void solve() {
	int who = fetch<int>();
	auto Left = fetch_vec<int>(N);
	auto Right = fetch_vec<int>(N);
	int i = find(Left);
	int j = find(Right);
	if(who) swap(i, j);	
	int v = convert(i, j);
	//DBG(dp[v]);
	if(dp[v] == +1) {
		cout << (who ? "Bob\n" : "Alice\n");
	} else if(dp[v] == -1) {
		cout << (who ? "Alice\n" : "Bob\n");
	} else {
		cout << "Deal\n";
	}
}
int main() {
	fast_io();
	init();
	int T = fetch<int>();
	while(T--) {
		solve();
	}

	return 0;
}