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
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

void solve()
{
	string a = "aeiou";

	int k;
	cin >> k;

	for(int x = 1; x <= k; ++x)
	{
		if(k % x == 0)
		{
			int y = k / x;

			if(x >= 5 && y >= 5)
			{
				for(int i = 0; i < x; ++i)
				{
					for(int j = 0; j < y; ++j)
					{
						if(j < (int)a.size())
							cout << a[(j + i) % a.size()];
						else
							cout << a[i % a.size()];
					}
#ifdef __LOCAL
					cout << endl;
#endif
				}

				cout << endl;

				return;
			}
		}
	}

	cout << "-1" << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}