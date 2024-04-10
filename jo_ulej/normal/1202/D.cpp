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

inline ll find(ll n)
{
	ll low = 0, high = n + 1337LL;

	while(high - low > 1)
	{
		ll mid = (low + high) / 2;

		if((mid * (mid - 1)) / 2 <= n)
			low = mid;
		else
			high = mid;
	}

	return low;
}

void solve()
{
	ll n;
	cin >> n;

	vector<ll> decompose;

	while(n)
	{
		ll cnt = find(n);
		decompose.push_back(cnt);

		n -= (cnt * (cnt - 1)) / 2;
	}

	reverse(decompose.begin(), decompose.end());

	for(int i = len(decompose) - 1; i > 0; --i)
		decompose[i] -= decompose[i - 1];

	string answ = "1";

	for(auto& x: decompose)
	{
		while(x--)
			answ.push_back('3');

		answ.push_back('7');
	}

	cout << answ << endl;
	DBG(len(answ));
}

int main()
{
	fast_io();

	int T;
	cin >> T;

	while(T--)
		solve();

	return 0;
}