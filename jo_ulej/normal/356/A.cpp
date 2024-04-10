#include <bits/stdc++.h>
 
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
static mt19937 _g(time(nullptr));

inline ll randint(ll a, ll b) { ll w = (_g() << 31LL) ^ _g(); return a + w % (b - a + 1); }
inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); };
template<typename T> inline T sign(T x) { return T(x > 0) - T(x < 0); }
template<typename T> inline ostream& operator<<(ostream& os, const vector<T>& v) { for(auto el: v) cout << el << " "; return os; }

const int MAX_N = (int)3e5 + 6;

int segtree[4 * MAX_N];

void segtree_ch(int v, int tl, int tr, int l, int r, int x)
{
	if(segtree[v] != 0)
		return;

	if(tl == l && tr == r)
	{
		segtree[v] = x;
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(r <= tm)
		{
			segtree_ch(2 * v + 1, tl, tm, l, r, x);
		}
		else if(l >= tm + 1)
		{
			segtree_ch(2 * v + 2, tm + 1, tr, l, r, x);
		}
		else
		{
			segtree_ch(2 * v + 1, tl, tm, l, tm, x);
			segtree_ch(2 * v + 2, tm + 1, tr, tm + 1, r, x);
		}
	}
}

int segtree_get(int v, int tl, int tr, int i)
{
	if(tl == tr)
	{
		return segtree[v];
	}
	else
	{
		int tm = (tl + tr) / 2;
		int val;

		if(i <= tm)
			val = segtree_get(2 * v + 1, tl, tm, i);
		else
			val = segtree_get(2 * v + 2, tm + 1, tr, i);

		//DBG(val);

		return (val == 0 ? segtree[v] : val);
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		int l, r, x;
		cin >> l >> r >> x;

		if(l == x)
		{
			segtree_ch(0, 1, n, l + 1, r, x);
		}
		else if(r == x)
		{
			segtree_ch(0, 1, n, l, r - 1, x);
		}
		else
		{
			segtree_ch(0, 1, n, l, x - 1, x);
			segtree_ch(0, 1, n, x + 1, r, x);
		}
	}

	for(int i = 1; i <= n; ++i)
		cout << segtree_get(0, 1, n, i) << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}