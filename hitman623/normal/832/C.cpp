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
long n,i,t,tim;
double x,y,s,d=1e6;
vector < pair < double , double > > v[2];
long check(double mid)
{
    long i,l,r;
    vll vv;
    for(i=0;i<v[0].size();++i)
    {
        if(v[0][i].x/v[0][i].y<=mid) {vv.pb({-1e18,-2});vv.pb({1e18,2});continue;}
        l=(long)((mid*(s*s-v[0][i].y*v[0][i].y)+v[0][i].y*v[0][i].x)/s);
        if(l>=v[0][i].x)
        {
            vv.pb({v[0][i].x,-2});
            vv.pb({l,2});
        }
    }
    for(i=0;i<v[1].size();++i)
    {
        if((d-v[1][i].x)/v[1][i].y<=mid) {vv.pb({-1e18,-1});vv.pb({1e18,1});continue;}
        r=(d-(long)((mid*(s*s-v[1][i].y*v[1][i].y)+v[1][i].y*(d-v[1][i].x))/s));
        if(r<=v[1][i].x)
        {
            vv.pb({v[1][i].x,1});
            vv.pb({r,-1});
        }
    }
    sort(vv.begin(),vv.end());
    long f=0,g=0;
    for(i=0;i<vv.size();++i)
    {
        if(vv[i].y%2==0)
        f-=vv[i].y;
        else g-=vv[i].y;
        if(f>0 && g>0) return 1;
    }
    return 0;
}

int main()
{
    io
    cout<<fixed;
    cout<<setprecision(10);
    cin>>n>>s;
    for(i=0;i<n;++i)
    {
        cin>>x>>y>>t;
        v[t-1].pb({x,y});
    }
    sort(v[0].begin(),v[0].end());
    sort(v[1].begin(),v[1].end());
    double lo=0,hi=1e6+1,mid;
    for(i=0;i<80;++i)
    {
        mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    if(check(lo)) cout<<lo;
    else if(check(mid)) cout<<mid;
    else cout<<hi;
    return 0;
}