#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 2e3 + 239;

int n, x[M], y[M];
bool used[M];
string s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];
    cin >> s;
    s += 'L';
    int id = -1;
    for (int i = 0; i < n; i++)
        if (id == -1 || x[id] > x[i] || (x[id] == x[i] && y[id] > y[i]))
            id = i;
    used[id] = true;
    cout << (id + 1) << " ";
    for (int it = 1; it < n; it++)
    {
        int to = -1;
        for (int i = 0; i < n; i++)
            if (!used[i])
            {
                if (to == -1)
                    to = i;
                else
                {
                    ll now = (ll)(x[i] - x[id]) * (ll)(y[to] - y[id]) - (ll)(y[i] - y[id]) * (ll)(x[to] - x[id]);
                    if (s[it - 1] == 'R') now = -now;
                    if (now > 0) to = i;
                }
            }
        used[to] = true;
        id = to;
        cout << (id + 1) << " ";
    }
    return 0;
}