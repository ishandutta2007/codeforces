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
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        vector<int> res;
        vector<ll> pref(n);
        pref[0] = a[0].first;
        for(int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + a[i].first;
        }
        for(int i = n - 1; i >= 0; i--)
        {
            if(i == n - 1)
            {
                res.push_back(a[i].second);
                continue;
            }
            if(pref[i] >= a[i + 1].first)
            {
                res.push_back(a[i].second);
            }
            else
            {
                break;
            }
        }
        sort(res.begin(), res.end());
        cout << res.size() << '\n';
        for(int i = 0; i < res.size(); i++)
        {
            cout << res[i] + 1 << ' ';
        }
        cout << '\n';
    }
}