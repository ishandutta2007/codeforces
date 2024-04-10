#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

ll n, need, x, y;

inline ll calc(ll t, ll x, ll y)
{
    if (x < y) swap(x, y);
    if (t <= y) return (t * (t + 1) / 2);
    if (t >= x + y - 1) return x * y;
    if (t <= x) return (y * (y + 1) / 2 + y * (t - y));
    t = x + y - 1 - t;
    return x * y - (t * (t + 1) / 2);
}

inline ll kv(ll t)
{
    return 1 + min(t, x - 1) + min(t, n - x) + min(t, y - 1) + min(t, n - y) +
        calc(t - 1, x - 1, y - 1) + calc(t - 1, n - x, y - 1) + calc(t - 1, x - 1, n - y) + calc(t - 1, n - x, n - y);
}

int main()
{
    scanf(LLD LLD LLD LLD, &n, &x, &y, &need);
    if (need <= 1)
    {
        printf("0\n");
        return 0;
    }
    int kv1 = 1;
    if (x > 1) kv1++;
    if (x < n) kv1++;
    if (y > 1) kv1++;
    if (y < n) kv1++;
    if (kv1 >= need)
    {
        printf("1\n");
        return 0;
    }
    ll l = 1;
    ll r = 2 * n + 5;
    while (r - l > 1)
    {
        ll m = (l + r) / 2;
//         cout << m << ' ' << kv(m) << endl;
        if (kv(m) >= need) r = m;
        else l = m;
    }
    cout << r << endl;
	return 0;
}