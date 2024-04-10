#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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

ll n, m, a[500000];
ll s;

int main()
{
    cin >> n >> m;
    m = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
        m = max(a[i], m);
    }
    sort(a, a + n);
    ll have = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= have + 1)
        {
            have++;
            cnt++;
        }
        else
        {
            cnt++;
        }
    }
    cnt += m - have;
    cout << s - cnt;
}