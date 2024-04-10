#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int mn = 1e9, id = 0;
        for (int i = 0; i < n; i++)
        {
            int y = a[i];
            int deg = 0;
            while (y % x == 0)
            {
                y /= x;
                deg++;
            }
            if (deg < mn)
            {
                mn = deg;
                id = i;
            }
        }
        long long ans = accumulate(a.begin(), a.end(), 0LL) * (mn + 1);
        for (int i = 0; i < id; i++) ans += a[i];
        cout << ans << "\n";
    }
}