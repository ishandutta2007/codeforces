/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int fans;
int x[5],y[5],ox[5],oy[5];

void val(int a,int b,int c,int d)
{
    int ans=0;
    x[2]=max(ox[a],ox[b]);
    x[1]=min(ox[a],ox[b]);
    x[4]=max(ox[d],ox[c]);
    x[3]=min(ox[d],ox[c]);

    y[2]=max(oy[a],oy[c]);
    y[1]=min(oy[a],oy[c]);
    y[4]=max(oy[b],oy[d]);
    y[3]=min(oy[b],oy[d]);


    ans+=x[2]-x[1];
    ans+=x[4]-x[3];
    ans+=y[2]-y[1];
    ans+=y[4]-y[3];

    int p1=x[3]-x[2];
    int p2=x[4]-x[1];

    int q1=y[3]-y[2];
    int q2=y[4]-y[1];

    int ans2;

    if(q2<=p1)
    {
        ans2=p1-q2;
    }
    else if(p2<=q1)
    {
        ans2=q1-p2;
    }
    else ans2=0;

    ans+=2*ans2;
    //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" -> "<<ans<<endl;
    fans=min(fans,ans);

}

void solve()
{
    fans=1e20;
    for(int i=1;i<=4;i++)
    {
        cin>>x[i]>>y[i];
        ox[i]=x[i];
        oy[i]=y[i];
    }

    val(1,2,3,4);
    val(1,2,4,3);
    val(1,3,2,4);
    val(1,3,4,2);
    val(1,4,2,3);
    val(1,4,3,2);
    val(2,1,3,4);
    val(2,1,4,3);
    val(2,3,1,4);
    val(2,3,4,1);
    val(2,4,1,3);
    val(2,4,3,1);
    val(3,2,1,4);
    val(3,2,4,1);
    val(3,1,2,4);
    val(3,1,4,2);
    val(3,4,2,1);
    val(3,4,1,2);
    val(4,2,3,1);
    val(4,2,1,3);
    val(4,3,2,1);
    val(4,3,1,2);
    val(4,1,2,3);
    val(4,1,3,2);

    cout<<fans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--) solve();
    return 0;
}