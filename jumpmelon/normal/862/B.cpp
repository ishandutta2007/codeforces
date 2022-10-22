#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
struct ED
{
    int to,next;
}g[100005*2];int cnt,head[100005];
void Add(int x,int y){g[++cnt].to=y;g[cnt].next=head[x];head[x]=cnt;}
int tot[2];
void dfs(int x,int f,int d)
{
    tot[d]++; bool ok=0;
    for(int i=head[x];i;i=g[i].next)
        if(g[i].to!=f) dfs(g[i].to,x,d^1),ok=1;
}long long ans=0;
void dfs2(int x,int f,int d)
{
    int to=(f!=0);
    for(int i=head[x];i;i=g[i].next)
        if(g[i].to!=f)dfs2(g[i].to,x,d^1),to++;
    ans+=tot[d^1]-to;
}
int main()
{
    int n;scanf("%d",&n);
    for(int u,v,i=1;i<n;i++)
        scanf("%d%d",&u,&v),Add(u,v),Add(v,u);
    dfs(1,0,0);
    dfs2(1,0,0); ans/=2; cout<<ans<<endl;
    return 0;
}