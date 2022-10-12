#include <iostream>
#include <algorithm>

using namespace std;
int n;
long long a[500000], ans;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long t = a[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        ans += t;
        t--;
        t = max(t, 0LL);
        if (i > 0)
           t = min(t, a[i - 1]);
    }
    cout << ans;
}