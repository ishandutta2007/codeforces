#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=4e5+10;
vector<int>g[mn],ind[mn];
pii ans[mn];
bool vis[mn],ins[mn];
int o[mn],l[mn],scc[mn];
int ct,sct;
stack<int>s;
void dfs(int x,int p){
    o[x]=l[x]=ct++;
    ins[x]=vis[x]=1;
    s.push(x);
    for(int y:g[x]){
        if(y==p)continue;
        if(!vis[y])dfs(y,x),l[x]=min(l[x],l[y]);
        else if(ins[y])l[x]=min(l[x],o[y]);
    }
    if(o[x]==l[x]){
        while(s.top()!=x)scc[s.top()]=sct,ins[s.top()]=0,s.pop();
        scc[s.top()]=sct++,ins[s.top()]=0,s.pop();
    }
}
vector<int>slave[mn];
void dfs2(int x,int p){
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i],in=ind[x][i];
        if(y==p)continue;
        if(!vis[y])dfs2(y,x);
        if(!ans[in].first)ans[in]={x,y};
    }
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
        ind[a].push_back(i);
        ind[b].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)slave[scc[i]].push_back(i);
    int mo=0;
    for(int i=1;i<sct;i++)if(slave[i].size()>slave[mo].size())mo=i;
    memset(vis,0,sizeof(vis));
    dfs2(slave[mo][0],0);
    printf("%d\n",slave[mo].size());
    for(int i=0;i<m;i++){
        printf("%d %d\n",ans[i].second,ans[i].first);
    }
}