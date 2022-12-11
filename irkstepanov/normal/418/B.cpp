#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
ll inf = 2000000000000000000;

int n, m;
ll b;

struct man
{
    ll x, k;
    int p;
};

bool comp (man a, man b)
{
    return a.k < b.k;
}

int main()
{

    cin >> n >> m;
    cin >> b;

    man a[120];

    for (int i = 0; i < n; i++)
    {
        int z;
        cin >> a[i].x >> a[i].k >> z;
        a[i].p = 0;
        while (z--)
        {
            int r;
            cin >> r;
            --r;
            a[i].p += (1 << r);
        }
    }

    sort(a, a + n, comp);

    ll ans = inf;
    vector <ll> f (1 << m);

    f[0] = 0;
    for (int j = 1; j < (1 << m); j++)
        f[j] = inf;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (1 << m); j++)
            if (f[j] != inf) f[j | a[i].p] = min(f[j | a[i].p], a[i].x + f[j]);
        if (f[(1 << m) - 1] != inf) ans = min(ans, f[(1 << m) - 1] + a[i].k * b);
    }

    if (ans != inf) cout << ans;
    else cout << "-1";

}