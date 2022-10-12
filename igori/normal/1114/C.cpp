#pragma GCC optimize("O2")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <time.h>
#include <iomanip>
#include <bitset>

using namespace std;
typedef long long ll;
ll x, y, z, b;

vector<ll> p;
vector<ll> c;

ll get(ll x, ll b)
{
    ll z = 0;
    while (x > 0)
    {
        z += x / b;
        x /= b;
    }
    return z;
}

signed main()
{
    cin >> x >> b;
    for (int i = 2; i <= 1000000; i++)
    {
        int cnt = 0;
        while (b % i == 0)
        {
            cnt++;
            b /= i;
        }
        if (cnt > 0)
        {
            p.push_back(i);
            c.push_back(cnt);
        }
    }
    if (b > 1)
    {
        p.push_back(b);
        c.push_back(1);
    }
    ll ans = 1e18;
    for (int i = 0; i < p.size(); i++)
    {
        ll g = get(x, p[i]);
        ans = min(ans, g / c[i]);
    }
    cout << ans;
}