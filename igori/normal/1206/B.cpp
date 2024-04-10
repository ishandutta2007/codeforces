#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define int long long
using namespace std;

#define fi first
#define se second

const long long MOD = 998244353;
long long a[500000];
long long n, ans;

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] < -1)
        {
            ans += abs(-1 - a[i]);
            a[i] = -1;
        }
        if (a[i] > 1)
        {
            ans += abs(1 - a[i]);
            a[i] = 1;
        }
    }
    int cntmin = 0, cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0) cntmin++;
        if (a[i] == 0) cnt0++;
        if (a[i] > 0) cnt1++;
    }
    if (cntmin % 2 == 0)
    {
        cout << ans + cnt0;
    }
    else
    {
        if (cnt0)
        {
            cout << ans + 1 + cnt0 - 1;
        }
        else
        {
            cout << ans + 2;
        }
    }
}