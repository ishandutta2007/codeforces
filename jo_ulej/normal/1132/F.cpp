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

#define fast_min(X, Y) ((X) < (Y) ? (X) : (Y))

const int MAX_N = 507;
const int ALPHA = 26;
const int FULL_MASK = (1 << ALPHA) - 1;

int dp[MAX_N][MAX_N];
int mask[MAX_N][MAX_N];
int used[MAX_N][MAX_N];

int n;
string str;

//vector<int> pos[ALPHA];

void calc(int l, int r)
{
	if(used[l][r] || r < l)
		return;	

	used[l][r] = 1;
	dp[l][r] = r - l + 1;

	for(int i = l; i <= r; ++i)
	{
		int code = str[i] - 'a';
		mask[l][r] |= (1 << code);
	}

	for(int m = l; m + 1 <= r; ++m)
	{
		calc(l, m);
		calc(m + 1, r);

		int local = dp[l][m] + dp[m + 1][r];
		int local_mask = mask[l][m] | mask[m + 1][r];

		if(mask[l][m] & mask[m + 1][r])
		{
			--local;
			local_mask = mask[l][m] & mask[m + 1][r];
		}

		if(local < dp[l][r])
		{
			dp[l][r] = local;
			mask[l][r] = local_mask;
		}
		else if(local == dp[l][r])
		{
			mask[l][r] |= local_mask;
		}
	}
}

void solve()
{
	cin >> n >> str;
	n = len(str);

	calc(0, n - 1);

	cout << dp[0][n - 1] << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}