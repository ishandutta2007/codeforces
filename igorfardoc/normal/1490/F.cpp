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
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<int> b;
        sort(a.begin(), a.end());
        for(int i = 0; i < n; i++)
        {
            if(i == 0 || a[i] != a[i - 1])
            {
                b.push_back(1);
            }
            else
            {
                b[b.size() - 1]++;
            }
        }
        sort(b.begin(), b.end());
        n = b.size();
        ll ans = 1000000000000000000ll;
        vector<ll> pref(n + 1);
        pref[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + b[i - 1];
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(i != 0 && b[i - 1] == b[i])
            {
                continue;
            }
            ll here = 0;
            here += pref[i];
            here += pref[n] - pref[i];
            here -= b[i] * (n - i);
            ans = min(ans, here);
        }
        cout << ans << '\n';
    }
}