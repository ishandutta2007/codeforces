#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<int,ll> num;
int l[201],dp[201],op[201],d[201];
vector<int> g[201];
int ans;
void dfs(int x,int p){
    int k1=0,k2=0;
    for(int y:g[x]){
        if(y==p)continue;
        d[y]=d[x]+1;
        dfs(y,x);
        op[x]=max(op[x],dp[y]);
        l[y]++;
        if(l[y]>k1)k2=k1,k1=l[y];
        else if(l[y]>k2)k2=l[y];
    }
    l[x]=k1;
    dp[x]=k1+k2;
}
bool yes[201];
void tra(int x,int p,int tar){
    if(x==tar)yes[x]=1;
    for(int y:g[x]){
        if(y==p)continue;
        tra(y,x,tar);
        yes[x]|=yes[y];
    }
    for(int y:g[x]){
        if(y!=p&&!yes[y])ans=max(ans,d[tar]*dp[y]);
    }
}
int main(){
    int n,i,j,a,b;
    scanf("%d",&n);
    for(i=0;i<n-1;i++)scanf("%d%d",&a,&b),g[a].push_back(b),g[b].push_back(a);
    for(i=1;i<=n;i++){
        memset(l,0,sizeof(l));
        memset(op,0,sizeof(op));
        memset(d,0,sizeof(d));
        memset(dp,0,sizeof(dp));
        dfs(i,0);
        for(j=1;j<=n;j++){
            memset(yes,0,sizeof(yes));
            tra(i,0,j);
        }
    }
    printf("%d",ans);
}