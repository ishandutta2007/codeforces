#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct Edge{int to,w,nxt;}e[4*maxn];
int cnt;
int head[2*maxn];
int d[2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v,int w){
    e[cnt]=(Edge){v,w,head[u]};
    head[u]=cnt++;
    return ;
}
int res[maxn];
bool vis[4*maxn];
void dfs(int x){
    for(int &i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to,w=e[i].w,id=i;
        if(vis[i])continue;
        vis[i]=vis[i^1]=1;
        dfs(tmp);
        res[w]=(id&1);
        if(i==-1)break;
    }
    return ;
}
int main(){
    int n;
    n=read();
    memset(head,-1,sizeof(head));
    int b=200000;
    for(int i=1;i<=n;i++){
        int u,v;
        u=read();v=read();
        add(u,v+b,i),add(v+b,u,i);
        d[u]++;d[v+b]++;
    }
    int pre=0,m=n;
    for(int i=1;i<=2*b;i++){
        if(d[i]%2==0)continue;
        if(!pre){pre=i;continue;}
        add(pre,i,0),add(i,pre,0);
        m++;
        pre=0;
    }
    for(int i=1;i<=2*b;i++)dfs(i);
    for(int i=1;i<=n;i++)if(res[i])printf("b");else printf("r");
    return 0;
}