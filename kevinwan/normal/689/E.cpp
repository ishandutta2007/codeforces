#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const ll mod=1e9+7;
const int mn=2e5+10;
int a[mn],b[mn];
ll fact[mn];
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll ch(ll a,ll b){
    if(a<0||b<0||b>a)return 0;
    return fact[a]*po(fact[b]*fact[a-b]%mod)%mod;
}
ll p[mn*2];
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int>nums;
    for(int i=0;i<n;i++)scanf("%d%d",a+i,b+i),nums.push_back(a[i]),nums.push_back(b[i]+1);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    map<int,int>comp;
    for(int i=0;i<nums.size();i++)comp[nums[i]]=i;
    for(int i=0;i<n;i++)a[i]=comp[a[i]],b[i]=comp[b[i]+1]-1;
    fact[0]=1;
    for(int i=1;i<=n;i++)fact[i]=fact[i-1]*i%mod;
    for(int i=0;i<n;i++)p[a[i]]++,p[b[i]+1]--;
    for(int i=1;i<mn*2;i++)p[i]+=p[i-1];
    ll ans=0;
    for(int i=0;i<nums.size()-1;i++){
        ans+=ch(p[i],k)*(nums[i+1]-nums[i]),ans%=mod;
    }
    printf("%lld",ans);
}