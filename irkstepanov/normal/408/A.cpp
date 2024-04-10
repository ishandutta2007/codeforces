#include <iostream>

using namespace std;

typedef long long ll;

int main()
{


    ll n;
    ll k[120];
    ll m[120][120];
    ll ans[120];
    int i, j;

    cin >> n;
    for (i = 1; i <= n; i++)
        cin >> k[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= k[i]; j++)
        cin >> m[i][j];

    for (i = 1; i <= n; i++)
    {
        ans[i] = 0;
        for (j = 1; j <= k[i]; j++)
            ans[i] += m[i][j] * 5, ans[i] += 15;
    }

    ll otv = 999999999999999;

    for (i = 1; i <= n; i++)
        otv = min(otv, ans[i]);

    cout << otv;

}