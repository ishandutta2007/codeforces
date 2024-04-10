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

    int a[n+1],b[n+1],c[m+1],d[m+1];
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=m;i++) cin>>c[i]>>d[i];

    int mx=33500000;
    int y_of_x[mx+1]={0},x,y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]>c[j] || b[i]>d[j]) continue;
            x=c[j]-a[i];
            y=d[j]-b[i];
            y_of_x[x]=max(y_of_x[x],y+1);
        }
    }

    for(int i=mx-1;i>=0;i--) y_of_x[i]=max(y_of_x[i],y_of_x[i+1]);
    for(int i=1;i<=mx;i++) y_of_x[i]+=i;

    int ans=y_of_x[0];
    for(int i=1;i<=mx;i++) ans=min(ans,y_of_x[i]);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}