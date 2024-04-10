#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b, k;
    cin >> a >> b >> k;

    int n = a + b;
    string x = "1";
    string y = "1";

    if (k == 0)
    {
        cout << "Yes\n" << string(b, '1') << string(a, '0') << "\n" << string(b, '1') << string(a, '0') << "\n";
        return 0;
    }

    if (b == 1)
    {
        if (k > 0)
        {
            cout << "No\n";
            return 0;
        }
        else
        {
            cout << "Yes\n1" << string(a, '0') << "\n1" << string(a, '0') << '\n';
            return 0;
        }
    }

    if (a == 0)
    {
        if (k > 0)
        {
            cout << "No\n";
            return 0;
        }
        else
        {
            cout << "Yes\n" << string(b, '1') << "\n" << string(b, '1') << '\n';
            return 0;
        }
    }

    x += "1";
    y += "0";

    int r0 = a - 1, r1 = b - 2;

    for (int i = 0; i < k - 1; i++)
    {
        if (r0) x += "0", y += "0", r0--;
        else if (r1) x += "1", y += "1", r1--;
        else
        {
            cout << "No\n";
            return 0;
        }
    }

    x += "0";
    y += "1";

    for (int i = 0; r0 + r1 > 0; i++)
    {
        if (r0) x += "0", y += "0", r0--;
        else if (r1) x += "1", y += "1", r1--;
        else
        {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    cout << x << "\n" << y << "\n";
}