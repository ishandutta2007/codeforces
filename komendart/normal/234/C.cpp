#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    vector<int> pr(n, 0);
    vector<int> su(n, 0);
    if (a[0] >= 0)
    {
        pr[0] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        pr[i] = pr[i - 1];
        if (a[i] >= 0)
        {
            pr[i] += 1;
        }
    }
    if (a[n - 1] <= 0)
    {
        su[n - 1] = 1;
    }
    for (int i = n - 2; i > -1; --i)
    {
        su[i] = su[i + 1];
        if (a[i] <= 0)
        {
            su[i] += 1;
        }
    }
    int mi = n + 1;
    for (int i = 1; i < n; ++i)
    {
        mi = min(mi, pr[i - 1] + su[i]);
    }
    cout << mi << endl;
    return 0;
}