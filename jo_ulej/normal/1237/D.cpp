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
#else
	#define DBG(X)
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
template<typename T> inline void goodbye(const T& val) { cout << val << endl; exit(0); }

const int MAXN = (int)5e5 + 777;
const int MAX_LOGN = 20;

int a[MAXN], n;

void solve() {
	cin >> n;
	n *= 4;

	for(int i = 0; i < n / 4; ++i) {
		cin >> a[i];
		a[n / 4 + i] = a[i];
		a[n / 4 + n / 4 + i] = a[i];
		a[n / 4 + n / 4 + n / 4 + i] = a[i];
	}

	multiset<int> setik;
	int j = 0;

	for(int i = 0; i < n / 4; ++i) {
		while(j < n && (setik.empty() || 2 * a[j] >= *prev(setik.end()))) {
			setik.insert(a[j++]);
		}

		cout << (j == n ? -1 : j - i) << ' ';
		setik.erase(setik.find(a[i]));
	}

	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}