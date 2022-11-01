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

const int MAX_N = (int)1e5 + 6;

struct Node
{
	int val = 0, mod = 0;
};

Node segtree[4 * MAX_N];

void push(int v)
{
	segtree[2 * v + 1].mod |= segtree[v].mod;
	segtree[2 * v + 2].mod |= segtree[v].mod;
	segtree[v].mod = 0;

	segtree[v].val = (segtree[2 * v + 1].mod | segtree[2 * v + 1].val) & (segtree[2 * v + 2].mod | segtree[2 * v + 2].val);
}

void segtree_ch(int v, int tl, int tr, int l, int r, int x)
{
	if(tl != tr)
		push(v);

	if(l == tl && r == tr)
	{
		segtree[v].mod |= x;
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
		
		segtree[v].val = (segtree[2 * v + 1].mod | segtree[2 * v + 1].val) & (segtree[2 * v + 2].mod | segtree[2 * v + 2].val);
	}
}

int segtree_get(int v, int tl, int tr, int l, int r)
{
	if(tl != tr)
		push(v);

	if(l == tl && r == tr)
	{
		return segtree[v].mod | segtree[v].val;
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(r <= tm)
			return segtree[v].mod | segtree_get(2 * v + 1, tl, tm, l, r);

		if(l >= tm + 1)
			return segtree[v].mod | segtree_get(2 * v + 2, tm + 1, tr, l, r);

		int val1 = segtree_get(2 * v + 1, tl, tm, l, tm);
		int val2 = segtree_get(2 * v + 2, tm + 1, tr, tm + 1, r);

		return segtree[v].mod | (val1 & val2);
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	vector<tuple<int, int, int>> data;

	for(int i = 0; i < m; ++i)
	{
		int l, r, q;
		cin >> l >> r >> q;
		--l, --r;

		data.emplace_back(l, r, q);

		segtree_ch(0, 0, MAX_N - 1, l, r, q);
	}

	for(auto& el: data)
	{
		int l = get<0>(el), r = get<1>(el), q = get<2>(el);

		if(segtree_get(0, 0, MAX_N - 1, l, r) != q)
		{
			cout << "NO" << endl;
			return;
		}
	}

	cout << "YES" << endl;

	for(int i = 0; i < n; ++i)
		cout << segtree_get(0, 0, MAX_N - 1, i, i) << " ";

	cout << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}