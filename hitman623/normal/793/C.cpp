#include <bits/stdc++.h>
#define pb push_back
using namespace std;
long double n,xx1,yy1,xx2,yy2,rx[100005],ry[100005],vx[100005],vy[100005],du=0,dw=1e15;
long double m(long i)
{
    long double t;
    if(vx[i]>0) t=(xx1-rx[i])/vx[i];
    else if(vx[i]<0) t=(xx2-rx[i])/vx[i];
    else if(rx[i]>xx1 && rx[i]<xx2) t=0;
    else return dw;
    if(vy[i]>0) t=max(t,(yy1-ry[i])/vy[i]);
    else if(vy[i]<0) t=max(t,(yy2-ry[i])/vy[i]);
    else if(ry[i]>yy1 && ry[i]<yy2) t=max(t,du);
    else return dw;
    return t;
}
long double M(long i)
{
    long double t;
    if(vx[i]>0) t=(xx2-rx[i])/vx[i];
    else if(vx[i]<0) t=(xx1-rx[i])/vx[i];
    else if(rx[i]>xx1 && rx[i]<xx2) t=dw;
    else return du;
    if(vy[i]>0) t=min(t,(yy2-ry[i])/vy[i]);
    else if(vy[i]<0) t=min(t,(yy1-ry[i])/vy[i]);
    else if(ry[i]>yy1 && ry[i]<yy2) t=min(t,dw);
    else return du;
    return t;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(14);
    vector < pair < long double , long double > > v;
    long double mn=0,mx=1e15;
    long i;
    cin>>n;
    cin>>xx1>>yy1>>xx2>>yy2;
    if(xx1>xx2) swap(xx1,xx2);
    if(yy1>yy2) swap(yy1,yy2);
    for(i=0;i<n;++i)
    {
        cin>>rx[i]>>ry[i]>>vx[i]>>vy[i];
        v.pb({m(i),M(i)});
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;++i)
    {
        if(v[i].first>mn) mn=v[i].first;
        if(v[i].second<mx) mx=v[i].second;
    }
    if(mn<mx) cout<<mn;
    else cout<<-1;
    return 0;
}