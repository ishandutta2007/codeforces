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

const int MAX_N = 107;
const ll MAX_VALUE = (ll)1e12;

string str;
ll dp[MAX_N][MAX_N];

inline void check(ll& value)
{
	if(value > MAX_VALUE)
		value = MAX_VALUE;

	if(value < 0)
		value = 0;
}

void solve()
{
	int n;
    ll k;

	cin >> n >> k;
	cin >> str;

	int prev[26];
	memset(prev, NIL, sizeof(prev));

	dp[0][0] = 1;

	for(int i = 1; i <= n; ++i)
	{
		dp[i][0] = 1;
		int ch = (int)str[i - 1] - 'a';

		for(int j = 1; j <= n; ++j)
		{
			dp[i][j] += dp[i - 1][j] + dp[i - 1][j - 1];

			if(prev[ch] != NIL)
				dp[i][j] -= dp[prev[ch] - 1][j - 1];

			check(dp[i][j]);
		}

		prev[ch] = i;
	}

#ifdef __LOCAL

	for(int len = 0; len <= n; ++len)
		cout << len << " -> " << dp[n][len] << endl;

#endif

	ll answer = ((ll)n) * k;

	for(int len = n; len >= 0 && k; --len)
	{
		ll count = min(dp[n][len], k);

		answer -= count * ((ll)len);
		k -= count;
	}

	cout << (k ? -1 : answer) << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}