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

const int MOD = (int)1e9 + 7;

#ifdef __LOCAL
const int MAX_N = 1000;
const int MAX_VALUE = 1000;
#else
const int MAX_N = (int)2e5 + 777;
const int MAX_VALUE = (int)1e6 + 777;
#endif

int sieve[MAX_VALUE];
vector<int> prime_divisors[MAX_VALUE];

void run_sieve()
{
	for(int i = 2; i < MAX_VALUE; ++i)
	{
		if(sieve[i])
			continue;

		prime_divisors[i].push_back(i);

		for(int j = 2 * i; j < MAX_VALUE; j += i)
		{
			sieve[j] = 1;
			prime_divisors[j].push_back(i);
		}
	}
}

inline int add(int x, int y)
{
	return (x + y >= MOD ? x + y - MOD : x + y);
}

inline int sub(int x, int y)
{
	return (x - y < 0 ? x - y + MOD : x - y);
}

inline int mult(int x, int y)
{
	return (x * 1LL * y) % MOD;
}

int binpow(int x, int y)
{
	if(x == 0)
		return 0;

	if(x == 1 || y == 0)
		return 1;

	int ret = binpow(x, y >> 1);
	ret = mult(ret, ret);

	if(y & 1)
		ret = mult(ret, x);

	return ret;
}

inline int divide(int x, int y)
{
	return mult(x, binpow(y, MOD - 2));
}

int fenwick[MAX_N];

inline void init_fenwick()
{
	for(int i = 0; i < MAX_N; ++i)
		fenwick[i] = 1;
}

inline void fenwick_mult(int pos, int x)
{
	for(; pos < MAX_N; pos |= pos + 1)
		fenwick[pos] = mult(fenwick[pos], x);
}

inline int fenwick_get(int r)
{
	int acc = 1;

	for(; r >= 0; r = (r & (r + 1)) - 1)
		acc = mult(acc, fenwick[r]);

	return acc;
}

inline void subsegment_mult(int l, int r, int x)
{
	fenwick_mult(l, x);
	fenwick_mult(r + 1, divide(1, x));
}

inline int get_elem(int pos)
{
	return fenwick_get(pos);
}

struct Query
{
	int left, right, index;
};

int a[MAX_N], n;
Query queries[MAX_N];
vector<int> by_right[MAX_N];
int q;

int pref[MAX_N];

int answ[MAX_N];
int lst[MAX_VALUE];

void solve()
{
	init_fenwick();
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];

	pref[0] = a[0];

	for(int i = 1; i < n; ++i)
		pref[i] = mult(a[i], pref[i - 1]);

	cin >> q;

	for(int i = 0; i < q; ++i)
	{
		Query q;
		cin >> q.left >> q.right;
		--q.left, --q.right;

		q.index = i;
		queries[i] = q;
		by_right[q.right].push_back(i);
	}

	memset(lst, NIL, sizeof(lst));

	for(int r = 0; r < n; ++r)
	{
		int val = a[r];

		for(auto& p: prime_divisors[val])
		{
			subsegment_mult(lst[p] + 1, r, sub(1, divide(1, p)));
			lst[p] = r;
		}

		for(auto& index: by_right[r])
		{
			int l = queries[index].left;	
			answ[index] = get_elem(l);
			answ[index] = mult(answ[index], pref[r]);

			if(l > 0)
				answ[index] = divide(answ[index], pref[l - 1]);

		}
	}

	for(int i = 0; i < q; ++i)
		cout << answ[i] << endl;
}

int main()
{
	run_sieve();

	fast_io();
	solve();

	return 0;
}