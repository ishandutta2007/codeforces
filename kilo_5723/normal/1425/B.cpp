#include <bits/stdc++.h>
using namespace std;
const int maxm=2e3+5;
vector<int> e[maxm];
bool b[maxm];
int siz;
void dfs(int u){
    if (b[u]) return;
    b[u]=true; siz++;
    for (auto v:e[u]) dfs(v);
}
vector<int> arr;
void init(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=0,u,v;i<m;i++){
        scanf("%d%d",&u,&v);
        if (u!=1&&v!=1){
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }
    for (int i=2;i<=n;i++) if (!b[i]){
        siz=0;
        dfs(i);
        arr.push_back(siz+1);
    }
}
typedef long long ll;
const ll mod=1e9+7;
const int mid=4005,maxn=8010;
ll dp[maxn],tmp[maxn];
void add(ll n){
    memset(tmp,0,sizeof(tmp));
    for (int i=n;i<maxn-n;i++)
        tmp[i]=(dp[i-n]+dp[i]+dp[i+n])%mod;
    memcpy(dp,tmp,sizeof(dp));
}
void rem(ll n){
    memset(tmp,0,sizeof(tmp));
    for (int i=0;i<maxn-2*n;i++) if (dp[i]){
        tmp[i+n]=dp[i]; dp[i+n]=(dp[i+n]-dp[i])%mod; dp[i+2*n]=(dp[i+2*n]-dp[i])%mod;
    }
    memcpy(dp,tmp,sizeof(dp));
}
void go(ll n){
    memset(tmp,0,sizeof(tmp));
    for (int i=n;i<maxn-n;i++)
        tmp[i]=(dp[i-n]+dp[i+n])%mod;
    memcpy(dp,tmp,sizeof(dp));
}
void rem2(ll n){
    memset(tmp,0,sizeof(tmp));
    for (int i=0;i<maxn-2*n;i++) if (dp[i]){
        tmp[i+n]=dp[i]; dp[i+2*n]=(dp[i+2*n]-dp[i])%mod;
    }
    memcpy(dp,tmp,sizeof(dp));
}
ll tp[maxm][mid];
int main(){
    init();
    ll ans=0;
    dp[mid]=1;
    for (auto v:arr) add(v);
    for (auto v:arr){
        rem(v);
        for (int i=mid-v+2;i<mid+v-1;i++)
            ans=(ans+2*dp[i])%mod;
        add(v);
    }
    int sum=0;
    for (auto v:arr) sum+=v;
    if (sum&1){
        memset(dp,0,sizeof(dp));
        dp[mid]=1;
        for (auto v:arr) go(v);
for (auto v:arr){
rem2(v);
ans=(ans+(dp[mid-v+1]+dp[mid+v-1])*2)%mod;
go(v);}
    }
    else {
        memset(dp,0,sizeof(dp));
        dp[mid]=1;
        for (auto v:arr) go(v);
ans=(ans+dp[mid])%mod;
    }
    printf("%lld\n",(ans+mod)%mod);
    return 0;
}