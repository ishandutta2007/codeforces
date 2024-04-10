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
    int l,n;
    cin>>n>>l;

    double strt=0,nd=l;

    double a[n+2]={0};
    for(int i=1;i<=n;i++) cin>>a[i];
    a[n+1]=(double)l;

    double time1[n+2]={0},time2[n+2]={0};

    double speed1=1,speed2=1;

    for(int i=1;i<=n+1;i++)
    {
        time1[i]=time1[i-1]+(double)((a[i]-strt)/speed1);
        strt=a[i];
        speed1++;
    }

    for(int i=n;i>=0;i--)
    {
        time2[i]=time2[i+1]+(double)((nd-a[i])/speed2);
        nd=a[i];
        speed2++;
    }
    /*
    for(int i=0;i<=n+1;i++) cout<<time1[i]<<" ";
    cout<<endl;
    for(int i=0;i<=n+1;i++) cout<<time2[i]<<" ";
    cout<<endl;
    */

    int i=1;
    while(1)
    {
        if(time1[i]>time2[i]) break;
        i++;
    }

    double dist=(a[i]-a[i-1]);

    if(time1[i-1]>time2[i])
    {
        dist-=((n-i+2)*(time1[i-1]-time2[i]));
    }
    else
    {
        dist-=((i)*(time2[i]-time1[i-1]));
    }

    double ans=max(time1[i-1],time2[i])+(double)(dist/(n+2));
    cout<<ans<<endl;

}

int32_t main()
{
    std::cout << std::setprecision(15); std::cout << std::fixed;
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}