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
        vector<ll> c(n);
        for(int i = 0; i < n; i++)
        {
            cin >> c[i];
        }
        ll sum1 = 0;
        ll sum2 = 0;
        ll min1 = 1000000000;
        ll min2 = 1000000000;
        ll ans = 100000000000000000ll;
        ll now1 = n;
        ll now2 = n;
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 0)
            {
                min2 = min(min2, c[i]);
                sum2 += c[i];
                --now2;
            }
            else
            {
                min1 = min(min1, c[i]);
                sum1 += c[i];
                --now1;
            }
            if(i == 0)
            {
                continue;
            }
            ll ans1 = (sum1 - min1) + min1 * (now1 + 1);
            ans1 += (sum2 - min2) + min2 * (now2 + 1);
            ans = min(ans, ans1);
        }
        cout << ans << '\n';
    }
}