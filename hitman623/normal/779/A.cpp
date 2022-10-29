#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a[102],b[102],i,ans=0;
    cin>>n;
    map < int ,int > fa,fb;
    for(i=0;i<n;++i)
        {cin>>a[i];
        fa[a[i]]++;}
    for(i=0;i<n;++i)
        {cin>>b[i];
        fb[b[i]]++;}
    for(i=1;i<=5;++i)
    if((fa[i]+fb[i])%2==0) ans+=abs(fb[i]-fa[i])/2;
    else {cout<<-1;return 0;}
    cout<<ans/2;
    return 0;
}