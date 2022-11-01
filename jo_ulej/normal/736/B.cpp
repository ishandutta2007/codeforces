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

inline bool is_prime(int x)
{
	if(x == 1)
		return false;

	if(!(x & 1) && x > 2)
		return false;

	for(int i = 2; i * i <= x; ++i)
	{
		if(x % i == 0)
			return false;
	}

	return true;
}

void solve()
{
	int n;
	cin >> n;

	if(is_prime(n))
	{
		cout << "1" << endl;
		return;
	}

	if(!(n & 1) && n > 100)
	{
		cout << "2" << endl;
		return;
	}

	for(int i = 2; n - i > 1; ++i)
	{
		int j = n - i;

		if(is_prime(i) && is_prime(j))
		{
			cout << "2" << endl;
			return;
		}

		if(clock() > 1.8 * CLOCKS_PER_SEC)
			break;
	}

	cout << "3" << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}