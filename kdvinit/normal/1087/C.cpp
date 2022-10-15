/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

void connect(int x1,int y1,int x2,int y2)
{
    if(y1<=y2)
    {
        for(int i=y1;i<y2;i++) cout<<x1<<" "<<i<<endl;
    }
    else
    {
        for(int i=y1;i>y2;i--) cout<<x1<<" "<<i<<endl;
    }

    if(x1<=x2)
    {
        for(int i=x1;i<x2;i++) cout<<i<<" "<<y2<<endl;
    }
    else
    {
        for(int i=x1;i>x2;i--) cout<<i<<" "<<y2<<endl;
    }
}

void solve()
{
    int x[4],y[4],p[4],q[4];

    for(int i=1;i<=3;i++)
    {
        cin>>x[i]>>y[i];
        p[i]=x[i];
        q[i]=y[i];
    }

    sort(p+1,p+4);
    sort(q+1,q+4);
    int mx=p[2],my=q[2];

    int ans=0;
    for(int i=1;i<=3;i++)
    {
        ans+=abs(mx-x[i]);
        ans+=abs(my-y[i]);
    }
    ans++;

    cout<<ans<<endl;

    cout<<mx<<" "<<my<<endl;

    for(int i=1;i<=3;i++)
    {
        connect(x[i],y[i],mx,my);
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}