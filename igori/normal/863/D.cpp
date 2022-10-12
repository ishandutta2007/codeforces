#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n, q, m;
    cin >> n >> q >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> t(q), l(q), r(q);
    for (int i = 0; i < q; i++) cin >> t[i] >> l[i] >> r[i];
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        for (int j = q - 1; j >= 0; j--)
        {
            if (l[j] <= b && b <= r[j])
            {
                if (t[j] == 2) b = r[j] + l[j] - b;
                else b = b != l[j] ? b - 1 : r[j];
            }
        }
        cout << a[b - 1] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
}