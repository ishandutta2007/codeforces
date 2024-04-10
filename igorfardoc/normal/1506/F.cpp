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
        vector<pair<int, int> > a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].first;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> a[i].second;
        }
        sort(a.begin(), a.end());
        if(a[0].first != 1 || a[0].second != 1)
        {
            a.push_back({1, 1});
            ++n;
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = 0; i < n - 1; i++)
        {
            int r1 = a[i].first;
            int r2 = a[i + 1].first;
            int c1 = a[i].second;
            int c2 = a[i + 1].second;
            int dr = r2 - r1;
            int dc = c2 - c1;
            if(dr == dc)
            {
                if((r1 + c1) % 2 == 0)
                {
                    ans += dr;
                }
                continue;
            }
            dr -= dc;
            if((r1 + c1) % 2 == 0)
            {
                --dr;
            }
            if(dr > 0)
            {
                ans += (dr - 1) / 2 + 1;
            }
        }
        cout << ans << '\n';
    }
}