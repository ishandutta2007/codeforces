#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
ll mod = 1000000007;
ll inf = 1000000000;

int main()
{

    int n, m;

    cin >> n >> m;
    vector <ll> a(n + 1), b(m + 1);
    vector <ll> suma(n + 1), sumb(m + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];

    a[0] = b[0] = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    suma[0] = sumb[0] = 0;
    for (int i = 1; i <= n; i++)
        suma[i] = suma[i - 1] + a[i];
    for (int i = 1; i <= m; i++)
        sumb[i] = sumb[i - 1] + b[i];

    vector <ll> poss;
    for (int i = 1; i <= n; i++)
        poss.pb(a[i]);
    for (int i = 1; i <= m; i++)
        poss.pb(b[i]);

    sort(poss.begin(), poss.end());

    int uka = 1, ukb = 1;
    ll ans = inf * inf;
    for (int i = 0; i < poss.size(); i++)
    {
        while (uka <= n && a[uka] < poss[i])
            ++uka;
        while (ukb <= m && b[ukb] < poss[i])
            ++ukb;
        ll otv = 0;
        if (uka == n + 1) otv += n * poss[i] - suma[n];
        else otv += (uka - 1) * poss[i] - suma[uka - 1];
        if (ukb == m + 1) otv += 0;
        else otv += sumb[m] - sumb[ukb - 1] - (m - ukb + 1) * poss[i];
        ans = min(ans, otv);
        //cout << poss[i] << " " << ans << "\n";
    }

    cout << ans;

}