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
	#define DBG(X) cout << #X << "=" << (X) << endl;
#else
	#define DBG(X)
	#define endl '\n'
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

const int MAX_N = 1007;

ll M[MAX_N][MAX_N], n;
ll answ[MAX_N];

ll GCD(ll x, ll y)
{
	return (x == 0 ? y : GCD(y % x, x));
}

ll find(ll x)
{
	ll low = 0, high = (ll)2e9 + 777;

	while(high - low > 1)
	{
		ll mid = (low + high) / 2;

		if(mid * mid <= x)
			low = mid;
		else
			high = mid;
	}

	return low;
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < n; ++j)
			cin >> M[i][j];
	}

	answ[0] = find((M[1][0] * M[2][0]) / M[1][2]);

	for(int i = 1; i < n; ++i)
		answ[i] = M[0][i] / answ[0];

	for(int i = 0; i < n; ++i)
		cout << answ[i] << " ";

	cout << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}