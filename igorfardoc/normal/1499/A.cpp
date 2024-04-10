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
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int w, b;
        cin >> w >> b;
        int ans = min(k1, k2);
        ans += (max(k2, k1) - min(k2, k1)) / 2;
        if(ans < w)
        {
            cout << "NO\n";
            continue;
        }
        k1 = n - k1;
        k2 = n - k2;
        ans = min(k1, k2);
        ans += (max(k2, k1) - min(k2, k1)) / 2;
        if(ans < b)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}