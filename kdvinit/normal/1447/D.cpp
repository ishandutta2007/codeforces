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

    char b[n+1],c[m+1];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int j=1;j<=m;j++) cin>>c[j];

    int a[n+1][m+1]={0};
    for(int i=0;i<=n;i++) a[i][0]=0;
    for(int j=0;j<=m;j++) a[0][j]=0;

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int x=max(a[i-1][j],a[i][j-1]);
            x--;
            x=max(x,(int)0);
            int y=a[i-1][j-1];
            if(b[i]==c[j])
            {
                y+=2;
                y=max(x,y);
                a[i][j]=y;
                ans=max(ans,y);
            }
            else
            {
                a[i][j]=x;
            }
        }
    }
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}