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

int cnt[26];

void solve()
{
	int n;
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		string t;
		cin >> t;

		++cnt[t.front() - 'a'];
	}

	int answ = 0;

	for(int ch = 0; ch < 26; ++ch)
	{
		int value = cnt[ch];
		int loc = INT_INF;

		for(int a = 0; a <= value; ++a)
		{
			loc = min(loc, (a * (a - 1)) / 2 + ((value - a) * (value - a - 1)) / 2);
		}
		
		answ += loc;
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}