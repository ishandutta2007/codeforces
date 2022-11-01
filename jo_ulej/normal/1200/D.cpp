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

const int MAX_N = 2007;

int a[MAX_N][MAX_N], n, k, already_white = 0;

int dp1[MAX_N][MAX_N], sum1[MAX_N][MAX_N];
int dp2[MAX_N][MAX_N], sum2[MAX_N][MAX_N];

void solve()
{
	cin >> n >> k;

	for(int i = 0; i < n; ++i)
	{
		string row;
		cin >> row;

		for(int j = 0; j < n; ++j)
		{
			a[i][j] = (row[j] == 'B');
		}
	}

	for(int i = 0; i < n; ++i)
	{
		int fsum = 0;

		for(int j = 0; j < n; ++j)
			fsum += a[i][j];

		if(!fsum)
		{
			++already_white;
			continue;
		}

		int cur = 0;

		for(int j = 0; j < k; ++j)
			cur += a[i][j];

		for(int j = 0; j + k - 1 < n; ++j)
		{
			dp1[i][j] = (cur == fsum);

			if(j + k < n)
			{
				cur -= a[i][j];
				cur += a[i][j + k];
			}
		}
	}

	for(int j = 0; j < n; ++j)
	{
		int cur = 0;

		for(int i = 0; i < k; ++i)
			cur += dp1[i][j];

		for(int i = 0; i + k - 1 < n; ++i)
		{
			sum1[i][j] = cur;

			if(i + k < n)
			{
				cur -= dp1[i][j];
				cur += dp1[i + k][j];
			}
		}
	}

	for(int j = 0; j < n; ++j)
	{
		int fsum = 0;

		for(int i = 0; i < n; ++i)
			fsum += a[i][j];
		
		if(!fsum)
		{
			++already_white;
			continue;
		}

		int cur = 0;

		for(int i = 0; i < k; ++i)
			cur += a[i][j];

		for(int i = 0; i + k - 1 < n; ++i)
		{
			dp2[i][j] = (cur == fsum);

			if(i + k < n)
			{
				cur -= a[i][j];
				cur += a[i + k][j];
			}
		}
	}

	for(int i = 0; i < n; ++i)
	{
		int cur = 0;

		for(int j = 0; j < k; ++j)
			cur += dp2[i][j];

		for(int j = 0; j + k - 1 < n; ++j)
		{
			sum2[i][j] = cur;

			if(j + k < n)
			{
				cur -= dp2[i][j];
				cur += dp2[i][j + k];
			}		
		}
	}

	int answ = 0;

	for(int i = 0; i + k - 1 < n; ++i)
	{
		for(int j = 0; j + k - 1 < n; ++j)
		{
			answ = max(answ, sum1[i][j] + sum2[i][j]);
		}
	}

	cout << answ + already_white << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}