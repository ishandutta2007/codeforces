#include <bits/stdc++.h>
#define pb push_back

using namespace std;

int main()
{
    long long n,a[100005],i,p[100005]={0},mn=0,mx=0,ans=0;
    vector < long long > v;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    for(i=0;i<n-1;++i)
    v.pb(abs(a[i]-a[i+1]));
    p[0]=v[0];
    for(i=1;i<n-1;++i)
    {
        if(i%2==0)
        p[i]=v[i]+p[i-1];
        else
        p[i]=-v[i]+p[i-1];
    }
    for(i=0;i<n-1;++i)
    {
        if(i%2==0)
        ans=max(ans,p[i]-mn);
        else ans=max(ans,mx-p[i]);
        if(p[i]>mx) mx=p[i];
        if(p[i]<mn) mn=p[i];
    }
    cout<<ans;
    return 0;
}