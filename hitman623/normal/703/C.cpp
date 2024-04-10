#include <bits/stdc++.h>
#define pb push_back
#define double long double
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    io
    vector< pair < double , double > >  vv;
    long n,i;
    double w,x,y,v,u,f=1,t=0;
    cin>>n>>w>>v>>u;
    for(i=0;i<n;++i)
    {
        cin>>x>>y;
        vv.pb({x,y});
    }
    cout<<fixed;
    cout<<setprecision(10);
    for(i=0;i<n;++i)
    if((vv[i].y)*v-(vv[i].x)*u>0) {f=0;break;}
    if(f) {cout<<(w/u);exit(0);}
    for(i=0;i<n;++i)
    t=max(t,(u*vv[i].x-v*vv[i].y)/(u*v));
    cout<<t+(w/u)<<endl;
    return 0;
}