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
#else
	#define DBG(X)
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
template<typename T> inline void goodbye(const T& val) { cout << val << endl; exit(0); }

struct Point {
	ll x, y, z;
	int index;

	bool operator<(const Point& other) const {
		if(x != other.x) {
			return x < other.x;
		}

		if(y != other.y) {
			return y < other.y;
		}

		return z < other.z;
	}
};

void solve() {
	int n;
	cin >> n;

	vector<Point> a(n);
	int last = 0;

	for(auto& pt: a) {
		cin >> pt.x >> pt.y >> pt.z;
		pt.index = ++last;
	}

	sort(a.begin(), a.end());
	vector<Point> b, c;
	vector<pii> answ;

	for(int i = 0; i < n;) {
		int j = i;

		while(j + 1 < n && a[j + 1].x == a[i].x && a[j + 1].y == a[i].y) {
			++j;
		}

		for(int k = i; k + 1 <= j; k += 2) {
			answ.emplace_back(a[k].index, a[k + 1].index);
		}

		if((j - i + 1) & 1) {
			b.push_back(a[j]);
		}

		i = j + 1;
	}

	n = len(b);

	for(int i = 0; i < n;) {
		int j = i;

		while(j + 1 < n && b[j + 1].x == b[i].x) {
			++j;
		}

		for(int k = i; k + 1 <= j; k += 2) {
			answ.emplace_back(b[k].index, b[k + 1].index);
		}

		if((j - i + 1) & 1) {
			c.push_back(b[j]);
		}

		i = j + 1;
	}

	n = len(c);

	for(int i = 0; i + 1 < n; i += 2) {
		answ.emplace_back(c[i].index, c[i + 1].index);
	}

	for(auto& pr: answ) {
		cout << pr.first << ' ' << pr.second << '\n';
	}
}

int main() {
	fast_io();
	solve();

	return 0;
}