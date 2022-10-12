const int MOD = 1e9 + 7;

#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 1; i < n; i++)
    {
        cout << "XOR " << 1 << " " << i + 1 << endl;
        cin >> c[i];
    }

    vector<vector<int> > pos(n);
    for (int i = 1; i < n; i++)
    {
        if (c[i] == 0)
        {
            cout << "AND " << 1 << " " << i + 1 << endl;
            cin >> c[0];
            cout << "! " << c[0] << " ";
            for (int i = 1; i < n; i++) cout << (c[0] ^ c[i]) << " "; cout << endl;
            return 0;
        }
        pos[c[i]].push_back(i);
    }
    for (int i = 1; i < n; i++)
    {
        if (pos[i].size() >= 2)
        {
            cout << "AND " << pos[i][0] + 1 << " " << pos[i][1] + 1 << endl;
            int x;
            cin >> x;
            c[0] = x ^ c[pos[i][0]];
            cout << "! " << c[0] << " ";
            for (int i = 1; i < n; i++) cout << (c[0] ^ c[i]) << " "; cout << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (pos[i].size() && pos[n - 1 - i].size())
        {
            int v = pos[i][0];
            int u = pos[n - 1 - i][0];
            cout << "AND " << 1 << " " << v + 1 << endl;
            cout << "AND " << 1 << " " << u + 1 << endl;
            int v0, u0;
            cin >> v0 >> u0;
            c[0] = v0 | u0;
            cout << "! " << c[0] << " ";
            for (int i = 1; i < n; i++) cout << (c[0] ^ c[i]) << " "; cout << endl;
            return 0;
        }
    }
}