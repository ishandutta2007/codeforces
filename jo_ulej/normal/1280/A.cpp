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

const int MOD = (int)1e9 + 7;

int add(int x, int y) {
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int sub(int x, int y) {
	return (x - y < 0 ? x - y + MOD : x - y);
}

int mult(int x, int y) {
	return (x * 1LL * y) % MOD;
}

void solve() {
	int x = fetch<int>();
	auto S = fetch<string>();
	int sz = len(S) % MOD;
	int flag = 1;

	deque<int> q;

	for(auto& ch: S) {
		q.push_back(ch - '0');
	}

	for(int i = 0; i < x; ++i) {
		/*cout << "@q: ";

		for(auto& el: q) {
			cout << el << ' ';
		}

		cout << '\n';*/
		int fst = q.front(); q.pop_front();
		sz = add(sz, mult(sub(sz, 1 + i), fst - 1));

		if(flag) {
			int old = len(q);

			for(int t = 0; t < fst - 1; ++t) {
				for(int i = 0; i < old; ++i) {
					int temp = q[i];
					q.push_back(temp);

					if(len(q) > x + 7) {
						flag = 0;
						goto out;
					}
				}
			}

out: 		{}
		}
	}

	cout << sz << '\n';
}

int main() {
	fast_io();

	int T = fetch<int>();

	while(T--) {
		solve();
	}

	return 0;
}