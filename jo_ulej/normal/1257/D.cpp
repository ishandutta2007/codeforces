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

const int MAXN = (int)2e5 + 777;
int a[MAXN], n, m;
pii h[MAXN];
int prefmax[MAXN];

int check(int mx, int cnt) {
	if(h[m - 1].first >= mx) {
		return prefmax[m - 1] >= cnt;
	} else if(h[0].first < mx) {
		return 0;
	} else {
		int low = 0, high = m - 1;

		while(high - low > 1) {
			int mid = (low + high) / 2;

			if(h[mid].first >= mx) {
				low = mid;
			} else {
				high = mid;
			}
		}

		return prefmax[low] >= cnt;
	}
}

void solve() {
	cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}	

	cin >> m;

	for(int i = 0; i < m; ++i) {
		cin >> h[i].first >> h[i].second;
	}

	SAY("finished reading");

	sort(h, h + m);
	reverse(h, h + m);
	prefmax[0] = h[0].second;

	for(int i = 1; i < m; ++i) {
		prefmax[i] = max(prefmax[i - 1], h[i].second);
	}

	int cur = 0;
	int answ = 0;

	while(cur < n) {
		DBG(cur);
		int mx = -INT_INF;
		int cnt = 0;

		while(cur + cnt < n) {
			int mx2 = max(mx, a[cur + cnt]);

			if(check(mx2, cnt + 1)) {
				mx = mx2;
				++cnt;
			} else {
				break;
			}
		}

		if(cnt == 0) {
			cout << NIL << '\n';
			return;
		} else {
			++answ;
			cur += cnt;
		}
	}

	cout << answ << '\n';
}

int main() {
	fast_io();

	int T = fetch<int>();

	while(T--) {
		solve();
	}

	return 0;
}