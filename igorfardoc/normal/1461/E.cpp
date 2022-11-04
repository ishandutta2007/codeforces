#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    if(y + k <= r)
    {
        k += y;
    }
    if(y < x)
    {
        if(k <= l + x - 1)
        {
            cout << "No";
            return 0;
        }
        ll ans = (k - (l + x - 1) - 1) / (x - y) + 1;
        if(ans >= t)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        return 0;
    }
    if(x + y <= r - l)
    {
        cout << "Yes";
        return 0;
    }
    vector<bool> used(1000002, false);
    while(true)
    {
        ll a1 = (k - l) / x;
        t -= a1;
        if(t <= 0)
        {
            cout << "Yes";
            return 0;
        }
        k -= a1 * x;
        if(used[k - l])
        {
            cout << "Yes";
            return 0;
        }
        used[k - l] = true;
        if(k + y <= r)
        {
            k += y;
        }
        else
        {
            break;
        }
    }
    cout << "No";
}