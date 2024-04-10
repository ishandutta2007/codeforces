#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> mm;
    for (int i = 0; i < n; i++) mm[a[i]]++;
    vector<int> ans = {a[0]};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            ll pos1 = a[i] - (1ll << j);
            ll pos2 = a[i] + (1ll << j);
            vector<int> e = {a[i]};
            if (mm.find(pos1) != mm.end()) e.push_back(pos1);
            if (mm.find(pos2) != mm.end()) e.push_back(pos2);
            if (e.size() > ans.size())
                ans = e;
        }
    }
    cout << ans.size() << "\n";
    for (auto e : ans) cout << e << " ";
    cout << "\n";
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