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

#define move __Moove

const int MAX_M = (int)1e5 + 77;

ll p[MAX_M];
ll n, m, k, move = 0;

void solve()
{
	cin >> n >> m >> k;

	for(ll i = 0; i < m; ++i)
	{
		cin >> p[i];
		--p[i];
	}

	ll answ = 0;

	for(ll i = 0; i < m;)
	{
		ll block = (p[i] - move) / k;
		ll j = i;

		while(j + 1 < m && (p[j + 1] - move) / k == block)
			++j;

		move += (j - i + 1);

		i = j + 1;
		++answ;
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}