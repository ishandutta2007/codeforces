/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char x; cin>>x;
            if(x=='.') a[i][j]=0;
            else a[i][j]=1;
        }
    }

    int ml[n+1][m+1],mr[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        int cnt=0;
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0) { ml[i][j]=0; cnt=0; }
            else
            {
                ml[i][j]=cnt;
                cnt++;
            }
        }

        cnt=0;
        for(int j=m;j>0;j--)
        {
            if(a[i][j]==0) { mr[i][j]=0; cnt=0; }
            else
            {
                mr[i][j]=cnt;
                cnt++;
            }
        }
    }

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0) continue;
            int cnt=0;
            while(1)
            {
                if((i+cnt)>n || (j-cnt)<1 || (j+cnt)>m) break;
                if(ml[i+cnt][j]<cnt || mr[i+cnt][j]<cnt) break;
                cnt++;
            }
            ans+=cnt;
        }
    }
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}