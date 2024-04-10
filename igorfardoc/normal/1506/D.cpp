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
        map<int, int> am;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            am[a[i]]++;
        }
        int ans = (n % 2);
        for(auto p : am)
        {
            if(p.second > n / 2)
            {
                ans = n - 2 * (n - p.second);
                break;
            }
        }
        cout << ans << '\n';
    }
}