#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e6;

int f[N];

void add(int x)
{
    while (x < N)
    {
        f[x]++;
        x |= (x + 1);
    }
}

int get(int x)
{
    int res = 0;
    while (x >= 0)
    {
        res += f[x];
        x &= (x + 1);
        x--;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> p(n);
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        res += get(n) - get(p[i]);
        add(p[i]);
    }
    if (res % 2 == 3 * n % 2) cout << "Petr\n";
    else cout << "Um_nik\n";
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