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
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> b(n, 0);
    for(int i = 1; i < n - 1; i++)
    {
        b[i] = a[i + 1] - a[i - 1] - 2;
    }
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + b[i - 1];
    }
    for(int o = 0; o < q; o++)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        ll ans = 0;
        if(r - l > 1)
        {
            ans += pref[r] - pref[l + 1];
        }
        if(r - l > 0)
        {
            ans += a[l + 1] - 2;
            ans += k - a[r - 1] - 1;
        }
        if(l == r)
        {
            ans += k - 1;
        }
        cout << ans << '\n';
    }
}