#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[1000009];
ll pr[1000009];
ll mod=998244353;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=2;i<1000000;i++)
    {
        if(pr[i])continue;
        for(ll j=i*1LL*i;j<=1000000;j+=i)pr[j]=i;
    }

    for(int i=2;i<=1000000;i++)
        if(pr[i]==0)pr[i]=i;
    for(int i=2;i<=1000000;i++)
    {
        int x=i;
        p[i]=1;
        while(x>1)
        {
            int u=pr[x],z=0;
            while((x%u)==0){z++;x/=u;}
            p[i]*=(z+1);
        }
    }
    p[0]=2;
    p[1]=1;
    ll r=1,ans=0,n;
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        if(i>1)r*=2;
        r%=mod;
        ans+=r*(p[n-i]-1);
        ans%=mod;

    }
    cout<<ans;

    return 0;
}