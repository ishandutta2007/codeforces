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
	#define DBG(X) cout << #X << "=" << (X) << '\n';
	#define SAY(X) cout << (X) << '\n';
#else
	#define DBG(X)
	#define SAY(X)
#endif
 
using namespace std;

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
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int MAXN = (int)2e5 + 777;
int k[3], n = 0;
int a[MAXN], pref[MAXN], suff[MAXN];
int prefmax[MAXN], suffmax[MAXN];

void solve() {
	for(int i = 0; i < 3; ++i) {
		cin >> k[i];
		n += k[i];
	}

	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < k[i]; ++j) {
			int idx = fetch<int>() - 1;
			a[idx] = i + 1;
		}
	}

#ifdef __LOCAL
	cout << "a: ";

	for(int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}

	cout << '\n';
#endif

	pref[0] += (a[0] == 1);
	pref[0] -= (a[0] == 2);
	prefmax[0] = pref[0];

	for(int i = 1; i < n; ++i) {
		pref[i] += pref[i - 1];
		pref[i] += (a[i] == 1);
		pref[i] -= (a[i] == 2);

		prefmax[i] = max(prefmax[i - 1], pref[i]);
	}

	suff[n - 1] += (a[n - 1] == 3);
	suff[n - 1] -= (a[n - 1] == 2);
	suffmax[n - 1] = suff[n - 1];

	for(int i = n - 2; i >= 0; --i) {
		suff[i] += suff[i + 1];
		suff[i] += (a[i] == 3);
		suff[i] -= (a[i] == 2);

		suffmax[i] = max(suffmax[i + 1], suff[i]);
	}

	int answ = max({0, prefmax[n - 1], suffmax[0]});

	for(int i = 0; i < n - 1; ++i) {
		answ = max(answ, prefmax[i] + suffmax[i + 1]);
	}

	// add cnt2
	for(int i = 0; i < n; ++i) {
		answ += (a[i] == 2);
	}

	cout << n - answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}