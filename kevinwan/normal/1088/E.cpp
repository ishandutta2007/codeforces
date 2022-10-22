#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll a[mn];
vector<int>g[mn];
ll dp[mn],mo;
void dfs(int x,int p){
    dp[x]=a[x];
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        if(dp[y]>0)dp[x]+=dp[y];
    }
    mo=max(mo,dp[x]);
}
bool u[mn];
int cnt;
void dfs2(int x,int p){
    dp[x]=a[x];
    for(int y:g[x]){
        if(y==p)continue;
        dfs2(y,x);
        if(u[y])continue;
        if(dp[y]>0)dp[x]+=dp[y];
    }
    if(dp[x]==mo)cnt++,u[x]=1;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    mo=-inf;
    dfs(1,1);
    dfs2(1,1);
    printf("%lld %d",mo*cnt,cnt);
}