#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=300+10;
const ll mod=1e9+7;
ll inf=0x3f3f3f3f3f3f3f3f;
ll ch[mn][mn];
ll dp[mn][mn],fact[mn];
int a[mn];
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
int main(){
    ch[0][0]=fact[0]=1;
    for(int i=1;i<mn;i++){
        ch[i][0]=1;
        fact[i]=fact[i-1]*i%mod;
        for(int j=1;j<mn;j++)ch[i][j]=(ch[i-1][j-1]+ch[i-1][j])%mod;
    }
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    map<int,int>m;
    for(int i=0;i<n;i++){
        for(int j=2;j*j<=a[i];j++)while(a[i]%(j*j)==0)a[i]/=j*j;
        m[a[i]]++;
    }
    vector<int>v;
    for(pii p:m)v.push_back(p.second);
    int sg=1;
    ll ans=0;
    dp[0][0]=1;
    for(int i=1;i<=v.size();i++){
        for(int j=i;j<=n;j++){
            for(int k=1;k<=min(j,v[i-1]);k++){
                dp[i][j]+=dp[i-1][j-k]*ch[v[i-1]-1][k-1]%mod*po(fact[k]);
                dp[i][j]%=mod;
            }
        }
    }
    for(int i=n;i>=1;i--,sg*=-1){
        ans+=sg*fact[i]*dp[v.size()][i],ans%=mod;
    }
    for(int x:v)ans*=fact[x],ans%=mod;
    if(ans<0)ans+=mod;
    printf("%lld\n",ans);
}