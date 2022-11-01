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

const int MAX_N = 507;

int dp[MAX_N][MAX_N], a[MAX_N], n;

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	for(int l = n - 1; l >= 0; --l)
	{
		for(int r = l; r < n; ++r)
		{
			dp[l][r] = r - l + 1;

			if(r > l)
			{
				dp[l][r] = (dp[l][r] < dp[l + 1][r] + 1 ? dp[l][r] : dp[l + 1][r] + 1);
				dp[l][r] = (dp[l][r] < dp[l][r - 1] + 1 ? dp[l][r] : dp[l][r - 1] + 1);		
			}

			for(int m = l; m < r; ++m)
				dp[l][r] = (dp[l][r] < dp[l][m] + dp[m + 1][r] ? dp[l][r] : dp[l][m] + dp[m + 1][r]);

			for(int i = l, j = r; i <= j && a[i] == a[j]; ++i, --j)
			{
				int local = (j - i > 2 ? dp[i + 1][j - 1] : 1);
				dp[l][r] = (dp[l][r] < local ? dp[l][r] : local);
			}
		}
	}

	cout << dp[0][n - 1] << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}