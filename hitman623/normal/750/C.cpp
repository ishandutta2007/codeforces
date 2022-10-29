#include <bits/stdc++.h>
#define h 1000000009
using namespace std;
long long n,o[200005][2];
long long check(long mid)
{
    long i;
    for(i=0;i<n;++i)
    {
        if(o[i][1]==1 && mid<1900) return -h-10;
        if(o[i][1]==2 && mid>=1900) return -h-20;
        mid+=o[i][0];
    }
    return mid;
}
int main()
{
    long long i,f,ans=-h;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>o[i][0]>>o[i][1];
    long long hi=h,lo=-h,mid=(lo+hi)/2;
    while(hi-lo>1)
    {
        f=check(mid);
        ans=max(ans,f);
        if(f==-h-10 || f>=-h) lo=mid;
        else hi=mid;
        mid=(lo+hi)/2;
    }
    if(ans<-h+5) cout<<"Impossible";
    else if(mid==h-1) cout<<"Infinity";
    else cout<<ans;
    return 0;
}