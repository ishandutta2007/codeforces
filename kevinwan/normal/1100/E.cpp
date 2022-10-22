#include<bits/stdc++.h>
using namespace std;
struct three{
    int a,b,c,ind;
    const bool operator<(const three&ot)const{return c>ot.c;}
};
const int mn=1e5+10;
three t[mn];
vector<int>g[mn];
int n,m,o[mn],cnt;
bool vis[mn],ins[mn];
bool fail;
void dfs2(int x){
    vis[x]=ins[x]=1;
    for(int y:g[x]){
        if(ins[y])fail=1;
        else if(!vis[y]) dfs2(y);
    }
    ins[x]=0;
}
void dfs1(int x){
    vis[x]=1;
    for(int y:g[x]){
        if(!vis[y])dfs1(y);
    }
    o[x]=cnt++;
}
vector<int>ans,bes;
bool check(int e){
    int i;
    ans.clear();
    for(i=1;i<=n;i++)g[i].clear();
    for(i=0;i<e;i++)g[t[i].a].push_back(t[i].b);
    memset(vis,0,sizeof(vis));
    fail=0;
    for(i=1;i<=n;i++)if(!vis[i])dfs1(i);
    memset(vis,0,sizeof(vis));
    for(i=e;i<m;i++){
        if(o[t[i].a]>o[t[i].b])g[t[i].a].push_back(t[i].b);
        else g[t[i].b].push_back(t[i].a),ans.push_back(t[i].ind+1);
    }
    for(i=1;i<=n;i++)if(!vis[i])dfs2(i);
    if(!fail)bes=ans;
    return !fail;
}
int main(){
    int i;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&t[i].a,&t[i].b,&t[i].c);
        t[i].ind=i;
    }
    sort(t,t+m);
    int cur=0;
    for(i=1<<16;i;i>>=1){
        if(cur+i>m)continue;
        if(check(cur+i))cur+=i;
    }
    if(cur==m)printf("0 0");
    else{
        printf("%d %d\n",t[cur].c,bes.size());
        for(int x:bes)printf("%d ",x);
    }
}