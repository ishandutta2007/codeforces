#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const int mn=2e5+10;
int a[mn],b[mn];
vector<int>g[mn],gs[mn];
int num[mn];
int o[mn],l[mn],scc[mn],sct,ct;
bool vis[mn],ins[mn];
stack<int> s;
void dfs(int x){
    ins[x]=vis[x]=1;
    o[x]=l[x]=ct++;
    s.push(x);
    for(int y:g[x]){
        if(!vis[y])dfs(y),l[x]=min(l[x],l[y]);
        else if(ins[y])l[x]=min(l[x],o[y]);
    }
    if(l[x]==o[x]){
        while(s.size()&&s.top()!=x)ins[s.top()]=0,scc[s.top()]=sct,s.pop();
        ins[x]=0,scc[x]=sct++,s.pop();
    }
}
void dfs2(int x){
    vis[x]=1;
    for(int y:gs[x]){
        if(!vis[y])dfs2(y);
    }
    num[x]=ct++;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    FOR(i,0,n)scanf("%d",a+i);
    FOR(i,0,n)scanf("%d",b+i);
    FOR(i,0,n-1)g[a[i+1]].push_back(a[i]),g[b[i+1]].push_back(b[i]);
    FOR(i,1,n+1)if(!vis[i])dfs(i);
    FOR(i,1,n+1)for(int j:g[i])if(scc[i]!=scc[j])gs[scc[i]].push_back(scc[j]);
    FOR(i,0,sct)sort(gs[i].begin(),gs[i].end()),gs[i].erase(unique(gs[i].begin(),gs[i].end()),gs[i].end());
    if(sct<k)printf("NO");
    else{
        printf("YES\n");
        memset(vis,0,sizeof(vis));
        memset(num,-1,sizeof(num));
        ct=0;
        FOR(i,0,sct)if(!vis[i])dfs2(i);
        FOR(i,1,n+1)printf("%c",'a'+min(24+1,num[scc[i]]));
    }
}