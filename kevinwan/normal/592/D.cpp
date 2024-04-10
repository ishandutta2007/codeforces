#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mn=2e5+10;
bool u[mn];
vector<int> g[mn];
int dep[mn],lo[mn],ind[mn],le;
pii ans[mn];
void dfs(int x,int p){
    lo[x]=dep[x];
    ind[x]=x;
    for(int y:g[x]){
        if(y==p)continue;
        dep[y]=dep[x]+1;
        dfs(y,x);
        u[x]|=u[y];
        if(lo[y]>lo[x]||(lo[y]==lo[x]&&ind[y]<ind[x]))
            ind[x]=ind[y],lo[x]=lo[y];
    }
    if(!u[x]){
        lo[x]=0xc0c0c0c0;
        return;
    }
    pii bes,sec;
    bes={dep[x],-x};
    sec={0xc0c0c0c0,0};
    le++;
    for(int y:g[x]){
        if(y==p)continue;
        pii cont={lo[y],-ind[y]};
        if(cont>bes)sec=bes,bes=cont;
        else if(cont>sec)sec=cont;
    }
    ans[x]={bes.first+sec.first-dep[x]*2,max(bes.second,sec.second)};
    if(ans[x]<make_pair(0,-x))ans[x]={0,-x};
}
int main()
{
    int n,m,a,b,i;
    cin>>n>>m;
    for(i=0;i<n-1;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(i=0;i<m;i++){
        cin>>a;
        u[a]=1;
    }
    dfs(a,0);
    pii pr=ans[a];
    for(i=1;i<=n;i++)if(u[i])pr=max(pr,ans[i]);
    printf("%d\n%d",-pr.second,le*2-2-pr.first);
}