#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>

using namespace std;
int n, a[5000], ans;
signed main()
{
    cin >> n;
    for (int i= 0; i< n; i++)
    cin >> a[i];
    ans = 600000;
    int e = 0;
    for (int t = 1; t <= 1000; t++)
    {
        int v = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == t)
            continue;
            if (a[i] > t)
            v += a[i] - t - 1;
            else
            v += t - a[i] - 1;
        }
        if (ans > v)
        e = t;
        ans = min(ans, v);
    }
    cout << e << " " << ans;
}