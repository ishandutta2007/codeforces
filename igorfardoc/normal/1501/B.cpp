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
        vector<pair<int, int> > b;
        for(int i = 0; i < n; i++)
        {
            if(a[i] != 0)
            {
                b.push_back({max(0, i - a[i] + 1), i});
            }
        }
        sort(b.begin(), b.end());
        vector<bool> ans(n, false);
        int r = -1;
        for(int i = 0; i < b.size(); i++)
        {
            if(b[i].second <= r)
            {
                continue;
            }
            for(int j = max(r + 1, b[i].first); j <= b[i].second; j++)
            {
                ans[j] = true;
            }
            r = max(r, b[i].second);
        }
        for(int i = 0; i < n; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}