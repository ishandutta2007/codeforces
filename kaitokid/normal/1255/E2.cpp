#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,u;
vector<ll>pr;
ll a[1000009],b[1000009];
ll go(ll x)
{
    for(int i=0;i<n;i++)b[i]=a[i];
    ll i=0,j=0,sum=0,res=0,mx=0,l;
    while(i<n&&a[i]==0)i++;
    j=i;
    while(j<n)
    {
        if(sum<(x+1)/2&&sum+b[j]>=(x+1)/2)l=j;
        if(sum<x&&sum+b[j]>=x)
        {


            for(int q=i;q<j;q++)res+=b[q]*abs(q-l);
            res+=(x-sum)*abs(j-l);
            //cout<<j<<" "<<res<<" "<<l<<endl;
            b[j]=(b[j]-(x-sum))%x;
            i=j;
            while(i<n&&b[i]==0)i++;
            j=i;
            sum=0;
            continue;
        }
        sum+=b[j];

    j++;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        u+=a[i];
    }
    ll v=u;
    if(u==1){cout<<-1;return 0;}
    ll gh=sqrt(u)+1;
    for(int i=2;i<=gh;i++)
    {
        if(u<2)break;
        if(u%i==0)pr.push_back(i);
    while(u%i==0)u/=i;
    }
    if(u>1)pr.push_back(u);
    u=v;
    ll ans=1e18;
    int s=pr.size();
    for(int i=0;i<s;i++)
    {

        ans=min(ans,go(pr[i]));
//cout<<pr[i]<<" "<<ans<<endl;
    }
    cout<<ans;
    return 0;
}