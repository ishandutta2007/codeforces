#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3010;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
inline ll gcd(ll a,ll b){while(b)a%=b,swap(a,b);return a;}
vector<int>g[mn];
int s[mn],par[mn];
void gs(int x,int p){
    par[x]=p;
    s[x]=1;
    for(int y:g[x]){
        if(y!=p)gs(y,x),s[x]+=s[y];
    }
}
ll dp[mn][mn];
ll solve(int a,int b,int ab,int ba){
    if(a>b)swap(a,b),swap(ab,ba);
    if(dp[a][b]!=-1)return dp[a][b];
    dp[a][b]=0;
    int pota,potb;
    if(ab==par[a])pota=s[a];
    else pota=s[1]-s[ab];
    if(ba==par[b])potb=s[b];
    else potb=s[1]-s[ba];
    for(int y:g[a]){
        if(y==ab)continue;
        int pot;
        if(y==par[a])pot=s[1]-s[a];
        else pot=s[y];
        dp[a][b]=max(dp[a][b],solve(y,b,a,ba)+1LL*potb*pot);
    }
    for(int y:g[b]){
        if(y==ba)continue;
        int pot;
        if(y==par[b])pot=s[1]-s[b];
        else pot=s[y];
        dp[a][b]=max(dp[a][b],solve(a,y,ab,b)+1LL*pota*pot);
    }
    return dp[a][b];
}
ll ans;
void dfs(int x,int p){
    for(int y:g[x]){
        if(y==p)continue;
        ans=max(ans,solve(x,y,y,x)+1LL*s[y]*(s[1]-s[y]));
        dfs(y,x);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    memset(dp,-1,sizeof(dp));
    gs(1,0);
    dfs(1,0);
    printf("%lld",ans);
}