#pragma GCC optimize("Ofast,unroll-loops")

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

const int MAXN = (int)2e5 + 7;
const int T    = 448;

string str;
int pref[MAXN], a[MAXN];
int fst[2 * MAXN];
int n;

int count(int l, int r, int mod, int rem) {
	if(l == 0) {
		int rez = (r + 1) / mod;
		if((r + 1) % mod != 0) rez += r % mod >= rem;
		return rez;
	} else {
		return count(0, r, mod, rem) - count(0, l - 1, mod, rem);
	}
}

int pos[MAXN], neg[T * MAXN];

ll calc1(int k) {
	for(int i = 0; i < n; ++i) {
		a[i] = i - k * pref[i];
		if(a[i] >= 0) {
			++pos[a[i]];
		} else {
			++neg[-a[i]];
		}
	}

	ll rez = 0;
	for(int i = 0; i < n; ++i) {
		ll cnt = 0;
		if(a[i] >= 0) {
			cnt = pos[a[i]];
			pos[a[i]] = 0;
		} else {
			cnt = neg[-a[i]];
			neg[-a[i]] = 0;
		}

		rez += cnt * (cnt - 1);
	}

	return rez / 2;
}

ll calc2() {
	ll rez = 0;
	for(int l = 0; l < n; ++l) {
		for(int cnt = 1; cnt <= T; ++cnt) {
			int low = fst[pref[l] + cnt]; //lower_bound(pref, pref + n, pref[l] + cnt) - pref;
			int high = fst[pref[l] + cnt + 1]; //upper_bound(pref, pref + n, pref[l] + cnt) - pref;
			--high;

			if(high < low) {
				break;
			}

			low = max(low, T * cnt + 1 + l);
			if(high < low) {
				continue;
			}

			rez += count(low, high, cnt, l % cnt);
		}
	}

	return rez;
}

void solve() {
	cin >> str; n = len(str) + 1;
	for(int i = 1; i < n; ++i) pref[i] = pref[i - 1] + (str[i - 1] - '0');
	for(int i = 0; i < 2 * MAXN; ++i) fst[i] = n;
	for(int i = 0; i < n; ++i) {
		fst[pref[i]] = min(fst[pref[i]], i);
	}
	for(int i = 2 * MAXN - 1; i > 0; --i) fst[i - 1] = min(fst[i - 1], fst[i]);
	ll answ = 0;
	for(int k = 1; k <= T; ++k) answ += calc1(k);
	answ += calc2();
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}