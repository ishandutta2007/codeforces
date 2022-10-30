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

const int MAXN = (int)1e6 + 777;

struct Node {
	int min = 0, max = 0, mod = 0;
};

Node tree[4 * MAXN];

void push(int v) {
	tree[v].min += tree[v].mod;
	tree[v].max += tree[v].mod;

	tree[2 * v + 1].mod += tree[v].mod;
	tree[2 * v + 2].mod += tree[v].mod;

	tree[v].mod = 0;
}

int read_min(int v) {
	return tree[v].mod + tree[v].min;
}

int read_max(int v) {
	return tree[v].mod + tree[v].max;
}

void change(int v, int tl, int tr, int l, int r, int x) {
	l = max(l, tl);
	r = min(r, tr);

	if(r < l) {
		return;
	}

	if(l == tl && r == tr) {
		tree[v].mod += x;
	} else {
		int tm = (tl + tr) / 2;
		push(v);

		change(2 * v + 1, tl, tm, l, r, x);
		change(2 * v + 2, tm + 1, tr, l, r, x);

		tree[v].min = min(read_min(2 * v + 1), read_min(2 * v + 2));
		tree[v].max = max(read_max(2 * v + 1), read_max(2 * v + 2));
	}
}

int getleaf(int v, int tl, int tr, int ps) {
	while(tl != tr) {
		push(v);
		int tm = (tl + tr) / 2;

		if(ps <= tm) {
			tr = tm;
			v = 2 * v + 1;
		} else {
			tl = tm + 1;
			v = 2 * v + 2;
		}
	}

	return read_min(v);
}

int getleaf(int ps) {
	return getleaf(0, 0, MAXN - 1, ps);
}

void change(int l, int r, int x) {
	change(0, 0, MAXN - 1, l, r, x);
}

int S[MAXN];

void modS(int ps, int vl) {
	change(ps, MAXN - 1, -S[ps]);
	S[ps] = vl;
	change(ps, MAXN - 1, S[ps]);
}

void solve() {
	int n = fetch<int>();
	auto Q = fetch<string>();
	int cur = 0;

	for(auto& q: Q) {
		if(q == 'R') {
			++cur;
		} else if(q == 'L') {
			--cur;

			if(cur < 0) {
				cur = 0;
			}
		} else if(q == '(') {
			modS(cur, +1);
		} else if(q == ')') {
			modS(cur, -1);
		} else {
			modS(cur, 0);
		}

		int mn = read_min(0);
		int mx = read_max(0);

		if(mn < 0 || getleaf(MAXN - 1) != 0) {
			cout << NIL << ' ';
		} else {
			cout << mx << ' ';
		}
	}

	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}