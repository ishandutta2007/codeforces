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

#ifdef __LOCAL
const int MAX_C = 1000;
#else
const int MAX_C = (int)4e6 + 77;
#endif

vector<int> pts[MAX_C];

struct node
{
	int mod = 0, mx = 0;
};

node tree[4 * MAX_C];

inline void push(int v, int tl, int tr)
{
	tree[v].mx += tree[v].mod;

	if(tl != tr)
	{
		tree[2 * v + 1].mod += tree[v].mod;
		tree[2 * v + 2].mod += tree[v].mod;
	}

	tree[v].mod = 0;
}

int get(int v, int tl, int tr, int l, int r)
{
	push(v, tl, tr);

	if(tl == l && tr == r)
	{
		return tree[v].mod + tree[v].mx;
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(r <= tm)
			return get(2 * v + 1, tl, tm, l, r);

		if(l >= tm + 1)
			return get(2 * v + 2, tm + 1, tr, l, r);

		int left = get(2 * v + 1, tl, tm, l, tm);
		int right = get(2 * v + 2, tm + 1, tr, tm + 1, r);

		return max(left, right);
	}
}

void change(int v, int tl, int tr, int l, int r, int x)
{
	push(v, tl, tr);

	if(tl == l && tr == r)
	{
		tree[v].mod += x;
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(r <= tm)
		{
			change(2 * v + 1, tl, tm, l, r, x);
		}
		else if(l >= tm + 1)
		{
			change(2 * v + 2, tm + 1, tr, l, r, x);
		}
		else
		{
			change(2 * v + 1, tl, tm, l, tm, x);
			change(2 * v + 2, tm + 1, tr, tm + 1, r, x);
		}

		tree[v].mx = max(tree[2 * v + 1].mod + tree[2 * v + 1].mx, tree[2 * v + 2].mod + tree[2 * v + 2].mx);
	}
}

void solve()
{
	int n, r;
	cin >> n >> r;
	r = 2 * r + 1;

	for(int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;

		int nx = y + x + MAX_C / 2;
		int ny = y - x + MAX_C / 2;

		pts[ny].push_back(nx);
	}

	int answ = 0;

	for(int i = 0; i < MAX_C; ++i)
	{
		for(auto x: pts[i])
		{
			int lambda = max(0, x - r + 1);
			int rho = x;

			change(0, 0, MAX_C - 1, lambda, rho, 1);
		}

		if(i - r >= 0)
		{
			for(auto x: pts[i - r])
			{
				int lambda = max(0, x - r + 1);
				int rho = x;

				change(0, 0, MAX_C - 1, lambda, rho, -1);
			}
		}

		answ = max(answ, get(0, 0, MAX_C - 1, 0, MAX_C - 1));
	}

	cout << answ << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}