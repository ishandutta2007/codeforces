#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=998244353;
const int mn=1e6+10;
int lim;
ll dp[20][1024],num[20][1024],hail[20][1024],p[20];
ll solve(string n){
    reverse(n.begin(),n.end());
    if(n=="0")return 0;
    ll ans=0;
    for(int i=1;i<n.size();i++){
        for(int j=0;j<1024;j++){
            if(__builtin_popcount(j)>lim)continue;
            ans+=hail[i][j];
            ans%=mod;
        }
    }
    int cum=0;
    ll cs=0;
    for(int i=n.size()-1;i>=0;i--){
        for(int j=0;j<n[i]-'0';j++){
            if(i==n.size()-1&&j==0)continue;
            for(int k=0;k<1024;k++){
                if(__builtin_popcount(cum|(1<<j)|k)>lim)continue;
                ans+=dp[i][k];
                ans+=j*num[i][k]%mod*p[i]+cs*num[i][k]%mod;
                ans%=mod;
            }
        }
        cum|=1<<n[i]-'0';
        cs+=p[i]*(n[i]-'0');
        cs%=mod;
    }
    return ans;
}
int main(){
    ll l,r;
    p[0]=1;
    for(int i=1;i<20;i++)p[i]=p[i-1]*10%mod;
    cin>>l>>r;
    scanf("%d",&lim);
    num[0][0]=1;
    for(int i=1;i<20;i++){
        for(int j=0;j<1024;j++){
            for(int k=0;k<10;k++){
                int cur=j|(1<<k);
                dp[i][cur]+=dp[i-1][j];
                num[i][cur]+=num[i-1][j];
                dp[i][cur]+=k*num[i-1][j]%mod*p[i-1];
                dp[i][cur]%=mod;
                num[i][cur]%=mod;
                if(k){
                    hail[i][cur]+=dp[i-1][j];
                    hail[i][cur]+=k*num[i-1][j]%mod*p[i-1];
                    hail[i][cur]%=mod;
                }
            }
        }
    }
    ll ans=solve(to_string(r+1))-solve(to_string(l));
    ans%=mod;
    if(ans<0)ans+=mod;
    cout<<ans;
}