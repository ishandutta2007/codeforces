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

const int MAX_N = (1 << 17);

int segtree[2 * MAX_N];

void segtree_ch(int v, int tl, int tr, int i, int x, int type)
{
	if(tl == tr)
	{
		segtree[v] = x;
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(i <= tm)
			segtree_ch(2 * v + 1, tl, tm, i, x, 1 - type);
		else
			segtree_ch(2 * v + 2, tm + 1, tr, i, x, 1 - type);

		if(type)
			segtree[v] = (segtree[2 * v + 1] | segtree[2 * v + 2]);
		else
			segtree[v] = (segtree[2 * v + 1] ^ segtree[2 * v + 2]);
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;

	int sz = (1 << n);

	for(int i = 0; i < sz; ++i)
	{
		int x;
		cin >> x;

		segtree_ch(0, 0, sz - 1, i, x, n % 2);
	}

	for(; m > 0; --m)
	{
		int p, x;
		cin >> p >> x;
		--p;

		segtree_ch(0, 0, sz - 1, p, x, n % 2);

		cout << segtree[0] << "\n";
	}
}

int main(int argc, char** argv)
{
	fast_io();
	solve();

	return 0;
}