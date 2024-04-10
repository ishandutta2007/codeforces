#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    const int N = 400000;
    vector<vector<int> > pos(N), neg(N);
    for (int i = 0; i < n; i++)
    {
        int si = 0, bal = 0;
        for (int j = 0; j < s[i].size(); j++)
        {
            if (s[i][j] == '(') si++;
            else si--;
            bal = min(bal, si);
        }
        if (si >= 0)
            pos[si].push_back(bal);
        else
            neg[-si].push_back(bal);
    }

    ll ans = 0;
    ll c = 0;
    for (int i = 0; i < pos[0].size(); i++) if (pos[0][i] == 0) c++;
    ans += c * c;

    for (int i = 1; i < N; i++)
    {
        ll c1 = 0, c2 = 0;
        for (int j = 0; j < pos[i].size(); j++) if (pos[i][j] == 0) c1++;
        for (int j = 0; j < neg[i].size(); j++) if (neg[i][j] >= -i) c2++;
        ans += c1 * c2;
    }

    cout << ans << "\n";
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