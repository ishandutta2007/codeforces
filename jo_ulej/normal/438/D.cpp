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

const int MAX_N = (int)1e5 + 7;
ll a[MAX_N];
ll segtree_sum[4 * MAX_N], segtree_max[4 * MAX_N];
int n, m;

inline int maxidx(int i, int j)
{
	return (a[i] > a[j] ? i : j);
}

ll getmax(int v, int tl, int tr, int l, int r)
{
	if(tl == l && tr == r)
	{
		return segtree_max[v];
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(r <= tm)
			return getmax(2 * v + 1, tl, tm, l, r);

		if(l >= tm + 1)
			return getmax(2 * v + 2, tm + 1, tr, l, r);

		ll val1 = getmax(2 * v + 1, tl, tm, l, tm);
		ll val2 = getmax(2 * v + 2, tm + 1, tr, tm + 1, r);

		return maxidx(val1, val2);
	}
}

ll getsum(int v, int tl, int tr, int l, int r)
{
	if(tl == l && tr == r)
	{
		return segtree_sum[v];
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(r <= tm)
			return getsum(2 * v + 1, tl, tm, l, r);

		if(l >= tm + 1)
			return getsum(2 * v + 2, tm + 1, tr, l, r);

		ll val1 = getsum(2 * v + 1, tl, tm, l, tm);
		ll val2 = getsum(2 * v + 2, tm + 1, tr, tm + 1, r);

		return val1 + val2;
	}
}

void ch(int v, int tl, int tr, int i, ll x)
{
	if(tl == tr)
	{
		segtree_sum[v] = x;
		segtree_max[v] = i;
		a[i] = x;
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(i <= tm)
			ch(2 * v + 1, tl, tm, i, x);
		else
			ch(2 * v + 2, tm + 1, tr, i, x);

		segtree_sum[v] = segtree_sum[2 * v + 1] + segtree_sum[2 * v + 2];
		segtree_max[v] = maxidx(segtree_max[2 * v + 1], segtree_max[2 * v + 2]);
	}
}

void solve()
{
	cin >> n >> m;

	for(int i = 0; i < n; ++i)
	{
		ll x;
		cin >> x;

		ch(0, 0, n - 1, i, x);
	}

	string output;

	for(; m > 0; --m)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			int l, r;
			cin >> l >> r;
			--l, --r;

			output += to_string(getsum(0, 0, n - 1, l, r)) + "\n";
		}
		else if(type == 2)
		{
			int l, r;
			ll x;

			cin >> l >> r >> x;
			--l, --r;

			for(;;)
			{
				int j = getmax(0, 0, n - 1, l, r);

				if(a[j] < x)
					break;

				ch(0, 0, n - 1, j, a[j] % x);
			}
		}
		else
		{
			int i;
			ll x;

			cin >> i >> x;
			--i;

			ch(0, 0, n - 1, i, x);
		}
	}
	
	cout << output;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}