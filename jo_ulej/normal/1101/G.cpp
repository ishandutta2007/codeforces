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

const ll mod = 1e9 + 7;
const int NIL = -1;
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T, typename S> inline ostream& operator<<(ostream& os, const pair<T, S> p) { cout << "[" << p.first << ";" << p.second << "]"; return os; }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)2e5 + 777;
const int N_BITS = 32;

int a[MAX_N], n;
int basis[N_BITS];

inline int add(int msk)
{
	for(int j = 0; j < N_BITS; ++j)
	{
		if((msk >> j) & 1)
		{
			if(basis[j])
			{
				msk ^= basis[j];
			}
			else
			{
				basis[j] = msk;
				return 1;
			}
		}
	}

	return 0;
}

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];

		if(i > 0)
			a[i] ^= a[i - 1];
	}

	if(a[n - 1] == 0)
	{
		cout << NIL << endl;
		return;
	}

	int answ = 0;

	for(int i = n - 1; i >= 0; --i)
		answ += add(a[i]);

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}