#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e3+10;
bool a[mn],b[mn];
ll dp[mn][mn];
const ll mod=1e9+7;
ll solve(ll a,ll b){
    if(dp[a][b]+1)return dp[a][b];
    if(a==0)return 0;
    if(b){
        return dp[a][b]=((a-b)*solve(a-1,b)+b*solve(a-1,b-1))%mod;
    }
    else{
        return dp[a][b]=(a-1)*solve(a-1,1)%mod;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(x+1)a[i]=1,b[x]=1;
    }
    int k=0,l=0;
    for(int i=1;i<=n;i++){
        if(!a[i])k++;
        if(b[i]&&!a[i])l++;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0]=1;
    printf("%lld",solve(k,l));
}