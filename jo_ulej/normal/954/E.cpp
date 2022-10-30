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

const int MAXN = 200000 + 7;
const double EPS = 1e-9;

pll a[MAXN];
ll T;
int n;

double get(const vector<pll>& aa, double m) {
	double answ = 0.;

	for(auto& pr: aa) {
		double alpha = pr.first;
		double beta  = pr.second;
		double t = alpha == 0. ? beta : min(m / alpha, beta);
		DBG(alpha); DBG(beta);

		m -= alpha * t;
		answ += t;
	}

	return answ;
}

void solve() {
	cin >> n >> T;
	for(int i = 0; i < n; ++i) {
		cin >> a[i].first;
	}

	for(int i = 0; i < n; ++i) {
		cin >> a[i].second;
		a[i].second -= T;
	}

	vector<pll> L, R;
	ll sumL = 0, sumR = 0;
	ll add = 0;

	for(int i = 0; i < n; ++i) {
		if(a[i].second > 0) {
			L.emplace_back(a[i].second, a[i].first);
			sumL += a[i].second * a[i].first;
		} else if(a[i].second < 0) {
			R.emplace_back(-a[i].second, a[i].first);
			sumR -= a[i].second * a[i].first;
		} else {
			add += a[i].first;
		}
	}

	ll sum = min(sumL, sumR);
	DBG(sum);
	sort(L.begin(), L.end());
	sort(R.begin(), R.end());

	cout << fixed << setprecision(12) << add + get(L, sum) + get(R, sum) << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}