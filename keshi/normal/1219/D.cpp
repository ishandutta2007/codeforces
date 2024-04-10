//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

ll a[N], c[N];

multiset < ll > m;

int main()
{
    ll n, p, x;
    cin >> n >> p;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    cin >> x;
    for (int i = 0; i < n; i ++)
        cin >> c[i];
    ll P = p, ans = 0;
    for (int i = 0; i < n; i ++)
    {
        m.insert(c[i]);
        if ((i + 1) * x + p < a[i])
            return cout << -1, 0;
        while (P < a[i])
        {
            ans += *m.begin();
            m.erase(m.begin());
            P += x;
        }
    }
    cout << ans;
    return 0;
}