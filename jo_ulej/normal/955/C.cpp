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

const int MAX_POWER = 65;
vector<ll> powers;

int count(ll x, ll r)
{
	int iter = 0;

	while(r >= x)
	{
		++iter;
		r /= x;
	}

	return iter;
}

ll find_max_base(ll p, ll r)
{
	ll low = 1, high = r + 1;

	while(high - low > 1)
	{
		ll mid = (low + high) / 2;

		if(count(mid, r) >= p)
			low = mid;
		else
			high = mid;
	}

	return low;
}

ll binpow(ll x, ll y)
{
	if(x == 0)
		return 0;

	if(x == 1 || y == 0)
		return 1;

	ll ret = binpow(x, y / 2);
	ret *= ret;

	if(y & 1)
		ret *= x;

	return ret;
}

ll get_sqrt(ll num)
{
	return find_max_base(2, num);		
}

void precalc()
{
	const ll INF = (ll)1e18 + 1;

	for(ll power = 3; power < MAX_POWER; ++power)
	{
		ll max_base = find_max_base(power, INF);

		for(ll i = 1; i <= max_base; ++i)
		{
			ll temp = binpow(i, power);
			ll j = get_sqrt(temp);

			if(j * j < temp)
				powers.push_back(temp);
		}
	}

	sort(powers.begin(), powers.end());
	powers.erase(unique(powers.begin(), powers.end()), powers.end());
}

ll solve(ll r)
{
	ll answ = get_sqrt(r);	
	answ += upper_bound(powers.begin(), powers.end(), r) - powers.begin();

	return answ;
}

void solve()
{
	ll l, r;
	cin >> l >> r;

	ll answ = solve(r);

	if(l > 1)
		answ -= solve(l - 1);

	cout << answ << endl;
}

int main()
{
	precalc();
	fast_io();

	int T;
	cin >> T;

	while(T--)
		solve();

	return 0;
}