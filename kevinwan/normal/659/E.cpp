#include<bits/stdc++.h>
using namespace std;
vector<int> g[100001];
bool vis[100001],cycle;
void dfs(int x,int p){
    vis[x]=1;
    for(int y:g[x]){
        if(y==p)continue;
        if(vis[y])cycle=1;
        else dfs(y,x);
    }
}
int main(){
    int v,e,i,a,b,ans=0;
    scanf("%d%d",&v,&e);
    for(i=0;i<e;i++)scanf("%d%d",&a,&b),g[a].push_back(b),g[b].push_back(a);
    for(i=1;i<=v;i++){
        if(vis[i])continue;
        cycle=0;
        dfs(i,0);
        if(!cycle)ans++;
    }
    printf("%d",ans);
}