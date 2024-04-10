#include <iostream>

using namespace std;

const int N = 200;

int n;
int a[N], b[N];
int ans[N];
int diff[N];

int fnd(int x)
{
    for (int i = 0; i < n + 5; i++)
    {
        if (diff[i] == x)
        {
            return i;
        }
    }
}

signed main()
{
    cin >> n;
    cin >> a[0] >> b[0];
    for (int i = 1; i <= n - 1; i++)
    {
        cout << "+ " << i << endl;
        cin >> a[i] >> b[i];
    }
    cout << "+ " << 1 << endl;
    cin >> a[n] >> b[n];
    for (int i = 1; i < n + 5; i++)
    {
        diff[i] = i * (i - 1) * (i - 2) / 6 - (i - 1) * (i - 2) * (i - 3) / 6;
    }
    ans[1] = fnd(a[n] - a[n - 1]);
    if (ans[1] == 0) ans[1] = 2;
    for (int i = 2; i <= n - 1; i++)
    {
        ans[i] = fnd(a[i] - a[i - 1]);
    }
    int mul = b[n] - b[n - 1];
    if (mul == 2)
    {
        if (b[2] == b[1])
        {
            ans[2] = 2, ans[3] = 1;
        }
        else
        {
            ans[2] = 1, ans[3] = 2;
        }
    }
    if (mul == 1)
    {
        ans[2] = 1;
        ans[3] = 1;
    }
    if (mul == 4)
    {
        if (ans[2] == 0 && ans[3] == 0)
        {
            ans[2] = 2, ans[3] = 2;
        }
        else
        {
            if (ans[2] == 4) ans[3] = 1;
            if (ans[3] == 4) ans[2] = 1;
        }
    }
    if (ans[2] == 0) ans[2] = mul / ans[3];
    if (ans[3] == 0) ans[3] = mul / ans[2];
    for (int i = 4; i <= n - 1; i++)
    {
        if (ans[i] == 0)
        {
            if (b[i - 1] - b[i - 2] == ans[i - 2] * (i - 3 > 1 ? ans[i - 3] : ans[i - 3] - 1))
            {
                ans[i] = 1;
            }
            else
            {
                ans[i] = 2;
            }
        }
    }
    int cur = 0;
    for (int i = 1; i + 2 <= n - 1; i++)
    {
        cur = cur + ans[i] * ans[i + 1] * ans[i + 2];
    }
    cur = b[n] - cur;
    int d = ans[n - 2] * ans[n - 1];
    ans[n] = cur / d;
    cout << "! " << ans[1] - 2 << " ";
    for (int i = 2; i <= n - 1; i++)
    {
        cout << ans[i] - 1 << " ";
    }
    cout << ans[n] << endl;
}