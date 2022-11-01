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

namespace stupid
{
	int solve(int n, int k)
	{
		vector<int> dp(n + 1, 0);

		for(int i = 1; i <= n; ++i)
			for(int j: {1, 2, k})
				if(i - j >= 0)
					dp[i] |= !dp[i - j];

		return dp[n];
	}

	void show(int maxn, int maxk)
	{
		for(int n = 0; n <= maxn; ++n)
		{
			cout << NIL << " " << NIL << " " << NIL << " ";

			for(int k = 3; k <= maxk; ++k)
				cout << solve(n, k) << " ";

			cout << endl;
		}
	}
};

namespace smart
{
	int solve(int n, int k)
	{
		if(k % 3 == 0)
		{
			n %= (k + 1);

			if(n == k)
				return 1;
			else
				return n % 3 > 0;
		}
		else
		{
			return n % 3 > 0;
		}
	}
}

namespace check
{
	void run_stress(int maxn, int maxk)
	{
		for(int n = 1; n <= maxn; ++n)
		{
			for(int k = 1; k <= maxk; ++k)
			{
				int stupid_answ = stupid::solve(n, k);
				int smart_answ = smart::solve(n, k);

				if(stupid_answ != smart_answ)
				{
					DBG(n); DBG(k);
					DBG(stupid_answ); DBG(smart_answ);

					exit(NIL);
				}
			}
		}

		cout << "stress passed" << endl;
	}
};

int main()
{
#ifdef __LOCAL
	check::run_stress(500, 500);
#endif

	fast_io();

	int T;
	cin >> T;

	while(T--)
	{
		int n, k;
		cin >> n >> k;

		cout << (smart::solve(n, k) ? "Alice" : "Bob") << endl;
	}

	return 0;
}