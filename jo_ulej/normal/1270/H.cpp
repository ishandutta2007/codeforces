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

struct Data {
	int mn = 0, cnt = 0;

	Data() {}
	Data(int _mn, int _cnt): mn(_mn), cnt(_cnt) {}

	Data operator+(const Data& other) const {
		if(cnt == 0)       return other;
		if(other.cnt == 0) return *this;

		if(mn < other.mn) {
			return *this;
		} else if(mn > other.mn) {
			return other;
		} else {
			return Data(mn, cnt + other.cnt);
		}
	}

	Data apply_mod(int mod) const {
		return Data(mn + mod, cnt);
	}
};

struct Node {
	Data data;
	int mod = 0;
};

Node tree[4 * MAXN];

void T_push(int v) {
	tree[2 * v + 1].mod += tree[v].mod;
	tree[2 * v + 2].mod += tree[v].mod;
	tree[v].data = tree[v].data.apply_mod(tree[v].mod);
	tree[v].mod = 0;
}

Data T_read(int v) {
	return tree[v].data.apply_mod(tree[v].mod);
}

void T_change_active(int v, int tl, int tr, int pos, int n_state) {
	if(pos < tl || pos > tr) return;
	if(tl == tr) {
		tree[v].data.cnt = n_state;
	} else {
		T_push(v);
		int tm = (tl + tr) / 2;
		T_change_active(2 * v + 1, tl, tm, pos, n_state);
		T_change_active(2 * v + 2, tm + 1, tr, pos, n_state);

		tree[v].data = T_read(2 * v + 1) + T_read(2 * v + 2);
	}
}

void T_add_on_range(int v, int tl, int tr, int l, int r, int delta) {
	l = max(tl, l);
	r = min(tr, r);
	if(r < l) return;

	if(tl == l && tr == r) {
		tree[v].mod += delta;
	} else {
		int tm = (tl + tr) / 2;
		T_push(v);
		T_add_on_range(2 * v + 1, tl, tm, l, r, delta);
		T_add_on_range(2 * v + 2, tm + 1, tr, l, r, delta);

		tree[v].data = T_read(2 * v + 1) + T_read(2 * v + 2);
	}
}

Data T_get(int v, int tl, int tr, int l, int r) {
	l = max(tl, l);
	r = min(tr, r);
	if(r < l) return Data(); // neutral element

	if(tl == l && tr == r) {
		return T_read(v);
	} else {
		int tm = (tl + tr) / 2;
		T_push(v);

		auto left  = T_get(2 * v + 1, tl, tr, l, r);
		auto right = T_get(2 * v + 2, tm + 1, tr, l, r);

		return left + right;
	}
}

const int ROOT = 0;
const int ROOT_TL = 0;
const int ROOT_TR = MAXN - 1;

void change_active(int val, int state) {
	T_change_active(ROOT, ROOT_TL, ROOT_TR, val, state);
}

void add(int l, int r, int delta) {
	T_add_on_range(ROOT, ROOT_TL, ROOT_TR, l, r, delta);
}

int count_mins(int l, int r) {
	auto data = T_get(ROOT, ROOT_TL, ROOT_TR, l, r);
	return data.cnt;
}

int a[MAXN], n, q;

void calc_delta(int L, int R, int x) {
	if(L > R) swap(L, R);
	if(L == R) return;

	add(L + 1, R, +x);
}

void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; ++i) cin >> a[i];
	a[0] = MAXN - 1, a[n + 1] = 0;
	n += 2;

	for(int i = 1; i < n - 1; ++i) change_active(a[i], 1);
	for(int i = 0; i < n - 1; ++i) calc_delta(a[i], a[i + 1], +1);

	DBG(count_mins(0, MAXN - 1));
	while(q--) {
		int pos = fetch<int>();
		int val = fetch<int>();

		change_active(a[pos], 0);
		calc_delta(a[pos - 1], a[pos], -1);
		calc_delta(a[pos + 1], a[pos], -1);

		a[pos] = val;
		
		calc_delta(a[pos - 1], a[pos], +1);
		calc_delta(a[pos + 1], a[pos], +1);
		change_active(a[pos], 1);
		cout << count_mins(0, MAXN - 1) << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}