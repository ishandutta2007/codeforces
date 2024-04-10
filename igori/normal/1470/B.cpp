#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    const int SZ = 1e6 + 228;
    vector<int> gpd(SZ);
    for (int i = 2; i < SZ; i++)
    {
        if (gpd[i] == 0)
        {
            for (int j = i; j < SZ; j += i)
                gpd[j] = i;
        }
    }
    int t;
    cin >> t;
    for (int _ = 0; _ < t; _++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            int x = a[i];
            int r = 1;
            while (x > 1)
            {
                int g = gpd[x];
                if (x % (g * g) == 0)
                {
                    x /= (g * g);
                }
                else
                {
                    x /= g;
                    r *= g;
                }
            }
            a[i] = r;
        }
        sort(a.begin(), a.end());
        int cnt = 0, mx = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            cnt++;
            if (i + 1 == n || a[i + 1] != a[i])
            {
                mx = max(mx, cnt);
                if (cnt % 2 == 0 || a[i] == 1)
                    even += cnt;
                cnt = 0;
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            long long t;
            cin >> t;
            if (t == 0)
            {
                cout << mx << "\n";
            }
            else
            {
                cout << max(mx, even) << "\n";
            }
        }
    }
}