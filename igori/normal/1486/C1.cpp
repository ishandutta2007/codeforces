#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    cout << "? 1 " << n << endl;
    int p;
    cin >> p;
    int x;
    if (p != 1)
    {
        cout << "? 1 " << p << endl;
        cin >> x;
    }
    else
    {
        x = -1;
    }
    if (x == p)
    {
        int L = 1, R = p;
        while (L + 1 < R)
        {
            int M = (L + R) / 2;
            cout << "? " << M << " " << p << endl;
            int x;
            cin >> x;
            if (x == p) L = M;
            else R = M;
        }
        cout << "! " << L << endl;
    }
    else
    {
        int L = p, R = n;
        while (L + 1 < R)
        {
            int M = (L + R) / 2;
            cout << "? " << p << " " << M << endl;
            int x;
            cin >> x;
            if (x == p) R = M;
            else L = M;
        }
        cout << "! " << R << endl;
    }
}