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
ll n;
ll a[6000];
ll g = 0;

signed main()
{
    srand(time(NULL));
    cin >> n;
    cout << "? 1" << endl;
    cin >> a[0];
    cout << "? 2" << endl;
    cin >> a[1];
    g = abs(a[1] - a[0]);
    for (int i = 2; i < 29; i++)
    {
        int y = (rand() * (1 << 15) + rand()) % n + 1;
        cout << "? " << y << endl;
        cin >> a[i];
        for (int j = 0; j < i; j++)
        {
            g = __gcd(g, abs(a[j] - a[i]));
        }
    }
    ll l = -1, r = 1000000000;
    while (l + 1 < r)
    {
        ll mid = (l + r) / 2;
        cout << "> " << mid << endl;
        int t;
        cin >> t;
        if (t == 0)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << "! " << r - (n - 1) * g << " " << g << endl;
}