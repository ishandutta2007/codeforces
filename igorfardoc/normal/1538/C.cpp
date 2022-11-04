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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            int am = upper_bound(a.begin(), a.end(), r - a[i]) - lower_bound(a.begin(), a.end(), l - a[i]);
            if(a[i] * 2 >= l && a[i] * 2 <= r)
            {
                --am;
            }
            ans += am;
        }
        cout << ans / 2 << '\n';
    }
}