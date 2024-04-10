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

#define len(X) ((int)(X).size())

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
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

#ifndef __LOCAL
#define gcd __gcd
#endif

const int MAX_N     = (int)3e5 + 77;
const int MAX_VALUE = (int)1.5e7 + 77;
int cnt[MAX_VALUE], sieve[MAX_VALUE], a[MAX_N];

void solve()
{
	int n;
	cin >> n;

	for(int i = 2; i < MAX_VALUE; ++i)
		if(!sieve[i])
			for(int j = i; j < MAX_VALUE; j += i)
				sieve[j] = i;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	int g = a[0];

	for(int i = 1; i < n; ++i)
		g = gcd(g, a[i]);

	for(int i = 0; i < n; ++i)
		a[i] /= g;

	int answ = n;

	for(int i = 0; i < n; ++i)
	{
		int x = a[i];

		while(x != 1)
		{
			int p = sieve[x];
			++cnt[p];

			answ = min(answ, n - cnt[p]);

			while(x % p == 0)
				x /= p;		
		}
	}

	cout << (answ == n ? -1 : answ) << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}