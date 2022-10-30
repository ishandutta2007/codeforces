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
ll a[MAXN];
int n;

int check(ll x, ll y) {
	DBG(x); DBG(y);

	for(int i = 0; i < n; ++i) {
		if(a[i] >= x * y) {
			return 0;
		}
	}

	for(int i = 1; i < n; ++i) {
		ll r1 = a[i - 1] / y;
		ll c1 = a[i - 1] - y * r1;

		ll r2 = a[i] / y;
		ll c2 = a[i] - y * r2;

		if(abs(r1 - r2) + abs(c1 - c2) != 1) {
			return 0;
		}
	}

	return 1;
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
	}

	set<ll> setik;
	for(int i = 1; i < n; ++i) {
		setik.insert(abs(a[i - 1] - a[i]));
	}

	if(len(setik) > 2) {
		cout << "NO\n";
		return;
	}

	vector<ll> temp = {(ll)1e9};
	for(auto& el: setik) {
		temp.push_back(el);
	}

	for(auto& x: temp) {
		for(auto& y: temp) {
			if(check(x, y)) {
				cout << "YES\n";
				cout << x << ' ' << y << '\n';
				return;
			}
		}
	}

	cout << "NO\n";
}

int main() {
	fast_io();
	solve();

	return 0;
}