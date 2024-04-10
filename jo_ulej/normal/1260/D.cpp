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

const int MAXN = (int)2e5 + 77;
int n, m, k, t;
int a[MAXN];
int L[MAXN], R[MAXN], d[MAXN];
int p[MAXN];

int check(int answ) {
	if(answ == 0) {
		return 1;
	}

	if(answ > m) {
		return 0;
	}

	ll time = n + 1;
	int soldier = a[answ - 1];

	memset(p, 0, sizeof(p));
	for(int i = 0; i < k; ++i) {
		if(d[i] > soldier) {
			++p[L[i]];
			--p[R[i] + 1];
		}
	}

	for(int i = 1; i < MAXN; ++i) {
		p[i] += p[i - 1];
	}

	for(int i = 0; i < MAXN;) {
		if(p[i]) {
			int j = i;

			while(j + 1 < MAXN && p[j + 1]) {
				++j;
			}

			time += 2 * (j - i + 1);
			i = j + 1;
		} else {
			++i;
		}
	}

	return time <= t * 1LL;
}

void solve() {
	cin >> m >> n >> k >> t;

	for(int i = 0; i < m; ++i) {
		cin >> a[i];
	}

	sort(a, a + m);
	reverse(a, a + m);

	for(int i = 0; i < k; ++i) {
		cin >> L[i] >> R[i] >> d[i];
	}

	int low = 0, high = m + 1;

	while(high - low > 1) {
		int mid = (low + high) / 2;

		if(check(mid)) {
			low = mid;
		} else {
			high = mid;
		}
	}

	cout << low << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}