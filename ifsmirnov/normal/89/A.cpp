#include <iostream>
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
const int maxn = 100500;
const int inf = 1e9+100500;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
#define se second
#define fi first
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;

ll n, m, k;
int a[maxn];

int main()
{
	ios :: sync_with_stdio(false);
	cin >> n >> m >> k;
	ll mn = inf;
	ll t;
	forn(i, n)
	{
		cin >> t;
		if (i%2 == 0) mn = min(mn, t);
	}
	
	if (n%2 == 0) cout << 0;
	else
	{
		ll cost = n/2+1;
		ll day = m / cost;
		cout << min(day*k, mn);

	}
	
	return 0;
};