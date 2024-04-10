#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,num=0,sum=0;
ll a[3009];
ll go1(ll x)
{
    ll g=num,d=sum;
    ll mx=0,mn=0,cur=0;
    for(int i=0;i<x;i++)
    {
        if(a[i]!=0){cur+=a[i];d-=a[i];mx=max(mx,cur);mn=min(mn,cur);continue;}
        g--;
        ll ff=cur+d-g*k+k;
        ll h=k;
        if(ff>0)h-=ff;
        cur+=h;
        mx=max(mx,cur);
        mn=min(mn,cur);

    }

    for(int i=x;i<n;i++)
    {
        if(a[i]!=0){cur+=a[i];d-=a[i];mx=max(mx,cur);mn=min(mn,cur);continue;}
        g--;
        ll ff=cur+d+g*k-k;
        ll h=k;
        if(ff<0)h+=ff;
        cur-=h;
        mx=max(mx,cur);
        mn=min(mn,cur);

    }
    return mx-mn+1;
}
ll go2(ll x)
{
    ll g=num,d=sum;
    ll mx=0,mn=0,cur=0;
    for(int i=0;i<x;i++)
    {
        if(a[i]!=0){cur+=a[i];d-=a[i];mx=max(mx,cur);mn=min(mn,cur);continue;}
        g--;
        ll ff=cur+d+g*k-k;
        ll h=k;
        if(ff<0)h+=ff;
        cur-=h;
        mx=max(mx,cur);
        mn=min(mn,cur);

    }
    for(int i=x;i<n;i++)
    {
        if(a[i]!=0){cur+=a[i];d-=a[i];mx=max(mx,cur);mn=min(mn,cur);continue;}
        g--;
        ll ff=cur+d-g*k+k;
        ll h=k;
        if(ff>0)h-=ff;
        cur+=h;
        mx=max(mx,cur);
        mn=min(mn,cur);

    }


    return mx-mn+1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)num++;
        sum+=a[i];
    }
    if(abs(sum)>k*num){cout<<-1;return 0;}
    ll ans=0;
    for(int i=0;i<=n;i++){ans=max(ans,go1(i));ans=max(ans,go2(i));}
    cout<<ans;
    return 0;
}