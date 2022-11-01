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

int segtree[4 * MAX_N];

void ch(int v, int tl, int tr, int i, int dlt)
{
	if(tl == tr)
	{
		segtree[v] += dlt;
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(i <= tm)
			ch(2 * v + 1, tl, tm, i, dlt);
		else
			ch(2 * v + 2, tm + 1, tr, i, dlt);

		segtree[v] = max(segtree[2 * v + 1], segtree[2 * v + 2]);
	}
}

int get(int v, int tl, int tr, int i)
{
	if(!segtree[v])
		return -1;

	if(tl == tr)
	{
		return (tl >= i ? tl : -1);
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(i >= tm + 1)
			return get(2 * v + 2, tm + 1, tr, i);

		int ind1 = get(2 * v + 1, tl, tm, i);

		if(ind1 != -1)
			return ind1;

		return get(2 * v + 2, tm + 1, tr, i);
	}
}

void solve()
{
	int n;
	cin >> n;

	vector<int> a(n), b(n);

	for(auto& el: a)
		cin >> el;

	for(auto& el: b)
	{
		cin >> el;
		ch(0, 0, n - 1, el, 1);
	}

	vector<int> c(n, -1);

	for(int i = 0; i < n; ++i)
	{
		int try1 = get(0, 0, n - 1, 0);
		int try2 = get(0, 0, n - 1, (n - a[i]) % n);


		if(try1 == -1)
		{
			c[i] = (a[i] + try2) % n;
			ch(0, 0, n - 1, try2, -1);
		}
		else if(try2 == -1)
		{
			c[i] = (a[i] + try1) % n;
			ch(0, 0, n - 1, try1, -1);
		}
		else
		{
			int value1 = (a[i] + try1) % n;
			int value2 = (a[i] + try2) % n;

			if(value1 < value2)
			{
				c[i] = (a[i] + try1) % n;
				ch(0, 0, n - 1, try1, -1);
			}
			else
			{
				c[i] = (a[i] + try2) % n;
				ch(0, 0, n - 1, try2, -1);
			}
		}
	}

	cout << c << endl;
}

int main()
{
	fast_io();
	solve();

	return 0;
}