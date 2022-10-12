#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int a[500000], b[500000];
int ans[500000];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    ans[1] = 1;
    ans[2] = a[1];
    ans[3] = b[1];
    int t = 1;
    for (int i = 4; i <= n; i++)
    {
        ans[i] = a[ans[i - 2]] + b[ans[i - 2]] - ans[i - 1];
        if (ans[i] != a[ans[i - 1]] && ans[i] != b[ans[i - 1]])
            t = 0;
        if (ans[i] != a[ans[i - 2]] && ans[i] != b[ans[i - 2]])
            t = 0;
    }
    if (t) {
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        return 0;
    }
    ans[1] = 1;
    ans[2] = b[1];
    ans[3] = a[1];
    t = 1;
    for (int i = 4; i <= n; i++)
    {
        ans[i] = a[ans[i - 2]] + b[ans[i - 2]] - ans[i - 1];
        if (ans[i] != a[ans[i - 1]] && ans[i] != b[ans[i - 1]])
            t = 0;
        if (ans[i] != a[ans[i - 2]] && ans[i] != b[ans[i - 2]])
            t = 0;
    }
    if (t) {
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        return 0;
    }
}