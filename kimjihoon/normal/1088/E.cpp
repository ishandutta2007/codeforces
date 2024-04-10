#include <iostream>
#include <vector>
using namespace std;

long long a[300009], d[300009];
vector<int> v[300009];
int vc[300009];

long long dfs(int n, int p)
{
    d[n] = a[n];
    for (int i = 0; i < v[n].size(); i++) {
        if (v[n][i] == p) continue;
        long long t = dfs(v[n][i], n);
        if (t > 0)
            d[n] += t;
    }
    return d[n];
}

void dfs1(int n, int p)
{
    for (int i = 0; i < v[n].size(); i++) {
        if (v[n][i] == p) continue;
        dfs1(v[n][i], n);
        if (d[v[n][i]] > 0 && vc[v[n][i]])
            vc[n] = 2;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b); v[b].push_back(a);
    }
    dfs(1, -1);
    long long mx = d[1];
    for (int i = 1; i <= n; i++)
        if (mx < d[i])
            mx = d[i];
    for (int i = 1; i <= n; i++)
        if (mx == d[i])
            vc[i] = 1;
    dfs1(1, -1);
    long long k = 0;
    for (int i = 1; i <= n; i++)
        if (mx == d[i] && vc[i] != 2)
            k++;
    cout << mx * k << " " << k <<'\n';
    return 0;
}