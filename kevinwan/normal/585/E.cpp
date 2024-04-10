#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll>pll;
typedef pair<int,int>pii;
const int mn=1e7+10;
const ll mod=1e9+7;
int cnt[mn],mu[mn];
bool isp[mn];
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(int i=1;i<mn;i++)for(int j=2*i;j<mn;j+=i)cnt[i]+=cnt[j];
    fill(mu,mu+mn,1);
    fill(isp,isp+mn,1);
    for(int i=2;i*i<mn;i++)if(isp[i])for(int j=i*i;j<mn;j+=i)isp[j]=0;
    for(int i=2;i<mn;i++)if(isp[i])for(int j=i;j<mn;j+=i){
        if(j/i%i==0)mu[j]=0;
        else mu[j]*=-1;
    }
    ll a1=0;
    for(int i=2;i<mn;i++){
        a1-=(po(2,cnt[i])-1)*mu[i]*(cnt[1]-cnt[i])%mod;
        a1%=mod;
    }
    if(a1<0)a1+=mod;
    printf("%lld",a1);
}