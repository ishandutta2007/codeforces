#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
    long n,w,i,x,ans[102],s=0,t;
    vector < pair < long , long > > a;
    cin>>n>>w;
    for(i=0;i<n;++i)
    {
        cin>>x;
        s+=x;
        a.pb({x,i});
    }
    if(s<w) {cout<<-1;exit(0);}
    sort(a.begin(),a.end());
    for(i=0;i<n;++i)
    {
       ans[a[i].second]=(a[i].first+1)/2;
       w-=(a[i].first+1)/2;
    }
    if(w<0) {cout<<-1;exit(0);}
    i=n-1;
    while(w>0 && i>=0)
    {
        t=min(w,a[i].first-ans[a[i].second]);
        ans[a[i].second]+=t;
        w-=t;
        i--;
    }
    for(i=0;i<n;++i)
    cout<<ans[i]<<" ";
    return 0;
}