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

const int MAXN = (int)1e6 + 77;
const int LOG  = 30;
int S[MAXN], n;
int b[LOG];

void init_Gauss() {
	for(int i = 0; i < LOG; ++i) b[i] = 0;
}

int add(int msk) {
	for(int i = 0; i < LOG; ++i) {
		int bit = 1 << i;
		if(msk & bit) {
			if(b[i]) {
				msk ^= b[i];
			} else {
				b[i] = msk;
				return 1;
			}
		}
	}

	return 0;
}

vector<int> build(int sz) {
	if(sz == 0) {
		return vector<int>(1, 0);
	} else {
		auto left = build(sz - 1);
		auto right = build(sz - 1);
		reverse(right.begin(), right.end());

		vector<int> answ;
		for(auto& el: left)  answ.push_back(2 * el);
		for(auto& el: right) answ.push_back(2 * el + 1);

		return answ;
	}
}

int used[MAXN];

void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> S[i];

	for(int x = LOG - 1; x >= 0; --x) {
		init_Gauss();
		vector<int> good;
		for(int i = 0; i < n; ++i) {
			if(S[i] >= (1 << x)) continue;
			if(add(S[i])) {
				good.push_back(S[i]);
			}
		}

		if(len(good) >= x) {
			auto path = build(x);

			for(auto& el: path) {
				int rez = 0;
				for(int i = 0; i < x; ++i) {
					if((el >> i) & 1) {
						rez ^= good[i];
					}
				}

				el = rez;
			}

			cout << x << '\n';
			cout << path << '\n';

			for(auto& el: path) {
				++used[el];
				assert(used[el] <= 1);
			}

			for(int i = 0; i < (1 << x); ++i) {
				assert(used[i] >= 1);
			}
			
			return;
		}
	}

	assert(false);
}

int main() {
	fast_io();
	solve();

	return 0;
}