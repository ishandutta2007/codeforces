#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long T,f,p[3],t[3],a[3],x,ans=1e18,cur,y,z;
long check(long x,long y,long z)
{
    x=max(x,0LL);
    y=max(y,0LL);
    long tt=t[1]*a[1]*x+t[2]*a[2]*y+t[0]*z,ti=tt,ex=(a[1]*x+a[2]*y+z-f);
    if(ex<a[1]*x)
    ti=min(ti,tt-ex*t[1]);
    if(ex<a[2]*y)
    ti=min(ti,tt-ex*t[2]);
    if(ex<z)
    ti=min(ti,tt-ex*t[0]);
    return (a[1]*x+a[2]*y+z>=f && ti<=T);
}
long check2(long x,long y)
{
    x=max(x,0LL);
    y=max(y,0LL);
    z=max(0LL,f-a[1]*x-a[2]*y);
    long tt=t[1]*a[1]*x+t[2]*a[2]*y+t[0]*z,ti=tt,ex=(a[1]*x+a[2]*y+z-f);
    if(ex<a[1]*x)
    ti=min(ti,tt-ex*t[1]);
    if(ex<a[2]*y)
    ti=min(ti,tt-ex*t[2]);
    if(ex<z)
    ti=min(ti,tt-ex*t[0]);
    return (a[1]*x+a[2]*y+z>=f && ti<=T);
}
int main()
{
    io
    cin>>f>>T>>t[0]>>a[1]>>t[1]>>p[1]>>a[2]>>t[2]>>p[2];
    for(z=0;z<=T/t[0]+2;++z)
    if(t[1]!=t[2])
    {
        y=(T-t[0]*z-t[1]*f+t[1]*z)/((t[2]-t[1])*a[2]);
        x=(f-z-a[2]*y)/a[1];
        x=max(x,0LL);
        y=max(y,0LL);
        if(check(x,y,z)) ans=min(ans,p[1]*x+p[2]*y);
        if(check(x+1,y,z)) ans=min(ans,p[1]*x+p[2]*y+p[1]);
        if(check(x,y+1,z)) ans=min(ans,p[1]*x+p[2]*y+p[2]);
        if(check(x+1,y+1,z)) ans=min(ans,p[1]*x+p[2]*y+p[1]+p[2]);
    }
    for(x=0;x<=T/(a[1]*t[1])+3;++x)
    if(t[0]!=t[2])
    {
        z=(T-t[1]*a[1]*x-t[2]*f+t[2]*a[1]*x)/(t[0]-t[2]);
        y=(f-a[1]*x-z)/a[2];
        y=max(y,0LL);
        if(check2(x,y)) ans=min(ans,p[1]*x+p[2]*y);
        if(check2(x,y+1)) ans=min(ans,p[1]*x+p[2]*y+p[2]);
    }
    else if(t[0]*f-t[0]*a[1]*x<=T-t[1]*a[1]*x && T-t[1]*a[1]*x>=0)
    ans=min(ans,p[1]*x);
    if(ans!=1e18)
    cout<<ans;
    else cout<<-1;
    return 0;
}