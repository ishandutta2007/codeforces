#pragma GCC optimize "O3"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,avx2,mmx,popcnt,tune=native"
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const ll mod=1e9+7;
const int mn=1e5+10;
int ki[2];
ll a[24],su[1<<24];
int dp[1<<24];
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k;
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cin>>k;
    ki[0]=ki[1]=-1;
    for(int i=0;i<k;i++)cin>>ki[i];
    dp[0]=1;
    for(int i=1;i<1<<n;i++){
        int l=__builtin_ctz(i);
        su[i]=su[i&(~(1<<l))]+a[l];
    }
    for(int i=0;i<1<<n;i++){
        ll sum=su[i];
        if(sum==ki[0]||sum==ki[1]){
            dp[i]=0;
            continue;
        }
        for(int j=0;j<n;j++)if(!((i>>j)&1)){
            int u=i|(1<<j);
            dp[u]+=dp[i];
            if(dp[u]>=mod)dp[u]-=mod;
        }
    }
    printf("%lld",dp[(1<<n)-1]);
}