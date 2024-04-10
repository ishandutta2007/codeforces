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
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for(int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        ll ans = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = i - 1; j >= 0; j--)
            {
                if(a[j] < a[i])
                {
                    ++ans;
                }
            }
        }
        cout << ans << '\n';
    }
}