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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)1e5 + 77;

const int LEFT = 0;
const int RIGHT = 1;
const int NONE = 2;

ll dp[3][MAX_N], a[2][MAX_N];
int n;

void solve()
{
	cin >> n;

	for(auto t: {LEFT, RIGHT})
		for(int i = 0; i < n; ++i)
			cin >> a[t][i];

	dp[LEFT][0] = -LL_INF;
	dp[RIGHT][0] = -LL_INF;

	for(int i = 1; i <= n; ++i)
	{
		ll left = a[0][i - 1], right = a[1][i - 1];

		dp[LEFT][i] = left + max(dp[RIGHT][i - 1], dp[NONE][i - 1]);
		dp[RIGHT][i] = right + max(dp[LEFT][i - 1], dp[NONE][i - 1]);
		dp[NONE][i] = max({dp[LEFT][i - 1], dp[RIGHT][i - 1], dp[NONE][i - 1]});
	}

	cout << max(dp[0][n], dp[1][n]) << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}