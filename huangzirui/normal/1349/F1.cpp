#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5010,mod=998244353;
int i,j,k,n,m;
ll dp[maxn][maxn],jc[maxn],ny[maxn];
ll ksm(ll sum,int num){
    ll ans=1;
    while(num){
        if(num&1)ans=ans*sum%mod;
        sum=sum*sum%mod;
        num>>=1;
    }return ans;
}
ll C(int a,int b){
    if(b>a || b<0)return 0;
    return jc[a]*ny[b]%mod*ny[a-b]%mod;
}
int main(){
    jc[0]=1;for(i=1;i<maxn;i++)jc[i]=jc[i-1]*i%mod;
    ny[maxn-1]=ksm(jc[maxn-1],mod-2);for(i=maxn-2;i>=0;i--)ny[i]=ny[i+1]*(i+1)%mod;
    cin>>n;
    dp[1][0]=1;
    for(i=2;i<maxn;i++)
        for(j=0;j<i;j++){
            dp[i][j]=dp[i-1][j]*(j+1)+dp[i-1][j-1]*(i-j);
            dp[i][j]%=mod;
        }
    for(i=0;i<n;i++){
        ll ans=0;
        for(j=max(1,i);j<=n;j++)ans+=dp[j][i]*C(n,j)%mod*jc[n-j]%mod;
        ans%=mod;
        printf("%lld ",ans);
    }puts("");
}