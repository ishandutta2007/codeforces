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
	#define DBG(X) cout << "[DBG] " << #X << "=" << (X) << '\n';
	#define SAY(X) cout << "[SAY] " << (X) << '\n';
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

const int MAXN = (int)2e5 + 7;
int a[MAXN], n;
ll cost[MAXN];
struct Node {
	ll mod = 0;
	ll max = 0;
};

Node tree[4 * MAXN];

inline void push(int v) {
	tree[2 * v + 1].mod += tree[v].mod;
	tree[2 * v + 2].mod += tree[v].mod;

	tree[v].max += tree[v].mod;
	tree[v].mod = 0;
}

inline ll read(int v) {
	return tree[v].mod + tree[v].max;
}

void change(int v, int tl, int tr, int l, int r, ll x) {
	if(tl == l && tr == r) {
		tree[v].mod += x;
	} else {
		push(v);
		int tm = (tl + tr) / 2;

		if(r <= tm) {
			change(2 * v + 1, tl, tm, l, r, x);
		} else if(l > tm) {
			change(2 * v + 2, tm + 1, tr, l, r, x);
		} else {
			change(2 * v + 1, tl, tm, l, tm, x);
			change(2 * v + 2, tm + 1, tr, tm + 1, r, x);
		}

		tree[v].max = max(read(2 * v + 1), read(2 * v + 2));
	}
}

ll get(int v, int tl, int tr, int l, int r) {
	if(tl == l && tr == r) {
		return read(v);
	} else {
		push(v);
		int tm = (tl + tr) / 2;

		if(r <= tm) {
			return get(2 * v + 1, tl, tm, l, r);
		}

		if(l > tm) {
			return get(2 * v + 2, tm + 1, tr, l, r);
		}

		ll left_max = get(2 * v + 1, tl, tm, l, tm);
		ll right_max = get(2 * v + 2, tm + 1, tr, tm + 1, r);

		return max(left_max, right_max);
	}
}

void ADD(int l, int r, ll val) {
	change(0, 0, MAXN - 1, l, r, val);
}

ll GET() {
	return get(0, 0, MAXN - 1, 0, MAXN - 1);
}

void solve() {
	cin >> n; for(int i = 0; i < n; ++i) a[i] = fetch<int>() - 1;
	for(int i = 0; i < n; ++i) cin >> cost[i];
	for(int pos = 0; pos < n; ++pos) {
		int val = a[pos];
		ADD(0, val, +cost[pos]);
	}
	ll best = 0;
	for(int p = 1; p < n; ++p) {
		int pos = p - 1;
		int val = a[pos];
		ADD(0, val, -cost[pos]);
		ADD(val + 1, MAXN - 1, +cost[pos]);
		best = max(best, GET());
	}
	ll answ = 0; 
	for(int i = 0; i < n; ++i) answ += cost[i];
	answ -= best;
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}