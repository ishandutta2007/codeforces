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

#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

int n, k, g;
ld L, v1, v2;	

bool check(ld T)
{
	if(v2 * T < L)
		return false;

	if(v1 * T >= L)
		return true;

	ld t1 = (L - v2 * T) / (v1 - v2);
	ld t2 = T - t1;

	DBG(T); DBG(t1); DBG(t2);

	ld time = g * t2 + (g - 1) * t2 * (v2 - v1) / (v2 + v1);

	DBG(time);

	return time <= T;
}

void solve()
{
	cin >> n >> L >> v1 >> v2 >> k;
	g = (n - 1) / k + 1;

	ld L = 0, R = 1e18;

	while(R - L > 1e-8)
	{
		ld M = 0.5 * (L + R);

		if(check(M))
			R = M;
		else
			L = M;
	}

	cout << fixed << setprecision(12) << 0.5 * (L + R) << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}