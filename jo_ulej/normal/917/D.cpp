#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")

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

#define dout   ___debug::instance

using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const set<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const map<T, S>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const multiset<T>& v) { for(auto el: v) cout << el << " "; return os; }
namespace ___debug {
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

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(2e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }
template<typename T> inline void makeUnique(vector<T>& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
const int MOD = (int)1e9 + 7;
const int INV2 = (MOD + 1) / 2;
inline int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}
inline int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}
inline int mult(int x, int y) {
	ll r = x * 1LL * y;
	if(r > MOD) r %= MOD;
	return (int)r;
}
int binpow(int x, int y) {
	if(x == 1 || y == 0) return 1;
	if(x == 0) return 0;
	int rez = binpow(x, y >> 1);
	rez = mult(rez, rez);
	if(y & 1) rez = mult(rez, x);
	return rez;
}
inline int divide(int x, int y) {
	int r = mult(x, binpow(y, MOD - 2));
	assert(mult(y, r) == x);
	return r;
}
const int MAXN = 107;
int edge[MAXN][MAXN];
int n;
int A[MAXN][MAXN];
int B[MAXN][MAXN], answ[MAXN];
inline void dumpMatrix() {
#ifdef __LOCAL
	cout << "####\n";
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) cout << B[i][j] << ' ';
		cout << " | " << B[i][n];
		cout << '\n';
	}
	cout << "####\n";
#endif
}
inline int _GetValInPoint(int x) {
	assert(x >= 0 && x < MOD);
	for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
		if(i == j) {
			A[i][j] = 0;
			for(int v = 0; v < n; ++v) {
				if(v == i) continue;
				A[i][j] = add(A[i][j], edge[i][v] ? x : 1);
			}
		} else {
			A[i][j] = sub(0, edge[i][j] ? x : 1);
		}
	}
	--n;
	//dumpMatrix();
	int rez = 1;
	for(int i = 0; i < n; ++i) {
		{
			int r = i;
			while(r < n && A[r][i] == 0) ++r;
			if(r >= n) return 0;
			for(int j = 0; j < n; ++j) swap(A[r][j], A[i][j]);
		}
		int z = A[i][i];
		assert(z != 0);
		rez = mult(rez, z);
		z = divide(1, z);
		for(int j = 0; j < n; ++j) A[i][j] = mult(A[i][j], z);
		//dumpMatrix();
		for(int r = i + 1; r < n; ++r) {
			z = A[r][i];
			for(int j = 0; j < n; ++j) A[r][j] = sub(A[r][j], mult(z, A[i][j]));
		}
		//dumpMatrix();
	}
	for(int i = 0; i < n; ++i) rez = mult(rez, A[i][i]);
	return rez;
}
inline int GetValInPoint(int x) {
	int r = _GetValInPoint(x);
   	++n;
	return r;	
}
void FindCoeffs() {
	dumpMatrix();
	for(int i = 0; i < n; ++i) {
		{
			int r = i;
			while(r < n && B[r][i] == 0) ++r;
			if(r >= n) assert(false);
			for(int j = 0; j < n; ++j) swap(B[r][j], B[i][j]);
		}
		int z = B[i][i];
		assert(z != 0);
		z = divide(1, z);
		for(int j = 0; j <= n; ++j) B[i][j] = mult(B[i][j], z);
		dumpMatrix();
		for(int r = i + 1; r < n; ++r) {
			z = B[r][i];
			for(int j = 0; j <= n; ++j) B[r][j] = sub(B[r][j], mult(z, B[i][j]));
		}
		dumpMatrix();
	}
	for(int i = n - 1; i >= 0; --i) {
		answ[i] = B[i][n];
		for(int j = i + 1; j < n; ++j) answ[i] = sub(answ[i], mult(B[i][j], answ[j]));
	}
}
void solve() {
	cin >> n;
	for(int id = 0; id < n - 1; ++id) {
		int v = fetch<int>() - 1;
		int u = fetch<int>() - 1;
		edge[v][u] = edge[u][v] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		int r = GetValInPoint(i);
		B[i - 1][n] = r; 
		int pw = 1;
		for(int j = 0; j < n; ++j) {
			B[i - 1][j] = pw;
			pw = mult(pw, i);
		}
	}
	FindCoeffs();
	for(int k = 0; k < n; ++k) cout << answ[k] << ' ';
	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}