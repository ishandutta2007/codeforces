#include <bits/stdc++.h>

using namespace std;

const int M = 5e5 + 239;

int n, a[M], p[M], timer;
vector<int> v[M];
vector<int> q;

void dfs(int t)
{
    p[t] = timer--;
    for (int i : v[t])
        dfs(i);
}

void solve()
{
    cin >> n;
    for (int i = 0; i <= n; i++) v[i].clear();
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        if (a[i] == -2) a[i] = i + 1;
        v[a[i]].push_back(i);
    }
    timer = n;
    dfs(n);
    q.clear();
    for (int i = n - 1; i >= 0; i--)
    {
        while (!q.empty() && p[q.back()] < p[i])
            q.pop_back();
        if ((q.empty() && a[i] != n) || (!q.empty() && q.back() != a[i]))
        {
            cout << "-1\n";
            return;
        }
        q.push_back(i);
    }
    for (int i = 0; i < n; i++)
        cout << p[i] + 1 << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}