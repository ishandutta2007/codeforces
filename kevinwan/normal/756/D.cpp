#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=5e3+10;
ll po(ll a,ll b=mod-2){
    ll ans=1;
    for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
    return ans;
}
ll fact[mn];
ll ch(ll a,ll b){return fact[a]*po(fact[b]*fact[a-b]%mod)%mod;}
ll dp[mn][mn];
ll cp[26][mn];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    fact[0]=1;
    for(int i=1;i<mn;i++)fact[i]=fact[i-1]*i%mod;
    int n;
    cin>>n;
    string s;
    cin>>s;
    s.erase(unique(s.begin(),s.end()),s.end());
    for(char&c:s)c-='a';
    s=" "+s;
    dp[0][0]=1;
    for(int i=1;i<s.size();i++){
        for(int j=1;j<=n;j++)dp[i][j]=dp[i-1][j-1];
        for(int j=1;j<=n;j++)dp[i][j]-=cp[s[i]][j]+cp[s[i]][j-1],dp[i][j]%=mod;
        for(int j=1;j<=n;j++)cp[s[i]][j]+=dp[i][j],cp[s[i]][j]%=mod;
        for(int j=0;j<=n;j++)dp[i][j]+=dp[i-1][j],dp[i][j]%=mod;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)ans+=dp[s.size()-1][i]*ch(n-1,i-1),ans%=mod;
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}