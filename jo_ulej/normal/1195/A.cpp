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

const int SZ = 1007;

int cnt[SZ];
int n, k;

inline int d(int x)
{
	return (x >> 1) + (x & 1);
}

void solve()
{
	cin >> n >> k;

	for(int i = 0; i < n; ++i)
	{
		int type;
		cin >> type;

		++cnt[type - 1];
	}

	int have = d(n), answ = 0, c = 0;
	DBG(have);

	for(int i = 0; i < k; ++i)
	{
		have -= cnt[i] >> 1;
		answ += cnt[i] - (cnt[i] & 1);

		c += cnt[i] & 1;

		DBG(i); DBG(cnt[i]);
	}

	DBG(have); DBG(c);

	answ += min(have, d(c));

	DBG("00");

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}