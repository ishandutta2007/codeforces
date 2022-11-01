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

const int MAX_N = (int)2e5 + 77;

int a[MAX_N], b[MAX_N], z[MAX_N], n, k;

inline int getsum(int l, int r)
{
	return b[r] - (l ? b[l - 1] : 0);
}

void solve()
{
	cin >> n >> k;

	for(int i = 0; i < n; ++i)
	{
		char chr;
		cin >> chr;

		if(chr == 'R')
			a[i] = 0;
		else if(chr == 'G')
			a[i] = 1;
		else
			a[i] = 2;
			
		a[i] -= i % 3;
		a[i] += 3;
		a[i] %= 3;
	}

	int answ = INT_INF;

	for(int v = 0; v < 3; ++v)
	{
		for(int i = 0; i < n; ++i)
			b[i] = (a[i] == v);

		for(int i = 1; i < n; ++i)
			b[i] += b[i - 1];

		for(int i = 0; i + k - 1 < n; ++i)
		{
			int diff = k - getsum(i, i + k - 1);
			answ = min(answ, diff);
		}
	}

	cout << answ << endl;
}

int main()
{
	fast_io();

	int q;
	cin >> q;

	while(q--)
		solve();

	return 0;
}