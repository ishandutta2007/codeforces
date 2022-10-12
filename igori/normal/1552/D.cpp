#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()

void solve(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        vector<int> b;
        for (int j = 0; j < a.size(); j++) if (j != i) b.push_back(a[j]);
        for (int mask = 0; mask < (1 << b.size()); mask++)
        {
            for (int sub = mask; ; sub = (sub - 1) & mask)
            {
                int res = 0;
                for (int j = 0; j < b.size(); j++)
                {
                    if (mask & (1 << j))
                    {
                        if (sub & (1 << j))
                            res += b[j];
                        else
                            res -= b[j];
                    }
                }
                if (res == a[i])
                {
                    cout << "YES\n";
                    return;
                }
                if (sub == 0)
                    break;
            }
        }
    }
    cout << "NO\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i], a[i] = abs(a[i]);
        solve(a);
    }
}