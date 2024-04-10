#include <bits/stdc++.h>
using namespace std;
const int mn=1e3+10;
int en[mn],nxt[mn],w[mn][mn],acc[mn],sec[mn];
vector<int>g[mn];
vector<int>aa,bb,cc;
void die(int x,int a,int b,int c,int d){
    if(nxt[b]==x)b=sec[b];
    if(nxt[c]==x)c=sec[c];
    aa.push_back(en[b]);
    bb.push_back(en[c]);
    cc.push_back(-d/2);
    aa.push_back(en[a]);
    bb.push_back(en[b]);
    cc.push_back(d/2);
    aa.push_back(en[a]);
    bb.push_back(en[c]);
    cc.push_back(d/2);
}
void dfs(int x,int p){
    for(int y:g[x]){
        if(y==p)continue;
        if(!nxt[x])nxt[x]=y;
        else if(!sec[x])sec[x]=y;
        dfs(y,x);
    }
    if(g[x].size()==1)en[x]=x;
    else en[x]=en[nxt[x]];
}
void dfs1(int x,int p){
    acc[nxt[x]]+=acc[x];
    w[x][nxt[x]]-=acc[x];
    for(int y:g[x]){
        if(y==p)continue;
        if(y==g[x][0])die(x,y,g[x][1],g[x][2],w[x][y]);
        else if(y==g[x][1])die(x,y,g[x][0],g[x][2],w[x][y]);
        else die(x,y,g[x][0],g[x][1],w[x][y]);
        acc[y]+=w[x][y];
        dfs1(y,x);
    }
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        g[a].push_back(b);
        g[b].push_back(a);
        w[a][b]=w[b][a]=d;
    }
    if(n==2){
        printf("YES\n1\n1 2 %d",w[1][2]);
        return 0;
    }
    for(i=1;i<=n;i++)if(g[i].size()==2){
        printf("NO");
        return 0;
    }
    for(i=1;i<=n;i++)if(g[i].size()!=1)break;
    dfs(i,0);
    dfs1(i,0);
    printf("YES\n%d\n",aa.size());
    for(i=0;i<aa.size();i++)printf("%d %d %d\n",aa[i],bb[i],cc[i]);
}