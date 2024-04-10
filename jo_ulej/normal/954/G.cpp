#pragma GCC optimize("Ofast")

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

const int MAXN = (int)5e5 + 7;
ll a[MAXN], k, pref[MAXN];
ll b[MAXN], c[MAXN];
int n, r;

ll get(int l, int r) {
	ll rez = pref[r];
	if(l > 0) {
		rez -= pref[l - 1];
	}

	return rez;
}

ll d[MAXN];

void add2(int l, int r, ll x) {
	d[l] += x;
	d[r + 1] -= x;
}

int check(ll x) {
	ll cur = k;
	memset(d, 0, sizeof(d));

	for(int i = 0; i < n; ++i) {
		c[i] = x - b[i];
	}

	ll already = 0;
	for(int i = 0; i < n; ++i) {
		already += d[i];
		ll old = d[i];
		ll val = c[i] + already;

		if(val > 0) {
			if(val > cur) {
				return 0;
			} else {
				cur -= val;
			}

			int cen = i + r;
			int low = max(0, cen - r);
			int high = min(n - 1, cen + r);
			add2(low, high, -val);
		}

		already -= old;
		already += d[i];
	}

	return 1;
}

void solve() {
	cin >> n >> r >> k;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		pref[i] = a[i];
		if(i > 0) {
			pref[i] += pref[i - 1];
		}
	}

	for(int i = 0; i < n; ++i) {
		int low = max(0, i - r);
		int high = min(n - 1, i + r);
		b[i] = get(low, high);
	}

	ll low = 0, high = (ll)2e18;

	while(high - low > 1) {
		ll mid = (low + high) / 2;
		if(check(mid)) {
			low = mid;
		} else {
			high = mid;
		}
	}

	cout << low << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}