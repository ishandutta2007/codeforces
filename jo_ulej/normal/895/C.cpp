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

const int MOD = 1e9 + 7;
const int MAX_VALUE = 71;
const int MAX_N = (int)1e5 + 777;

int primes[MAX_VALUE], n_primes = 0;

void precalc()
{
	for(int i = 2; i < MAX_VALUE; ++i)
	{
		bool good = true;

		for(int j = 2; j * j <= i; ++j)
		{
			if(i % j == 0)
			{
				good = false;
				break;
			}		
		}

		if(good)
			primes[n_primes++] = i;
	}

	DBG(n_primes);
}

int a[MAX_N], n;
int basis[MAX_VALUE];

int add(int v)
{
	for(int j = 0; j < n_primes; ++j)
	{
		if(v & (1 << j))
		{
			if(basis[j])
			{
				v ^= basis[j];
			}
			else
			{
				basis[j] = v;
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
		int val;
		cin >> val;

		for(int j = 0; j < n_primes; ++j)
		{
			int count = 0;

			for(; val % primes[j] == 0; val /= primes[j])
				++count;

			if(count & 1)
				a[i] |= (1 << j);
		}
	}

	int basis_sz = 0;

	for(int i = 0; i < n; ++i)
		basis_sz += add(a[i]);

	int answ = 1;

	for(int i = 0; i < n - basis_sz; ++i)
	{
		answ += answ;

		if(answ >= MOD)
			answ -= MOD;
	}

	--answ;

	if(answ < 0)
		answ += MOD;

	cout << answ << endl;
}

int main()
{
	precalc();

	fast_io();
	solve();

	return 0;
}