#include <bits/stdc++.h>
 
#define INT_INF (2 * 1e9)
#define LL_INF  (2LL * 1e18)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef __LOCAL
#define DBG(X) cout << #X << "=" << (X) << endl;
#else
#define DBG(X)
#endif
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9 + 7;
const int MAX_N = 100100;

int segtree[4 * MAX_N], n;

void segtree_inc(int v, int tl, int tr, int i)
{
	if(tl == tr)
	{
		++segtree[v];
	}
	else
	{
		int tm = (tl + tr) / 2;

		if(i <= tm)
			segtree_inc(2 * v + 1, tl, tm, i);
		else
			segtree_inc(2 * v + 2, tm + 1, tr, i);

		segtree[v] = min(segtree[2 * v + 1], segtree[2 * v + 2]);
	}
}

void solve()
{
	int m, a, c = 0;
	string answer;

	cin >> n >> m;

	for(int i = 0; i < m; ++i)
	{
		cin >> a;
		segtree_inc(0, 1, n, a);
		DBG(segtree[0]);

		if(segtree[0] == c + 1)
		{
			answer += "1";
			++c;
		}
		else
		{
			answer += "0";
		}
	}

	cout << answer << endl;
}

int main(int argc, char** argv)
{
	FAST_IO;
	solve();

	return 0;
}