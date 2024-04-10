#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll mn[9000009],sum[9000009],num[9000009];
ll dp[9000009];
int a[25][30],n;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<s.size();j++)a[i][s[j]-'a']++;

    }
    for(int i=0;i<n;i++){num[(1<<i)]=1;sum[(1<<i)]=i+1;}
    for(int i=1;i<(1<<n);i++)
    {
        dp[i]=1;
        if(num[i]==1)continue;
        num[i]=num[i^(i&(-i))]+1;
        sum[i]=sum[i^(i&(-i))]+sum[(i&(-i))];

    }

    for(int z=0;z<26;z++)
    {
        for(int i=0;i<n;i++)mn[(1<<i)]=a[i][z];
        for(int i=1;i<(1<<n);i++)
        {
            if(num[i]!=1){mn[i]=min(mn[i^(i&(-i))],mn[(i&(-i))]);}
            dp[i]=(dp[i]*1LL*(mn[i]+1))%mod;
        }
    }
    for(int i=1;i<(1<<n);i++)
        if(num[i]%2==0)dp[i]=(2*1LL*mod-dp[i])%mod;

    for(int j=0;j<n;j++)
        for(int i=0;i<(1<<n);i++)
    if(i&(1<<j))dp[i]=(dp[i]+dp[i^(1<<j)])%mod;
    ll ans=0;
    for(int i=0;i<(1<<n);i++)
    {
        //cout<<i<<" "<<dp[i]<<" "<<num[i]<<" "<<sum[i]<<endl;
        ll res=dp[i];
        res*=num[i];
        res*=sum[i];
        ans^=res;
    }
    cout<<ans;
    return 0;
}