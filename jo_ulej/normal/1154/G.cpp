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

#ifdef __LOCAL
const int MAXN = 100;
#else
const int MAXN = (int)1e7 + 654;
#endif

int mn[MAXN], mn2[MAXN], cnt[MAXN];
int mnpos[MAXN], mn2pos[MAXN];
int pos[MAXN], pos2[MAXN];

void init() {
	for(int i = 0; i < MAXN; ++i) {
		mn[i] = mn2[i] = INT_INF;
	}
}

void add(int ps, int x) {
	++cnt[x];

	if(cnt[x] == 1) {
		pos[x] = ps;
	} else {
		pos2[x] = ps;
	}
}

void calc() {
	for(int g = 1; g < MAXN; ++g) {
		for(int j = g; j < MAXN; j += g) {
			if(cnt[j]) {
				if(j <= mn[g]) {
					mn2[g] = mn[g];
					mn2pos[g] = mnpos[g];

					mn[g] = j;
					mnpos[g] = pos[j];
				} else if(j <= mn2[g]) {
					mn2[g] = j;
					mn2pos[g] = pos[j];
				}
			}
		}
	}
}

void solve() {
	init();
	int n = fetch<int>();

	for(int i = 1; i <= n; ++i) {
		add(i, fetch<int>());
	}

	calc();

	ll answ = LL_INF;
	int l = NIL, r = NIL;

	for(int g = 1; g < MAXN; ++g) {
		if(mn2[g] != INT_INF) {
			ll local = (mn[g] / g) * 1LL * (mn2[g]);
			//answ = (local < answ ? local : answ);
			
			if(local < answ) {
				answ = local;
				l = mnpos[g];
				r = mn2pos[g];
			}
		}

		if(cnt[g] >= 2) {
			//answ = (g < answ ? g : answ);	
			
			if(g < answ) {
				answ = g;
				l = pos[g];
				r = pos2[g];
			}
		}
	}

	if(l > r) {
		swap(l, r);
	}

	cout << l << ' ' << r << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}