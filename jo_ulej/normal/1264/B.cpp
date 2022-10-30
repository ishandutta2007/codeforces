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

void solve() {
	vector<int> cnt(4, 0);
	int n = 0;

	for(int i = 0; i < 4; ++i) {
		cin >> cnt[i];
		n += cnt[i];
	}

	int sz = cnt[1] + cnt[3];

	if(sz == 0) {
		if(n > 1) {
			cout << "NO\n";
		} else {
			cout << "YES\n";

			for(int d = 0; d < 4; ++d) {
				if(cnt[d] > 0) {
					cout << d << ' ';
				}
			}

			cout << '\n';
		}

		return;
	}

	sz = 2 * sz - 1;
	vector<int> answ(sz, NIL);

	for(int i = 0; i < sz; i += 2) {
		if(cnt[1] > 0) {
			answ[i] = 1;
			--cnt[1];
		} else {
			answ[i] = 3;
			--cnt[3];
		}
	}

	reverse(answ.begin(), answ.end());

	if(len(answ) < n) {
		answ.push_back(NIL);
	}

	reverse(answ.begin(), answ.end());

	if(len(answ) < n) {
		answ.push_back(NIL);
	}

	sz = len(answ);

	if(sz != n) {
		cout << "NO\n";
		return;
	}

	for(int i = 0; i < sz; ++i) {
		if(answ[i] == NIL) {
			for(int d = 0; d < 4; ++d) {
				if(cnt[d] == 0) {
					continue;
				}

				int ok = 1;

				if(i > 0 && abs(answ[i - 1] - d) != 1) {
					ok = 0;
				}

				if(i < sz - 1 && abs(answ[i + 1] - d) != 1) {
					ok = 0;
				}

				if(ok) {
					answ[i] = d;
					--cnt[d];
					break;
				}
			}

			if(answ[i] == NIL) {
				cout << "NO\n";
				return;
			}
		}
	}
	
	for(int i = 0; i < 4; ++i) {
		if(cnt[i] > 0) {
			cout << "NO\n";
			return;
		}
	}

	for(auto& el: answ) {
		if(el == NIL) {
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";
	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}