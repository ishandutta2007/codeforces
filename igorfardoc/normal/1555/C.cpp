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
        int m;
        cin >> m;
        vector<vector<int> > a(2, vector<int>(m));
        ll fir = 0;
        ll sec = 0;
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if(i == 0)
                {
                    sec += a[i][j];
                }
            }
        }
        sec -= a[0][0];
        ll ans = 1000000000000000ll;
        for(int i = 0; i < m; i++)
        {
            ans = min(ans, max(fir, sec));
            fir += a[1][i];
            if(i != m - 1)
            {
                sec -= a[0][i + 1];
            }
        }
        cout << ans << '\n';
    }
}