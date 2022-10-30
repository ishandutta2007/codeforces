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
	string s;
	int n, k;

	cin >> n >> k;
	cin >> s;

	int corner_case = 1;
	for(int i = k; i < n; ++i) {
		if(s[i] != s[i - k]) {
			corner_case = 0;
			break;
		}
	}

	if(corner_case) {
		cout << n << '\n';
		cout << s << '\n';
		return;
	}

	vector<int> ok(n);
	for(int i = 0; i < n; ++i) {
		ok[i] = i == 0 ? 1 : ok[i - 1];
		if(i >= k) {
			if(s[i] != s[i - k]) {
				ok[i] = 0;
			}
		}
	}

	for(int i = n - 2; i >= 0; --i) {
		if(ok[i]) {
			char must = (i + 1 >= k ? s[i + 1 - k] : s[i + 1] + 1);
			if(must <= '9' && must > s[i + 1]) {
				cout << n << '\n';
				string answ(n, '%');
				for(int j = 0; j <= i; ++j) {
					answ[j] = s[j];
				}

				answ[i + 1] = must;
				for(int j = i + 2; j < n; ++j) {
					if(j >= k) {
						answ[j] = answ[j - k];
					} else {
						answ[j] = '0';
					}
				}

				cout << answ << '\n';
				return;
			}
		}
	}

	if(s.front() != '9') {
		cout << n << '\n';
		string answ(n, '%');
		answ.front() = s.front() + 1;

		for(int i = 1; i < n; ++i) {
			if(i >= k) {
				answ[i] = answ[i - k];
			} else {
				answ[i] = '0';
			}
		}

		cout << answ << '\n';
		return;
	}

	cout << n + 1 << '\n';
	string answ(n + 1, '%');
	answ.front() = '1';
	for(int i = 1; i < n + 1; ++i) {
		if(i >= k) {
			answ[i] = answ[i - k];
		} else {
			answ[i] = '0';
		}
	}

	cout << answ << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}