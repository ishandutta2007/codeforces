#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> res(n + 1);
    vector<int> g0, g1;
    for (int i = 1; i <= n; i += 3)
    {
        cout << "? " << i << " " << i + 1 << " " << i + 2 << endl;
        int x;
        cin >> x;
        if (x) g1.push_back(i);
        else g0.push_back(i);
    }
    cout << "? " << g0[0] + 1 << " " << g0[0] + 2 << " " << g1[0] << endl;
    int r;
    cin >> r;
    cout << "? " << g0[0] + 2 << " " << g1[0] << " " << g1[0] + 1 << endl;
    int s;
    cin >> s;
    int a, b;
    if (0 != r)
    {
        a = g0[0], b = g1[0];
    }
    else if (r != s)
    {
        a = g0[0] + 1, b = g1[0] + 1;
    }
    else if (s != 1)
    {
        a = g0[0] + 2, b = g1[0] + 2;
    }
    res[a] = 1;

    for (int i = 1; i < g0.size(); i++)
    {
        cout << "? " << g0[i] << " " << g0[i] + 1 << " " << b << endl;
        int x;
        cin >> x;
        if (x == 0)
        {
            cout << "? " << a << " " << g0[i] + 2 << " " << b << endl;
            int y;
            cin >> y;
            if (y == 0) res[g0[i] + 2] = 1;
            res[g0[i] + 1] = res[g0[i]] = 1;
        }
        else
        {
            cout << "? " << a << " " << g0[i] + 1 << " " << b << endl;
            int y;
            cin >> y;
            res[g0[i] + 2] = 1;
            if (y == 0) res[g0[i] + 1] = 1;
            else res[g0[i]] = 1;
        }
    }

    for (int i = 1; i < g1.size(); i++)
    {
        cout << "? " << g1[i] << " " << g1[i] + 1 << " " << a << endl;
        int x;
        cin >> x;
        if (x == 1)
        {
            cout << "? " << a << " " << g1[i] + 2 << " " << b << endl;
            int y;
            cin >> y;
            if (y == 0) res[g1[i] + 2] = 1;
        }
        else
        {
            cout << "? " << a << " " << g1[i] + 1 << " " << b << endl;
            int y;
            cin >> y;
            if (y == 0) res[g1[i] + 1] = 1;
            else res[g1[i]] = 1;
        }
    }
    set<int> S;
    for (int k = 0; k < 3; k++) S.insert(g0[0] + k);
    for (int k = 0; k < 3; k++) S.insert(g1[0] + k);
    S.erase(a);
    S.erase(b);
    for (auto e : S)
    {
        cout << "? " << a << " " << e << " " << b << endl;
        int y;
        cin >> y;
        if (y == 0) res[e] = 1;
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) if (res[i]) ans.push_back(i);

    cout << "! " << ans.size() << " ";
    for (auto e : ans) cout << e << " "; cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //cout << "\n";

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}