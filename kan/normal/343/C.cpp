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

const int maxn = 100005;
const ll inf = 2e10;

ll a[maxn], b[maxn];
int n, m;

inline bool canone(int i, int li, int ri, ll t)
{
    ll wh = a[i];
    ll l = b[li];
    ll r = b[ri];
    return r - l + min(abs(wh - l), abs(wh - r)) <= t;
}

bool can(ll t)
{
    int last = 0;
    for (int i = 0; i < n; i++)
    {
        int prev = last;
        while (last < m && canone(i, prev, last, t)) last++;
        if (last >= m) return true;
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf(LLD, &a[i]);
    for (int i = 0; i < m; i++) scanf(LLD, &b[i]);
    ll l = -1;
    ll r = inf;
    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        if (can(mid)) r = mid;
        else l = mid;
    }
    cout << r << endl;
	return 0;
}