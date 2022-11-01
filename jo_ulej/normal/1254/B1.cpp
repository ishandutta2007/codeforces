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

const int MAXN = (int)1e5 + 77;
int a[MAXN], n, total = 0;

void solve() {
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		total += a[i];
	}

	ll answ = LL_INF;

	for(int d = 2; d <= total; ++d) {
		if(total % d != 0) {
			continue;
		}

		DBG(d);
		ll local = 0;

		for(int i = 0; i < n;) {
			if(a[i] == 0) {
				++i;
			} else {
				int sum = 0;
				int j = i;
				vector<ll> pos;

				while(j < n && sum != d) {
					sum += a[j];

					if(a[j] != 0) {
						pos.push_back(j);
					}

					++j;
				}

				DBG(i); DBG(j);
				DBG(pos); DBG(sum);

				if(sum != d) {
					local = LL_INF;
					break;
				}

				int med = len(pos) / 2;

				for(auto& idx: pos) {
					local += abs(pos[med] - idx);
				}

				i = j;
			}
		}

		answ = min(answ, local);
	}

	cout << (answ == LL_INF ? NIL : answ) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}