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

const int MAX_M = 1007;

int m, n;
bitset<MAX_M> rows[MAX_M], intr[MAX_M];

int dp[MAX_M][MAX_M], sum[MAX_M];

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

inline bool comp(const bitset<MAX_M>& lhs, const bitset<MAX_M>& rhs)
{
	bitset<MAX_M> x = lhs ^ rhs;

#ifdef __LOCAL
	int i = 0;

	while(i < MAX_M && !x[i])
		++i;
#else
	int i = x._Find_first();
#endif

	return (i < MAX_M && lhs[i] < rhs[i]);
}

void solve()
{
	cin >> m >> n;

	for(int k = 1; k <= m; ++k)
	{
		for(int l = 1; l < k; ++l)
		{
			dp[k][l] = add(dp[k - 1][l - 1], mult(l, dp[k - 1][l]));
			sum[k] = add(sum[k], dp[k][l]);
		}

		dp[k][k] = 1;
		sum[k] = add(sum[k], dp[k][k]);
	}

	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			char ch;
			cin >> ch;

			rows[i][j] = (ch == '1');
		}
	}

	for(int i = 0; i < m; ++i)
	{
		for(int j = 0; j < m; ++j)
			intr[i][j] = 1;

		for(int j = 0; j < m; ++j)
		{
			if(rows[j][i])
				intr[i] &= rows[j];
			else
				intr[i] &= ~rows[j];
		}	
	}

	sort(intr, intr + m, comp);

	int answ = 1;

	for(int i = 0; i < m; ++i)
	{
		if(!i || comp(intr[i - 1], intr[i]))
		{
			int cnt = intr[i].count();
			DBG(cnt); DBG(sum[cnt]);

			answ = mult(answ, sum[cnt]);
		}
	}

#ifdef __LOCAL
	for(int i = 0; i < m; ++i)
	{
		cout << i << ": ";

		for(int j = 0; j < m; ++j)
			cout << intr[i][j];

		cout << endl;
	}
#endif

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}