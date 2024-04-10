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

const int MAX_N = (int)4e5 + 777;
const int MAX_C = (int)20;
const int SZ    = (1 << MAX_C) + 228;

int a[MAX_N], n;
ll cnt[MAX_C][MAX_C];
ll dp[SZ];

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		a[i] = fetch<int>() - 1;

	for(int l = 0; l < MAX_C; ++l)
	{
		for(int r = 0; r < MAX_C; ++r)
		{
			ll cur = 0;

			if(l == r)
				continue;

			for(int i = 0; i < n; ++i)
			{
				cur += (a[i] == r);
				cnt[l][r] += (a[i] == l) * cur;
			}
		}		
	}

	for(int msk = 1; msk < (1 << MAX_C); ++msk)
	{
		dp[msk] = LL_INF;

		for(int last = 0; last < MAX_C; ++last)
		{
			if((msk >> last) & 1)
			{
				ll local = dp[msk ^ (1 << last)];

				for(int col = 0; col < MAX_C; ++col)
				{
					if((msk >> col) & 1)
						local += cnt[col][last];
				}

				dp[msk] = (dp[msk] < local ? dp[msk] : local);
			}
		}
	}

	cout << dp[(1 << MAX_C) - 1] << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}