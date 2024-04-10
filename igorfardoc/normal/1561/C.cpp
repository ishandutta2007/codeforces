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
        vector<int> k(n);
        vector<pair<int, int> > mass;
        for(int i = 0; i < n; i++)
        {
            cin >> k[i];
            int here = 0;
            for(int j = 0; j < k[i]; j++)
            {
                int val;
                cin >> val;
                here = max(here, val - j + 1);
            }
            mass.push_back({here, k[i]});
        }
        sort(mass.begin(), mass.end());
        int ans = 0;
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max((ll)ans, mass[i].first - sum);
            sum += mass[i].second;
        }
        cout << ans << '\n';
    }
}