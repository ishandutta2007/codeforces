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
vl v1,v2;
long n,S,s[100005],a[100005],cur=0,m,b[100005],i,sa=0,sb=0,ans=0,ss=0;
bool cmp1(long x,long y)
{
    return a[x]-b[x]<a[y]-b[y];
}
bool cmp2(long x,long y)
{
    return b[x]-a[x]<b[y]-a[y];
}
int main()
{
    io
    cin>>n>>S;
    for(i=0;i<n;++i)
    {
        cin>>s[i]>>a[i]>>b[i];
        if(a[i]>b[i])
        v1.pb(i),ans+=a[i]*s[i],sa+=s[i];
        else if(a[i]<b[i])
        v2.pb(i),ans+=b[i]*s[i],sb+=s[i];
        else ans+=s[i]*a[i],ss+=s[i];
    }
    sa%=S;
    sb%=S;
    sort(v1.begin(),v1.end(),cmp1);
    sort(v2.begin(),v2.end(),cmp2);
    if(sa+sb+ss>S)
    {
        cout<<ans;
        return 0;
    }
    long t1=0,t2=0;
    for(i=0;i<v1.size();++i)
    if(sa>0)
    {
        if(s[v1[i]]<=sa)
        {
            t1+=(b[v1[i]]-a[v1[i]])*s[v1[i]];
            sa-=s[v1[i]];
        }
        else
        {
            t1+=(b[v1[i]]-a[v1[i]])*sa;
            sa-=sa;
        }
    }
    for(i=0;i<v2.size();++i)
    if(sb>0)
    {
        if(s[v2[i]]<=sb)
        {
            t2+=(a[v2[i]]-b[v2[i]])*s[v2[i]];
            sb-=s[v2[i]];
        }
        else
        {
            t2+=(a[v2[i]]-b[v2[i]])*sb;
            sb-=sb;
        }
    }
    cout<<max(ans+t1,ans+t2);
    return 0;
}