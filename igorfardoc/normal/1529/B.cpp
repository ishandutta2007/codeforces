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
        sort(a.begin(), a.end());
        int delta = 1000000001;
        int ans = 1;
        for(int i = 0; i < n; i++)
        {
            if(a[i] > 0)
            {
                ans = max(ans, i + (delta >= a[i]));
                break;
            }
            ans = max(ans, i + 1);
            if(i != 0)
            {
                delta = min(delta, a[i] - a[i - 1]);
            }
        }
        cout << ans << '\n';
    }
}