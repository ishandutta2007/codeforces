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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<ll> pref(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        pref[0] = a[0];
        for(int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + a[i];
        }
        vector<pair<ll, int> > good;
        good.push_back({pref[0], 0});
        ll max1 = pref[0];
        for(int i = 1; i < n; i++)
        {
            if(pref[i] > good[good.size() - 1].first)
            {
                good.push_back({pref[i], i});
                max1 = pref[i];
            }
        }
        ll adding = pref[n - 1];
        for(int o = 0; o < m; o++)
        {
             int x;
             cin >> x;
             ll amount = 0;
             if(adding > 0)
             {
                int l = -1;
                int r = x;
                while(r - l > 1)
                {
                    int mid = ((ll)l + r) / 2;
                    if(adding >= x || (ll)mid * adding + max1 >= x)
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid;
                    }
                }
                amount = r;
             }
             int l = -1;
             int r = good.size();
             while(r - l > 1)
             {
                int mid = (l + r) / 2;
                if((ll)amount * adding + good[mid].first >= x)
                {
                    r = mid;
                }   
                else
                {
                    l = mid;
                }
             }
             if(r == good.size())
             {
                cout << "-1 ";
             }
             else
             {
                cout << (ll)amount * n + good[r].second << ' ';
             }
        }
        cout << '\n';
    }
}