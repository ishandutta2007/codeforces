#include <bits/stdc++.h>
using namespace std;
 
long long n, k;
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    long long m = (n - k) / 2;
    if (k == 1)
    {
        m = n - 1;
    }
    for (int i = 0; i < n; i++)
    {
        cout << (i % (m + 1) > 0);
    }
}