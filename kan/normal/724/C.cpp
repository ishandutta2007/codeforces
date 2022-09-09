#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using D = double;
using uint = unsigned int;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

int euclid(int a, int b, int &x, int &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	int xx, yy;
	int d = euclid(b, a % b, xx, yy);
	x = yy;
	y = xx - (a / b) * yy;
	return d;
}

int sgn(int x) { return x < 0 ? -1 : (x > 0 ? 1 : 0); }

const ll inf = 1e18;

int n, m, k;
int a, b, d;

ll solve(int x, int y)
{
	int t = y - x;
	if (t % d != 0)
	{
		return inf;
	}
	ll aa = (ll)a * (t / abs(d)) * sgn(d);
	ll bb = (ll)b * (t / abs(d)) * sgn(d);
	ll dd = 2 * m / abs(d);
	if (aa > 0)
	{
		ll k = aa / dd;
		aa -= k * dd;
	} else if (aa < 0)
	{
		ll k = abs(aa) / dd;
		aa += (k - 2) * dd;
		while (aa < 0) aa += dd;
	}
// 	cout << a << ' ' << b << ' ' << d << endl;
// 	cout << x << ' ' << y << ' ' << aa << endl;
	return x + (2 * n) * aa;
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	euclid(2 * n, 2 * m, a, b);
	if (a < 0)
	{
		a = -a;
		b = -b;
	}
	b = -b;
	d = (ll)a * (2 * n) - m * (2 * b);
// 	cout << a << ' ' << b << ' ' << d << endl;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ll ans1 = solve(x, y);
		ll ans2 = solve(2 * n - x, y);
		ll ans3 = solve(2 * n - x, 2 * m - y);
		ll ans4 = solve(x, 2 * m - y);
		ll ans = min(min(ans1, ans2), min(ans3, ans4));
		if (ans == inf)
		{
			printf("-1\n");
			continue;
		} else printf("%lld\n", ans);
	}
    return 0;
}