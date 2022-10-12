#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    while (q--)
    {
        int l, r, t = 0;
        cin >> l >> r;
        l--, r--;
        for (int th = 0; th < n; th++)
        {
            int p = l, le = 0, ri = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == th) continue;
                if (p <= r && s[j] == s[p])
                {
                    if (j < th) le++;
                    else ri++;
                    p++;
                }
            }
            if (p > r && le && ri)
                t = 1;
        }
        for (int th = 0; th < n; th++)
        {
            int p = r, le = 0, ri = 0;
            for (int j = n - 1; j >= 0; j--)
            {
                if (j == th) continue;
                if (p >= l && s[j] == s[p])
                {
                    if (j < th) le++;
                    else ri++;
                    p++;
                }
            }
            if (p < l && le && ri)
                t = 1;
        }
        if (t) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}