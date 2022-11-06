#include <bits/stdc++.h>

#define pb push_back

using namespace std;
const int maxn = 2 * (int)1e5 + 5;

int d[maxn], c[maxn], z[maxn], n, x, y;
vector <int> a[maxn];

void dfs(int v, int pr)
{
    d[v] = c[v];
    z[v] = c[v];
    for (int i = 0; i < a[v].size(); i++)
    {
        if (a[v][i] == pr)
            continue;
        dfs(a[v][i], v);
        d[v] += d[a[v][i]];
        z[v] += (d[a[v][i]] > 0);
    }
    if (d[v] > 0 && v != 1)
        z[v]++;
    z[v] %= 2;
//    cout << v << " " << d[v] << " " << z[v] << " " << c[v] << endl;
    return;
}
void dfs1(int v, int pr)
{
    c[v] = !c[v];
    cout << v << " ";
    for (int i = 0; i < a[v].size(); i++)
    {
        if (a[v][i] == pr)
            continue;
        if (d[a[v][i]] == 0)
            continue;
        dfs1(a[v][i], v);
        cout << v << " ";
        c[v] = !c[v];
    }
    int k = 0;
    for (int i = 0; i < a[v].size(); i++)
    {
        if (a[v][i] == pr)
            continue;
        if (d[a[v][i]] == 0 || c[a[v][i]] == 0)
            continue;
        cout << a[v][i] << " ";
        cout << v << " ";
        c[v] = !c[v];
        c[a[v][i]] = 0;
    }
    if (v == 1)
    {
        if (c[v])
            cout << a[v][0] << " " << v << " " << a[v][0];
    }
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        if (c[i] == -1)
            c[i] = 1;
        else
            c[i] = 0;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    dfs(1, 0);
    c[1] = !c[1];
    dfs1(1, 0);
    return 0;
}