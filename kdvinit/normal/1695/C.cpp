/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+1][m+1];
    memset(a, 0, sizeof(a));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin>>a[i][j];
    }

    int l = n+m-1;
    if(l%2==1) return false;

    int mn[n+1][m+1];
    int mx[n+1][m+1];

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            mn[i][j]=0;
            mx[i][j]=0;

            int tkn=0;
            if(a[i-1][j]!=0)
            {
                tkn=1;
                mn[i][j]=mn[i-1][j];
                mx[i][j]=mx[i-1][j];
            }

            if(a[i][j-1]!=0)
            {
                if(tkn==0)
                {
                    mn[i][j]=mn[i][j-1];
                    mx[i][j]=mx[i][j-1];
                }
                else
                {
                    mn[i][j]=min(mn[i][j], mn[i][j-1]);
                    mx[i][j]=max(mx[i][j], mx[i][j-1]);
                }
            }

            mn[i][j]+=a[i][j];
            mx[i][j]+=a[i][j];
        }
    }

    if(mn[n][m]<=0 && mx[n][m]>=0) return true;
    else return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}