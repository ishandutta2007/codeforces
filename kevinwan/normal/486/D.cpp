#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> g[2001];
int v[2001],d,r;
ll dp[2001],mod=1e9+7;
void dfs(int x,int p){
    dp[x]=1;
    for(int y:g[x]){
        if(y==p)continue;
        if(v[y]<v[r]||v[y]>v[r]+d)continue;
        if(v[y]==v[r]&&y<r)continue;
        dfs(y,x);
        dp[x]=dp[x]*(dp[y]+1)%mod;
    }
}
int main(){
    int n,i,j,a,b;
    scanf("%d%d",&d,&n);
    for(i=1;i<=n;i++)scanf("%d",v+i);
    for(i=0;i<n-1;i++)scanf("%d%d",&a,&b),g[a].push_back(b),g[b].push_back(a);
    ll ans=0;
    for(i=1;i<=n;i++){
        r=i;
        dfs(i,0);
        ans+=dp[i];
        ans%=mod;
    }
    printf("%lld",ans);
}