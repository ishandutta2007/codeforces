#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1<<20;
int k[mn];
ll po(ll a,ll b){
    ll ans=1;
    for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
    return ans;
}
int main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        k[x]++;
    }
    for(i=0;i<20;i++){
        for(j=0;j<mn;j++){
            if((j>>i)&1)continue;
            k[j]+=k[j+(1<<i)];
        }
    }
    ll ans=0;
    for(i=0;i<mn;i++){
        if(__builtin_popcount(i)&1)ans-=po(2,k[i]);
        else ans+=po(2,k[i]);
    }
    ans%=mod;
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}