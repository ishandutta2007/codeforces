#include <iostream>

using namespace std;

signed main()
{
    long long n, ans = 0;
    long long a[200000];
    long long cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0 && a[i] != a[i - 1])
        {
            ans = ans + cnt * (cnt - 1) / 2;
            cnt = 0;
        }
        cnt++;
    }
    ans = ans + cnt * (cnt - 1) / 2;
    cout << ans + n;
}