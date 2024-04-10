#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;

    vector<int> k(m);
    for (int i = 0; i < m; i++)
        cin >> k[i];

    int ans = 1e9;

    vector<int> cnt(m);
    int fine = 0;
    for (int i = 0; i < m; i++)
        if (k[i] == 0) fine++;
    for (int L = 0, R = 0; L < n; L++)
    {
        while (R < n && fine != m)
        {
            cnt[a[R]]++;
            if (cnt[a[R]] == k[a[R]])
                fine++;
            R++;
        }
        if (fine == m)
            ans = min(ans, R - L);
        cnt[a[L]]--;
        if (cnt[a[L]] == k[a[L]] - 1)
            fine--;
    }

    if (ans == 1e9)
        cout << -1 << "\n";
    else
        cout << ans - accumulate(k.begin(), k.end(), 0) << "\n";
}