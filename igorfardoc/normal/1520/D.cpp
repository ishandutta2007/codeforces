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
        vector<int> am(2 * n + 1, 0);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] += n;
            a[i] -= i;
            am[a[i]]++;
        }
        ll ans = 0;
        for(int i = 0; i <= 2 * n; i++)
        {
            ans += (ll)am[i] * (am[i] - 1) / 2;
        }
        cout << ans << '\n';
    }
}