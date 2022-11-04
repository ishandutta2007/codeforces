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
        map<int, vector<int> > d;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            d[a[i]].push_back(i);
        }
        ll ans = 0;
        for(auto & p : d)
        {
            vector<int> a = p.second;
            if(a.size() == 1)
            {
                continue;
            }
            int m = a.size();
            vector<int> b;
            b.push_back(a[0] + 1);
            for(int i = 0; i < m - 1; i++)
            {
                b.push_back(a[i + 1] - a[i]);
            }
            b.push_back(n - a[m - 1]);
            vector<ll> pref1(m + 1), pref2(m + 1);
            pref1[0] = b[0];
            for(int i = 1; i <= m; i++)
            {
                pref1[i] = pref1[i - 1] + b[i];
            }
            pref2[0] = pref1[0];
            for(int i = 1; i <= m; i++)
            {
                pref2[i] = pref2[i - 1] + pref1[i];
            }
            for(int i = 1; i < m; i++)
            {
                ll ans1 = n - a[i];
                ans1 *= pref2[i - 1];
                ans += ans1;
            }
        }
        cout << ans << '\n';
    }
}