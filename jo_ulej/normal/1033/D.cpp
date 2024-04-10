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
	//#define endl '\n'
#endif
 
using namespace std;

using ll = long long int;
using ull = unsigned long long int;
using ld  = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int INT_INF = (int)(2e9);
const ll  LL_INF  = (ll)(3e18);

const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }
template<typename T> inline T fetch() { T ret; cin >> ret; return ret; }
template<typename T> inline void goodbye(const T& val) { cout << val << endl; exit(0); }

const int MAGIC = (int)2e6;
const int MOD = 998244353;

int add(int x, int y)
{
	return (x + y >= MOD ? x + y - MOD : x + y);
}

int norm(int x)
{
	x %= MOD;

	return (x < 0 ? x + MOD : x);
}

int mult(int x, int y)
{
	return (x * 1LL * y) % MOD;
}

const int MAX_N = 577;

ll a[MAX_N];
int n;

ll GCD(ll x, ll y)
{
	return (x == 0 ? y : GCD(y % x, x));
}

ll find2(ll x)
{
	ll low = 1, high = (ll)2e9;

	while(high - low > 1)
	{
		ll mid = (low + high) / 2;

		if(mid * mid <= x)
			low = mid;
		else
			high = mid;
	}

	return low;
}

ll find3(ll x)
{
	ll low = 1, high = (ll)1.5e6;

	while(high - low > 1)
	{
		ll mid = (low + high) / 2;

		if(mid * mid * mid <= x)
			low = mid;
		else
			high = mid;
	}

	return low;
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	vector<ll> single, pairs, gcds;

	for(int i = 0; i < n; ++i)
	{
		ll sq2 = find2(a[i]);
		ll sq3 = find3(a[i]);
		ll sq4 = find2(sq2);

		if(sq4 * sq4 * sq4 * sq4 == a[i])
		{
			single.push_back(sq4);
			single.push_back(sq4);
			single.push_back(sq4);
			single.push_back(sq4);
		}
		else if(sq2 * sq2 == a[i])
		{
			single.push_back(sq2);
			single.push_back(sq2);
		}
		else if(sq3 * sq3 * sq3 == a[i])
		{
			single.push_back(sq3);
			single.push_back(sq3);
			single.push_back(sq3);
		}
		else
		{
			pairs.push_back(a[i]);
		}
	}

	DBG(single);
	DBG(pairs);

	for(auto& x: pairs)
	{
		for(auto& y: pairs)
		{
			if(x == y)
				continue;

			ll g = GCD(x, y);

			if(g > 1)
				gcds.push_back(g);
		}
	}

	for(auto& pr: pairs)
	{
		ll d = 1;

		for(auto& s: single)
		{
			if(pr % s == 0)
			{
				d = s;	
				break;
			}
		}

		for(auto& g: gcds)
		{
			if(d > 1)
				break;

			if(pr % g == 0)
				d = g;
		}

		if(d == 1)
			continue;
	
		single.push_back(d);
		single.push_back(pr / d);

		pr = 1;
	}

	DBG(single);
	DBG(pairs);

	int answ = 1;
	sort(single.begin(), single.end());
	sort(pairs.begin(), pairs.end());

	for(int i = 0; i < len(single);)
	{
		int j = i;

		while(j + 1 < len(single) && single[j + 1] == single[i])
			++j;

		answ = mult(answ, norm(j - i + 2));
		i = j + 1;
	}

	for(int i = 0; i < len(pairs);)
	{
		int j = i;

		while(j + 1 < len(pairs) && pairs[j + 1] == pairs[i])
			++j;

		int temp = norm(j - i + 2);
		temp = mult(temp, temp);

		if(pairs[i] > 1)
			answ = mult(answ, temp);

		i = j + 1;
	}

	cout << answ << endl;
}

int main()
{
	//fast_io();
	solve();

	return 0;
}