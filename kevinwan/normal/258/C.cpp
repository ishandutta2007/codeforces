#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e5+10;
int k[mn];
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
vector<int>f[mn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        k[x]++;
    }
    for(int i=1;i<mn;i++)k[i]+=k[i-1];
    for(int i=1;i<mn;i++)for(int j=i;j<mn;j+=i)f[j].push_back(i);
    ll ans=1;
    for(int i=2;i<mn;i++){
        ll hail=1,j;
        for(j=1;j<f[i].size();j++){
            hail*=po(j,k[f[i][j]-1]-k[f[i][j-1]-1]),hail%=mod;
        }
        ll hail1=hail*po(j-1,k[mn-1]-k[f[i][j-1]-1])%mod;
        ans-=hail1;
        hail*=po(j,k[mn-1]-k[f[i][j-1]-1]),hail%=mod;
        ans+=hail;
        ans%=mod;
    }
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}