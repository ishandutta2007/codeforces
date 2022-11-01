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

inline int add(int x, int y)
{
	int r = x + y;

	return (r >= mod ? r - mod : r);
}

inline int sub(int x, int y)
{
	int r = x - y;

	return (r < 0 ? r + mod : r);
}

inline int mult(int x, int y)
{
	return (x * 1LL * y) % mod;
}

int binpow(int x, int y)
{
	if(!x)
		return 0;

	if(!y || x == 1)
		return 1;

	int ret = binpow(x, y / 2);
	ret = mult(ret, ret);

	if(y & 1)
		ret = mult(ret, x);

	return ret;
}

inline int inv(int x)
{
	return binpow(x, mod - 2);
}

inline int divide(int x, int y)
{
	return mult(x, inv(y));
}

const int MAX_K = 1007;

int k, pa, pb, alpha;
int dp[MAX_K][MAX_K];
bool met[MAX_K][MAX_K];

int get_dp(int i, int j)
{
	if(met[i][j])
		return dp[i][j];

	met[i][j] = true;

	if(i + j >= k)
	{
		dp[i][j] = add(j,
				       add(i, inv(sub(1, alpha))));
	}
	else
	{
		dp[i][j] = add(mult(alpha, get_dp(i + 1, j)),
					   mult(sub(1, alpha), get_dp(i, j + i)));
	}

	return dp[i][j];
}

void solve()
{
	cin >> k >> pa >> pb;
	alpha = divide(pa, add(pa, pb));

	cout << sub(get_dp(1, 0), 1) << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}