#include <functional>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cassert>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fore(i, b, e) for (int i = (int)(b); i <= (int)(e); i++)
const int maxn = 105;
#define pb push_back
#define mp make_pair
#define se second
#define fi first
typedef long long i64;
typedef pair<i64, i64> pii;


int n;
pii a[maxn];
int t;
i64 p[maxn];

void scan()
{
	cin >> n;
	forn(i, n) cin >> a[i].se >> a[i].fi;
	cin >> t;
	forn(i, t) cin >> p[i];
	p[t] = 1e18;
	
	sort(a, a+n);
}

i64 getp(i64 p)
{
	i64 s = 0;
	forn(i, n)
	{
		if (a[i].se >= p)
		{
			a[i].se -= p;
			s += a[i].fi * p;
			p = 0;
			break;
		}
		else
		{
			s += a[i].fi * a[i].se;
			p -= a[i].se;
			a[i].se = 0;
		}
	}
	if (p != 0)
		return ~s;
	return s;
}
void solve()
{
	i64 res = 0;
	i64 mul = 1;
	forn(i, t + 1)
	{
		i64 s = getp(p[i] - (i ? p[i-1] : 0));
		if (s < 0)
		{
			s = ~s;
			res += s * mul;
			break;
		}
		else
		{
			res += s * mul;
			++mul;
		}
	}
	cout << res << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	
	scan();
	solve();
	
	return 0;
}