#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;

ll a[5000], b[5000];
ll pa[5000], pb[5000];
ll ma[5000], mb[5000];

int main() {
    ll n, m, x;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        pa[i + 1] = pa[i] + a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
        pb[j + 1] = pb[j] + b[j];
    }
    cin >> x;
    for (int i = 0; i <= n; i++)
        ma[i] = 999999999;
    for (int j = 0; j <= m; j++)
        mb[j] = 999999999;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            ll res = pa[j] - pa[i];
            ll len = j - i;
            ma[len] = min(ma[len], res);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            ll res = pb[j] - pb[i];
            ll len = j - i;
            mb[len] = min(mb[len], res);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (ma[i] * mb[j] <= x)
            {
                ans = max(ans, (ll)i * j);
            }
        }
    }
    cout << ans;
}