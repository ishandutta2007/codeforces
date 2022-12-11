#include <iostream>

using namespace std;

typedef long long ll;

int main()
{

    int n, m;
    ll a[120];
    int met[120];
    int b;
    int i, j;

    cin >> n >> m;
    for (i = 1; i <= n; i++)
        cin >> a[i], met[i] = 0;

    for (j = 1; j <= m; j++)
        cin >> b, met[b] = 1;

    ll ans = 0;
    for (i = 1; i <= n; i++)
        if (met[i] == 0) {ans += a[i]; met[i] = 2;}

    for (j = 1; j <= m; j++)
    {
        ll amax = -1, nmin;
        for (i = 1; i <= n; i++)
        if (met[i] == 1 && a[i] > amax) {amax = a[i]; nmin = i;}
        if (ans <= amax) ans += amax;
        else ans *= 2;
        met[nmin] = 2;
    }

    cout << ans;

}