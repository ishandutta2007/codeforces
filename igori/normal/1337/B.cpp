#include <iostream>

using namespace std;

const int N = 200;

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, n, m;
        cin >> x >> n >> m;
        while (n-- && (x / 2) + 10 < x)
        {
            x = (x / 2) + 10;
        }
        if (x <= 10 * m)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}