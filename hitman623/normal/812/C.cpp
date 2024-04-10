#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
using namespace std;
long n,s,a[100005],i,lo,mid,hi,ans=0;
long check(long mid)
{
    vl v;
    long i,b=s;
    for(i=0;i<n;++i)
    v.pb(a[i]+(i+1)*mid);
    sort(v.begin(),v.end());
    i=0;
    while(i<v.size())
    {
        if(b>=v[i])
        b-=v[i];
        else break;
        i++;
    }
    if(i>=mid) return 1;
    return 0;
}
int main()
{
    cin>>n>>s;
    for(i=0;i<n;++i)
    cin>>a[i];
    lo=0,hi=n+1,mid=(lo+hi)/2;
    for(i=0;i<60;++i)
    {
        if(check(mid))
        lo=mid;
        else hi=mid;
        mid=(lo+hi)/2;
    }
    if(check(hi)) mid=hi;
    vl v;
    for(i=0;i<n;++i)
    v.pb(a[i]+(i+1)*mid);
    sort(v.begin(),v.end());
    for(i=0;i<mid;++i)
    ans=ans+v[i];
    cout<<mid<<" "<<ans;
    return 0;
}