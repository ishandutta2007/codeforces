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
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        vector<ll> b(n, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            ll need = max(0ll, a[i] - b[i] - 1);
            ans += need;
            ll can = need + b[i];
            for(int j = i + 2; j < min((ll)n, a[i] + i + 1); j++)
            {
                b[j] += 1;
            }
            can -= a[i] - 1;
            if(i != n - 1)
            {
                b[i + 1] += can;
            }
        }
        cout << ans << '\n';
    }
}