#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    s = "0" + s + "0";
    n += 2;
    vector<int> pr(n), prmx(n), prmn(n);
    vector<int> su(n), sumx(n), sumn(n);
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '+')
        {
            pr[i] = pr[i - 1] + 1;
        }
        if (s[i] == '-')
        {
            pr[i] = pr[i - 1] - 1;
        }
        prmx[i] = max(prmx[i - 1], pr[i]);
        prmn[i] = min(prmn[i - 1], pr[i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '+')
        {
            su[i] = su[i + 1] + 1;
        }
        if (s[i] == '-')
        {
            su[i] = su[i + 1] - 1;
        }
        sumx[i] = max(sumx[i + 1], su[i]);
        sumn[i] = min(sumn[i + 1], su[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        int res = pr[l - 1] + su[r + 1];
        //cout << res << "\n";
        //cout << prmn[l - 1] << " " << prmx[l - 1] << "\n";
        //cout << res - sumx[r + 1] << " " << res - sumn[r + 1] << "\n";
        int l1 = prmn[l - 1], r1 = prmx[l - 1];
        int l2 = res - sumx[r + 1], r2 = res - sumn[r + 1];
        cout << max(r2, r1) - min(l2, l1) + 1 << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    srand(time(NULL));
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}