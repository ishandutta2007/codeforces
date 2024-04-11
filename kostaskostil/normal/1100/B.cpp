#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;

int cnt=0;
int g[100500];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for (int i=0; i<m; i++)
    {
        int x;
        cin>>x;
        if (g[x]==0)
            cnt++;
        g[x]++;
        if (cnt==n)
        {
            cout<<"1";
            for (int j=1; j<=n; j++)
            {
                g[j]--;
                if (g[j]==0)
                    cnt--;
            }
        }
        else
            cout<<"0";
    }
    return 0;
}