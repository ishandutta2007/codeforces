#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct Edge{int to,nxt;}e[2*maxn];
int cnt;
int head[maxn];
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
int f[maxn],siz[maxn];
int d[maxn];
bool vis[maxn];
queue<int>q;
int leaf,bud;
void dfs(int x,int fa){
    f[x]=fa;
    siz[x]=1;
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(tmp==fa)continue;
        dfs(tmp,x);
        siz[x]+=siz[tmp];
        if(siz[tmp]>1)d[x]++;
    }
    if(siz[x]>1&&!d[x]){
        q.push(x);
        leaf+=siz[x]-1,vis[x]=1;
    }
    return ;
}
int main(){
    int T;
    T=read();
    while(T--){
        int n;
        n=read();
        cnt=0;
        for(int i=1;i<=n;i++)head[i]=-1,vis[i]=0;
        for(int i=1;i<n;i++){
            int u,v;
            u=read();v=read();
            add(u,v),add(v,u);
        }
        leaf=0,bud=0;
        dfs(1,0);
        while(q.size()){
            int k=q.front();
            q.pop();bud+=vis[k];
            int fa=f[k];
            if(fa)d[fa]--;
            if(fa&&!d[fa]){
                int son=0;
                for(int i=head[fa];i!=-1;i=e[i].nxt){
                    int tmp=e[i].to;
                    if(vis[tmp]||tmp==f[fa])continue;
                    son++;leaf++;
                }
                if(son)q.push(fa),vis[fa]=1;
                else q.push(fa);
            }
        }
        printf("%d\n",leaf-bud+1);
    }
    return 0;
}