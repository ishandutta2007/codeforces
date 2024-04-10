#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    if (n == 1)
    {
        cout << 0 << "\n";
        cout << 1 << "\n";
        cout << 0 << "\n";
        return;
    }

    long long ans = 0;
    long long cnt = 1, st = n - 1, asz = 0;
    while (asz < n - 1)
    {
        if (cnt == 0)
        {
            cnt = 2;
            st--;
        }
        ans += st * st;
        cnt--;
        asz++;
    }
    cout << ans << "\n";

    vector<int> p;
    vector<int> opi, opj;

    {
        p.push_back(n / 2 + 1);
        for (int i = 1; i < n / 2; i++)
        {
            p.push_back(i);
        }
        for (int i = n / 2 + 2; i <= n; i++)
        {
            p.push_back(i);
        }
        p.push_back(n / 2);
        for (int i = n / 2 + 1; i < n; i++)
        {
            opi.push_back(i);
            opj.push_back(1);
        }
        for (int i = n / 2; i > 1; i--)
        {
            opi.push_back(i);
            opj.push_back(n);
        }
        if (n != 1)
        {
            opi.push_back(1);
            opj.push_back(n);
        }
    }

    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i] << " ";
    }
    cout << "\n";
    cout << opi.size() << "\n";
    for (int j = 0; j < opi.size(); j++)
    {
        cout << opi[j] << " " << opj[j] << "\n";
    }
    cout << "\n";
    return;

    long long tm = 0;
    for (int j = 0; j < opi.size(); j++)
    {
        opi[j]--;
        opj[j]--;
        assert(p[opj[j]] - 1 == opi[j]);
        swap(p[opi[j]], p[opj[j]]);
        tm += 1ll * (opi[j] - opj[j]) * (opi[j] - opj[j]);
    }
    //cout << "True time = " << tm << "\n";
    //cout << "Resulting permutation = ";
    for (int i = 0; i < n; i++)
    {
        ;//cout << p[i] << " ";
    }
    //cout << "\n";

    assert(tm == ans);
    for (int i = 0; i < n; i++)
    {
        assert(p[i] == i + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}