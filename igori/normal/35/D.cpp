#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>

typedef long long ll;

using namespace std;

#define all(x) x.begin(), x.end()

const ll INF = 1e9;

ll n, x;
ll a[5000];
ll c[5000];

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        c[i] = a[i] * (n - i);
    }
    sort(c, c + n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (x - c[i] >= 0)
        {
            ans++;
            x -= c[i];
        }
    }
    cout << ans;
}