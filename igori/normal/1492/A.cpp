#include <bits/stdc++.h>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        long long p, a, b, c, x, y, z;
        cin >> p >> a >> b >> c;
        x = (p + a - 1) / a * a;
        y = (p + b - 1) / b * b;
        z = (p + c - 1) / c * c;
        cout << min({x - p, y - p, z - p}) << "\n";
    }
}