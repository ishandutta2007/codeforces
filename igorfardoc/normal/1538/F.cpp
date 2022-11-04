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
        int l, r;
        cin >> l >> r;
        ll ans = 0;
        while(r > 0 || l > 0)
        {
            ans += r - l;
            r /= 10;
            l /= 10;
        }
        cout << ans << '\n';
    }
}