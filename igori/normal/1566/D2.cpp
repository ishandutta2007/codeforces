#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    for (int i = 0; i < n * m; i++)
        cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());
    vector<int> took(n * m);

    int ans = 0;
    for (int i = 0; i < n * m; i++)
    {
        int t = 0;
        for (int r = 0; !t && r < n; r++)
        {
            if (a[i] <= b[r * m + m - 1])
            {
                for (int io = r * m + m - 1; io >= r * m; io--)
                {
                    if (took[io] == 0 && b[io] == a[i])
                    {
                        for (int o = r * m; o < io; o++)
                            if (took[o]) ans++;
                        took[io] = 1;
                        t = 1;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cout << "\n";

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}