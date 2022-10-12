#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int> > a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first;
        for (int i = 0; i < n; i++) cin >> a[i].second;
        sort(a.begin(), a.end(), [&](pair<int, int> a, pair<int, int> b){
             return a.first + a.second < b.first + b.second;
             });
        int x = 1, y = 1;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x2 = a[i].first, y2 = a[i].second;
            if (x2 - y2 == x - y && (x2 - y2) % 2 == 0)
            {
                ans += abs(x2 - x);
            }
            else
            {
                int d1 = x - y;
                int d2 = x2 - y2;
                ans += d2 / 2 - d1 / 2;
            }
            x = x2, y = y2;
        }
        cout << ans << "\n";
    }
}