#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define all(x) (x).begin(), (x).end()

int check(vector<int> x, vector<int> y)
{
    int res = 0;
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        if (x[i] > y[i])
            swap(x[i], y[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int ch = 0;
            if (x[i] < x[j] && x[j] < y[i]) ch++;
            if (x[i] < y[j] && y[j] < y[i]) ch++;
            if (ch == 1) res++;
        }
    }
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> used(2 * n);
    vector<int> x(k), y(k);
    for (int i = 0; i < k; i++)
    {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        used[x[i]] = used[y[i]] = 1;
    }
    vector<int> q;
    for (int i = 0; i < 2 * n; i++)
        if (!used[i]) q.push_back(i);

    int m = q.size();
    int ans = check(x, y);
    for (int i = 0; i < q.size(); i++)
    {
        for (int j = 0; j < q.size() / 2; j++)
        {
            x.push_back(q[(i + j) % m]);
            y.push_back(q[(i + j + m / 2) % m]);
        }
        ans = max(ans, check(x, y));
        x.resize(k);
        y.resize(k);
    }
    cout << ans << "\n";
}

signed main()
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