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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)2e5 + 777;

ll dp[2][MAX_N];
string road;
ll a, b;
int n;

void solve()
{
	cin >> n >> a >> b;
	cin >> road;

	dp[0][0] = b;
	dp[1][0] = LL_INF;

	for(int i = 1; i <= n; ++i)
	{
		dp[1][i] = min(dp[1][i - 1] + a + 2 * b, dp[0][i - 1] + 2 * a + 2 * b);

		if(road[i - 1] != '1' && (i == n || road[i] != '1'))
		{
			dp[0][i] = min(dp[0][i - 1] + a + b, dp[1][i - 1] + 2 * a + b);
		}
		else
		{
			dp[0][i] = LL_INF;
		}
	}

#ifdef __LOCAL

	/*for(int i = 0; i <= n; ++i)
	{
		cout << "dp0[" << i << "] -> " << dp[0][i] << endl;			
		cout << "dp1[" << i << "] -> " << dp[1][i] << endl;			
	}*/

#endif

	cout << dp[0][n] << endl;
}

int main()
{
	fast_io();

	int T;
	cin >> T;

	while(T--)
		solve();

	return 0;
}