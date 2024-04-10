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
template<typename T> inline vector<T> fetch_vec(int sz) { vector<T> ret(sz); for(auto& elem: ret) cin >> elem; return ret; }

const int MAXN = (int)2e5 + 777;

int n, k;
int fenwick[MAXN];
vector<pii> info[MAXN];
vector<int> answ;

void fenwick_add(int pos, int x) {
	for(; pos < MAXN; pos |= pos + 1) {
		fenwick[pos] += x;
	}
}

int fenwick_get(int r) {
	int acc = 0;

	for(; r >= 0; r = (r & (r + 1)) - 1) {
		acc += fenwick[r];
	}

	return acc;
}

void add(int l, int r, int x) {
	fenwick_add(l, x);
	fenwick_add(r + 1, -x);
}

int get(int i) {
	return fenwick_get(i);
}

void solve() {
	cin >> n >> k;

	for(int i = 0; i < n; ++i) {
		int l = fetch<int>();
		int r = fetch<int>();

		info[l].emplace_back(r, i + 1);
		add(l, r, 1);
	}

	set<pii> setik;

	for(int i = 0; i < MAXN; ++i) {
		for(auto& evt: info[i]) {
			setik.insert(evt);
		}

		while(get(i) > k) {
			auto iter = prev(setik.end());
			pii last = *iter;
			setik.erase(iter);

			add(i, last.first, -1);
			answ.push_back(last.second);
		}
	}

	cout << len(answ) << '\n';
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}