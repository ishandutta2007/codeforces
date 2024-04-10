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

const int MAX_N = (int)2e5 + 777;
const int MAX_LOG_N = 20;

int a[MAX_N], p[MAX_N], pos[MAX_N];
int nxt[MAX_LOG_N][MAX_N], lst[MAX_N];
int fin[MAX_N];
int n, m, q;

int segtree[4 * MAX_N];

void build(int v, int tl, int tr)
{
	if(tl == tr)
	{
		segtree[v] = fin[tl];
	}
	else
	{
		int tm = (tl + tr) / 2;

		build(2 * v + 1, tl, tm);
		build(2 * v + 2, tm + 1, tr);

		segtree[v] = min(segtree[2 * v + 1], segtree[2 * v + 2]);
	}
}

int getmin(int v, int tl, int tr, int l, int r)
{
	if(tl == l && tr == r)
	{
		return segtree[v];
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(r <= tm)
			return getmin(2 * v + 1, tl, tm, l, r);

		if(l >= tm + 1)
			return getmin(2 * v + 2, tm + 1, tr, l, r);

		int val1 = getmin(2 * v + 1, tl, tm, l, tm);
		int val2 = getmin(2 * v + 2, tm + 1, tr, tm + 1, r);

		return min(val1, val2);
	}
}

void solve()
{
	cin >> n >> m >> q;

	for(int i = 0; i < n; ++i)
	{
		cin >> p[i];
		--p[i];

		pos[p[i]] = i;
	}

	for(int i = 0; i < m; ++i)
	{
		cin >> a[i];
		--a[i];

		a[i] = pos[a[i]];
	}

	for(int i = 0; i < n; ++i)
		lst[i] = m;

	nxt[0][m] = m;

	for(int i = m - 1; i >= 0; --i)
	{
		nxt[0][i] = lst[(a[i] + 1) % n];
		lst[a[i]] = i;
	}

	for(int log = 1; log < MAX_LOG_N; ++log)
		for(int i = 0; i <= m; ++i)
			nxt[log][i] = nxt[log - 1][nxt[log - 1][i]];

	for(int i = 0; i < m; ++i)
	{
		fin[i] = i;

		for(int log = 0; log < MAX_LOG_N; ++log)
		{
			if((1 << log) & (n - 1))
				fin[i] = nxt[log][fin[i]];
		}
	}

	build(0, 0, m - 1);

	string output;

	for(; q > 0; --q)
	{
		int l, r;
		cin >> l >> r;
		--l, --r;

		output += to_string((int)(getmin(0, 0, m - 1, l, r) <= r));
	}

	cout << output << endl;
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}