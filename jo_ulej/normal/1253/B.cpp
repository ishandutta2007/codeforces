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
int state[MAXN], a[MAXN], n;
int opened[MAXN], closed[MAXN], mark = 13;

void solve() {
	cin >> n;
	bool good = true;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];

		if(a[i] > 0) {
			++state[a[i]];
		} else {
			--state[-a[i]];

			if(state[-a[i]] < 0) {
				good = false;
			}
		}
	}

	for(int val = 1; val < MAXN; ++val) {
		if(state[val] != 0) {
			good = false;
			break;
		}
	}

	if(good) {
		vector<int> answ;

		for(int i = 0; i < n;) {
			int cnt = 0;
			++mark;
			int op = 0;

			while(i + cnt < n) {
				int val = a[i + cnt];

				if(val > 0) {
					if(opened[val] == mark) {
						break;
					}

					opened[val] = mark;
					++op;
				} else {
					if(closed[-val] == mark) {
						break;
					}

					closed[-val] = mark;
					--op;
				}

				++cnt;

				if(!op) {
					break;
				}
			}

			answ.push_back(cnt);
			i += cnt;
		}

		DBG(answ);

		int l = 0;

		for(auto& sz: answ) {
			int r = l + sz - 1;

			for(int i = l; i <= r; ++i) {
				if(a[i] > 0) {
					++state[a[i]];
				} else {
					--state[-a[i]];

					if(state[-a[i]] < 0) {
						good = false;
						break;
					}
				}
			}

			for(int i = l; i <= r; ++i) {
				int val = abs(a[i]);

				if(state[val] != 0) {
					good = false;
					break;
				}
			}

			if(!good) {
				break;
			}

			l += sz;
		}
		
		if(good) {
			cout << len(answ) << '\n';
			cout << answ << '\n';
		} else {
			cout << NIL << '\n';
		}
	} else {
		cout << NIL << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}