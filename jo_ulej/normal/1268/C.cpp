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

const int MAXN = (int)2e5 + 7;
int a[MAXN], pos[MAXN], n;
ll inv[MAXN], dp[MAXN];

struct Fenwick {
	ll* F = nullptr;
	int sz = 0;

	Fenwick(int _sz): sz(_sz) {
		F = new ll[sz];
		memset(F, 0, sizeof(ll) * sz);
	}

	inline void add(int pos, ll val) const {
		for(; pos < sz; pos |= pos + 1) {
			F[pos] += val;
		}
	}

	inline ll get(int r) const {
		ll rez = 0;
		for(; r >= 0; r = (r & (r + 1)) - 1) {
			rez += F[r];
		}

		return rez;
	}

	inline ll get(int l, int r) const {
		if(l > r) return 0;
		return get(r) - (l == 0 ? 0 : get(l - 1));
	}
};

struct SetWithSum {
	set<ll> setik;
	ll sum = 0;

	void insert(ll val) {
		setik.insert(val);
		sum += val;
	}

	void erase(ll val) {
		setik.erase(val);
		sum -= val;
	}

	ll get() const {
		return sum;
	}

	void print() {
		cout << "@:";
		for(auto& el: setik) {
			cout << ' ' << el; 
		}

		cout << '\n';
	}
};

ll calc(const Fenwick& count, const Fenwick& sum, ll half) {
	ll rez = 0;
	int low = 0, high = n - 1;
	if(count.get(high) <= half) {
		rez -= sum.get(high);
	} else if(count.get(low) <= half) {
		while(high - low > 1) {
			int mid = (low + high) / 2;
			if(count.get(mid) <= half) {
				low = mid;
			} else {
				high = mid;
			}
		}
		rez -= sum.get(low);
	}

	low = 0, high = n - 1;
	if(count.get(low, n - 1) <= half) {
		rez -= sum.get(low, n - 1);
	} else if(count.get(high, n - 1) <= half) {
		while(high - low > 1) {
			int mid = (low + high) / 2;
			if(count.get(mid, n - 1) <= half) {
				high = mid;
			} else {
				low = mid;
			}
		}
		rez += sum.get(high, n - 1);
		rez += count.get(high, n - 1);
	}

	return rez;
}

void solve() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		a[i] = fetch<int>() - 1;
		pos[a[i]] = i;
	}

	Fenwick fenv(n);
	Fenwick count(n), sum(n);

	for(int v = 0; v < n; ++v) {
		inv[v] = fenv.get(pos[v] + 1, n - 1);
		fenv.add(pos[v], 1);
	}

	for(int i = 2; i < MAXN; ++i) {
		dp[i] = i + dp[i - 2];
	}

	ll cur = 0;

	for(int v = 0; v < n; ++v) {
		cur += inv[v];
		count.add(pos[v], 1);
		sum.add(pos[v], pos[v]);

		ll answ = cur + calc(count, sum, (v + 1) / 2) - dp[v + 1];
		/*for(ll x = v + 1; x > 1; x -= 2) {
			answ -= x;
		}*/

		cout << answ << ' ';
	}

	cout << '\n';
}

int main() {
	fast_io();
	solve();

	return 0;
}