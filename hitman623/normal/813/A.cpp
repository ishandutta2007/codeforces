#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
int main()
{
    io;
    long n,j,m,i,a[1003],x,y,s=0,ans=-1,f=0;
    vll v;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        s+=a[i];
    }
    cin>>m;
    for(i=0;i<m;++i)
    {
        cin>>x>>y;
        if(s<=y && f==0) {f=1;ans=max(s,x);}
    }
    cout<<ans;
    return 0;
}