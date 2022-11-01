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

const int MAX_N = (int)2e5 + 777;

struct Node
{
	ll mod = 0;
	ll min = 0;
};

Node tree[4 * MAX_N];

inline void push(int v)
{
	tree[2 * v + 1].mod += tree[v].mod;
	tree[2 * v + 2].mod += tree[v].mod;

	tree[v].min += tree[v].mod;
	tree[v].mod = 0;
}

inline ll read(int v)
{
	return tree[v].mod + tree[v].min;
}

void change(int v, int tl, int tr, int l, int r, ll x)
{
	if(tl == l && tr == r)
	{
		tree[v].mod += x;
	}
	else
	{
		push(v);
		int tm = (tl + tr) / 2;

		if(r <= tm)
		{
			change(2 * v + 1, tl, tm, l, r, x);		
		}
		else if(l > tm)
		{
			change(2 * v + 2, tm + 1, tr, l, r, x);		
		}
		else
		{
			change(2 * v + 1, tl, tm, l, tm, x);
			change(2 * v + 2, tm + 1, tr, tm + 1, r, x);
		}

		tree[v].min = min(read(2 * v + 1), read(2 * v + 2));
	}
}

ll get(int v, int tl, int tr, int l, int r)
{
	if(tl == l && tr == r)
	{
		return read(v);
	}		
	else
	{
		push(v);
		int tm = (tl + tr) / 2;

		if(r <= tm)
			return get(2 * v + 1, tl, tm, l, r);

		if(l > tm)
			return get(2 * v + 2, tm + 1, tr, l, r);

		ll left_min = get(2 * v + 1, tl, tm, l, tm);
		ll right_min = get(2 * v + 2, tm + 1, tr, tm + 1, r);

		return min(left_min, right_min);
	}
}

ll info[MAX_N];
int answ[MAX_N], n;

void solve()
{
	cin >> n;

	for(int i = 0; i < n; ++i)
	{
		cin >> info[i];
		change(0, 0, n - 1, i, i, info[i]);
	}

	for(int val = 1; val <= n; ++val)
	{
		int low = 1, high = n;
		int pos;

#ifdef __LOCAL
		DBG(val);

		for(int suff = 1; suff <= n; ++suff)
			cout << suff << " -> " << get(0, 0, n - 1, n - suff, n - 1) << endl;		
#endif

		if(get(0, 0, n - 1, n - low, n - low) == 0)
		{
			pos = n - low;
		}
		else
		{
			while(high - low > 1)
			{
				int mid = (low + high) / 2;

				if(get(0, 0, n - 1, n - mid, n - 1) == 0)
					high = mid;
				else
					low = mid;
			}

			pos = n - high;
		}

		DBG(pos);

		if(pos != n - 1)
			change(0, 0, n - 1, pos + 1, n - 1, -val);

		change(0, 0, n - 1, pos, pos, +LL_INF);
		DBG(get(0, 0, n - 1, pos, pos));

		answ[pos] = val;
	}

	for(int i = 0; i < n; ++i)
		cout << answ[i] << " ";

	cout << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}