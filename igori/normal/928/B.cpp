#include <iostream>
typedef long long ll;
ll n, k, arr[1203040], ans[1203040];

ll min(ll a, ll b)
{
    if (a < b)
        return a;
    return b;
}

ll max(ll a, ll b)
{
    if (a > b)
        return a;
    return b;
}

int main()
{
    std :: cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        std :: cin >> arr[i];
        arr[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        ll minis = min(i, k);
        ll maxis = min(k, n - i - 1);
        ll q = minis + maxis + 1;
        if (arr[i] == -1)
        {
            ans[i] = q;
        }
        else
        {
            ll super = ans[arr[i]];
            ll last_readen = min(arr[i] + k, n - 1);
            ll first_this_seans = max(0, i - k);
            ll continik = max(0, last_readen - first_this_seans + 1);
            q = super + q - continik;
            ans[i] = q;
        }
        std :: cout << ans[i] << " ";
    }
}