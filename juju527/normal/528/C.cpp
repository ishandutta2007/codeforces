#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxm=2e5+5,maxM=5e5+5;
struct Edge{int to,nxt;}e[2*maxM];
int cnt;
int head[maxn];
bool d[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void add(int u,int v){
    e[cnt]=(Edge){v,head[u]};
    head[u]=cnt++;
    return ;
}
bool vis[2*maxM];
int len;
int p[maxM][2];
void dfs(int x){
    for(int &i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(vis[i])continue;
        vis[i]=vis[i^1]=1;
        dfs(tmp);
        p[++len][0]=x;p[len][1]=tmp;
        if(i==-1)break;
    }
    return ;
}
int main(){
    int n,m;
    n=read();m=read();
    memset(head,-1,sizeof(head));
    for(int i=1;i<=m;i++){
        int u,v;
        u=read();v=read();
        d[u]^=1;d[v]^=1;
        add(u,v),add(v,u);
    }
    int num=0,pre=0;
    for(int i=1;i<=n;i++){
        if(!d[i])continue;
        if(!pre){pre=i;continue;}
        add(pre,i),add(i,pre);
        m++;
        pre=0;
    }
    if(m&1)add(1,1),add(1,1);
    dfs(1);
    printf("%d\n",len);
    for(int i=1;i<=len;i++){
        if(i&1)swap(p[i][0],p[i][1]);
        printf("%d %d\n",p[i][0],p[i][1]);
    }
    return 0;
}