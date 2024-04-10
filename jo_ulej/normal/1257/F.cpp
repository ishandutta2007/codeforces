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

const int MAXN = 107;
const int BITS = 30;
const int HALF = BITS / 2;

int a[MAXN], n;
vector<pair<vector<int>, int>> L, R;

void solve() {
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	SAY("finished reading");

	for(int val = 0; val < (1 << HALF); ++val) {
		vector<int> cnt(n, 0);

		for(int j = 0; j < n; ++j) {
			int y = a[j] ^ val;
			y &= (1 << HALF) - 1;

			cnt[j] = __builtin_popcount(y);
		}

		L.emplace_back(cnt, val);
	}

	sort(L.begin(), L.end());

	for(int val = 0; val < (1 << HALF); ++val) {
		vector<int> cnt(n, 0);

		for(int j = 0; j < n; ++j) {
			int y = a[j] ^ (val << HALF);
			y >>= HALF;
			y &= (1 << HALF) - 1;

			cnt[j] = __builtin_popcount(y);
		}

		R.emplace_back(cnt, val << HALF);
	}

	for(int tot = 0; tot <= BITS; ++tot) {
		for(auto& pr: R) {
			auto cnt = pr.first;
			int ok = 1;

			for(auto& elem: cnt) {
				elem = tot - elem;

				if(elem < 0) {
					ok = 0;
					break;
				}
			}
			
			if(ok) {
				auto pr2 = make_pair(cnt, NIL);
				auto iter = lower_bound(L.begin(), L.end(), pr2);

				if(iter != L.end() && iter->first == cnt) {
					cout << pr.second + iter->second << '\n';
					return;
				}
			}
		}
	}

	cout << NIL << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}