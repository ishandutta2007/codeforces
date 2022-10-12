#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        if (b == 0)
        {
            cout << a << "\n";
            continue;
        }
        for (long long x = b / 4 * 4 + 1; x <= b; x++)
        {
            if (a % 2 == 0) a -= x;
            else a += x;
        }
        cout << a << "\n";
    }
}