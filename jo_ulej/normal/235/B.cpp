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

ld slow(const vector<ld>& p)
{
	int n = len(p);
	vector<ld> dp(n, 0);

	for(int i = 0; i < n; ++i)
	{
		ld acc = 1.0;

		for(int suff = 0; suff <= i + 1; ++suff)
		{
			ld prob = acc * (i - suff >= 0 ? 1.0 - p[i - suff] : 1.0);

			dp[i] += prob * (((ld)suff) * ((ld)suff) + (i - suff - 1 >= 0 ? dp[i - suff - 1] : 0.0));

			if(i - suff >= 0)
				acc *= p[i - suff];
		}
	}

	return dp.back();
}

ld calc(const vector<ld>& p, int l, int r)
{
	if(r - l == 1)
	{
		return p[l];
	}
	else
	{
		int m = (l + r) / 2;
		ld answ = calc(p, l, m) + calc(p, m, r);
		ld pref = 0.0, suff = 0.0, acc = 1.0;

		for(int i = m - 1; i >= l; --i)
		{
			acc *= p[i];
			ld length = (ld)(m - i);

			ld prob = acc;

			if(i - 1 >= l)
				prob *= (1.0 - p[i - 1]);

			pref += prob * length;
		}

		acc = 1.0;

		for(int i = m; i < r; ++i)
		{
			acc *= p[i];
			ld length = (ld)(i - m + 1);

			ld prob = acc;

			if(i + 1 < r)
				prob *= (1.0 - p[i + 1]);

			suff += prob * length;
		}

		answ += 2.0 * suff * pref;

		return answ;
	}
}

ld fast(const vector<ld>& p)
{
	return calc(p, 0, len(p));
}

void solve()
{
	int n;
	cin >> n;

	vector<ld> p(n);

	for(auto& elem: p)
		cin >> elem;

#ifdef __LOCAL
	cout << fixed << setprecision(12) << slow(p) << endl;	
#endif

	cout << fixed << setprecision(12) << fast(p) << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}