#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        ans += (n / 3) * m;
        n %= 3;
        ans += (m / 3) * n;
        m %= 3;
        if (m >= 1 && n >= 1)
            ans++;
        if (m == 2 && n == 2)
            ans++;
        cout << ans << "\n";
    }
}