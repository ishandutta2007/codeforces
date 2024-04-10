#include <bits/stdc++.h>
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml map < int , int >
#define mll map < pll , int >
#define x first
#define y second
#define vl vector < int >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
void scanint(int &x)
{
    scanf("%d",&x);
}
int n,m,k,a[1000006],b[1000006],i,x;
vll v;
int check(int mid)
{
    int i=0,j=mid-1;
    vl vv;
    while(i<n && j>=0)
    {
        if(a[i]<v[j].x)
        vv.pb(a[i++]);
        else vv.pb(v[j--].x);
    }
    while(i<n)
    vv.pb(a[i++]);
    while(j>=0)
    vv.pb(v[j--].x);
    j=0;
    for(i=0;i<n+mid;i+=k,j++)
    if(vv[i]<j) return 0;
    return 1;
}
int main()
{
    io
    scanint(n);
    scanint(m);
    scanint(k);
    for(i=0;i<n;++i)
    scanint(a[i]);
    sort(a,a+n);
    for(i=0;i<m;++i)
    {
        scanint(x);
        v.pb({x,i});
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int lo=0,mid,hi=m;
    while(hi-lo>1)
    {
        mid=(lo+hi)/2;
        if(check(mid))
        lo=mid;
        else hi=mid;
    }
    if(check(hi))
    {
        cout<<hi<<"\n";
        for(i=0;i<hi;++i)
        cout<<v[i].y+1<<" ";
    }
    else if(check(mid))
    {
        cout<<mid<<"\n";
        for(i=0;i<mid;++i)
        cout<<v[i].y+1<<" ";
    }
    else if(check(lo))
    {
        cout<<lo<<"\n";
        for(i=0;i<lo;++i)
        cout<<v[i].y+1<<" ";
    }
    else cout<<-1;
    return 0;
}