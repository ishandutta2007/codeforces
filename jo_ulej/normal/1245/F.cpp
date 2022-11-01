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

const int BITS = 32;

vector<int> convert(ll number) {
	vector<int> rez(BITS, 0);

	for(int i = 0; i < BITS; ++i) {
		rez[BITS - 1 - i] = number & 1;
		number /= 2;
	}

	return rez;
}

void solve() {
	ll l = fetch<ll>();
	ll r = fetch<ll>() + 1;
	ll answ = 0;

	if(l == 0) {
		answ += 2 * r - 1;
	} else {
		--l;
	}

	auto L = convert(l);
	auto R = convert(r);

	for(int i = 0; i < BITS; ++i) {
		if(L[i] == 1) {
			continue;
		}

		for(int j = 0; j < BITS; ++j) {
			if(R[j] == 0) {
				continue;
			}

			vector<int> x(BITS, NIL), y(BITS, NIL);

			for(int k = 0; k < i; ++k) {
				x[k] = L[k];
			}

			x[i] = L[i] ^ 1;

			for(int k = 0; k < j; ++k) {
				y[k] = R[k];
			}

			y[j] = R[j] ^ 1;
			int intr = 0;

			for(int k = 0; k < BITS; ++k) {
				if(x[k] == 1 && y[k] == 1) {
					intr = 1;
					break;
				}
			}

			if(intr) {
				continue;
			}

			DBG(x); DBG(y);

			for(int m = 0; m < BITS; ++m) {
				int good = 1;

				for(int k = 0; k < m; ++k) {
					if(x[k] == 1 || y[k] == 1) {
						good = 0;
						break;
					}
				}

				if(y[m] == 0 || x[m] == 1) {
					good = 0;
				}

				if(!good) {
					continue;
				}

				ll to_add = 1;

				for(int k = m + 1; k < BITS; ++k) {
					ll mult = 0;

					for(int xb = 0; xb <= 1; ++xb) {
						for(int yb = 0; yb <= 1; ++yb) {
							if((xb & yb) == 0) {
								if(x[k] == xb || x[k] == -1) {
									if(y[k] == yb || y[k] == -1) {
										++mult;
									}
								}
							}
						}
					}

					to_add *= mult;
				}

				DBG(to_add);
				answ += 2 * to_add;
			}
		}
	}

	cout << answ << '\n';
}

int main() {
	fast_io();

	int T;
	cin >> T;

	while(T--) {
		solve();
	}

	return 0;
}