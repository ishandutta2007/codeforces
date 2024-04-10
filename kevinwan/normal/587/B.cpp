#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=1e6+10;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll ch[mn];
ll a[mn];
ll dp[mn];
ll f[mn],fs[mn];
int main(){
    ch[0]=1;
    int n,k;
    ll l;
    scanf("%d%lld%d",&n,&l,&k);
    for(int i=1;i<mn;i++)ch[i]=ch[i-1]*((l/n+1-i)%mod)%mod*po(i)%mod;
    vector<int>nums;
    for(int i=0;i<n;i++)scanf("%lld",a+i),nums.push_back(a[i]);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    map<int,int>comp;
    for(int i=0;i<nums.size();i++)comp[nums[i]]=i;
    for(int i=0;i<n;i++)f[comp[a[i]]]++;
    for(int i=0;i<l%n;i++)fs[comp[a[i]]]++;
    ll ans=0;
    dp[0]=1;
    for(int i=1;i<=k;i++){
        ll cum=0;
        ll perm=1;
        if(i>l/n+1)perm=0;
        for(int j=0;j<nums.size();j++){
            cum+=dp[j];
            ans+=cum*fs[j]%mod*perm,ans%=mod;
        }
        cum=0;
        for(int j=0;j<nums.size();j++){
            cum+=dp[j],cum%=mod;
            dp[j]=cum*f[j]%mod;
        }
        perm=l/n-i+1;
        if(perm<0)perm=0;
        for(int j=0;j<nums.size();j++)ans+=perm%mod*dp[j],ans%=mod;
    }
    printf("%lld",ans);
}