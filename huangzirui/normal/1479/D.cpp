#include<bits/stdc++.h>
#define Mid ((L+R)>>1)
#define ull unsigned long long
using namespace std;
const int maxn=300010;
struct edge{
    int next,to;
}e[maxn*2];
int head[maxn],len;
void add(int x,int y){
    e[++len]={head[x],y};
    head[x]=len;
}
int i,j,k,n,m,a[maxn];
ull Hash[maxn],seed;
ull Rand(){
    return seed=(seed<<7)^(seed>>11)^(seed>>13);
}
vector<int>V[maxn];
int sz[maxn],dfn[maxn],cnt;
namespace st{
    #define ls(x) (d[x].son[0])
    #define rs(x) (d[x].son[1])
    struct node{
        int son[2];
        ull Hash;
    }d[maxn*80];int Cnt=0;
    void update(int root){
        d[root].Hash=d[ls(root)].Hash^d[rs(root)].Hash;
    }
    int add(int root,int L,int R,int x,ull S){
        int now=++Cnt;
        d[now]=d[root];
        if(L==R){d[now].Hash^=S;}
        else{
            if(x<=Mid)ls(now)=add(ls(root),L,Mid,x,S);
            else rs(now)=add(rs(root),Mid+1,R,x,S);
            update(now);
        }return now;
    }
    int work(int r1,int r2,int L,int R,int l,int r){
        // cerr<<"work "<<r1<<' '<<r2<<' '<<L<<' '<<R<<' '<<l<<' '<<r<<' '<<d[r1].Hash<<' '<<d[r2].Hash<<endl;
        if(L==l && R==r){
            if((d[r1].Hash^d[r2].Hash)==0)return -1;
            if(L==R)return L;
            if(d[ls(r1)].Hash^d[ls(r2)].Hash)return work(ls(r1),ls(r2),L,Mid,l,Mid);
            else return work(rs(r1),rs(r2),Mid+1,R,Mid+1,r);
        }else{
            if(r<=Mid)return work(ls(r1),ls(r2),L,Mid,l,r);
            else if(l>Mid)return work(rs(r1),rs(r2),Mid+1,R,l,r);
            else{
                int tmp=work(ls(r1),ls(r2),L,Mid,l,Mid);
                if(tmp<0)return work(rs(r1),rs(r2),Mid+1,R,Mid+1,r);
                else return tmp;
            }
        }
    }
}
int Root[maxn],Fa[maxn][21],deep[maxn];
void dfs(int now,int fa){
    Fa[now][0]=fa;deep[now]=deep[fa]+1;
    Root[now]=st::add(Root[fa],1,n,a[now],Hash[a[now]]);
    // cerr<<a[now]<<' '<<Hash[a[now]]<<endl;
    // cerr<<"dfs "<<now<<' '<<Root[now]<<' '<<st::d[Root[now]].Hash<<endl;
    for(int i=head[now];i;i=e[i].next){
        int u=e[i].to;
        if(u==fa)continue;
        dfs(u,now);
    }
}
void init(){
    for(int j=1;j<=20;j++)
        for(int i=1;i<=n;i++)
            Fa[i][j]=Fa[Fa[i][j-1]][j-1];
}
int lca(int x,int y){
    if(deep[x]<deep[y])swap(x,y);
    for(int j=20;j>=0;j--)
        if(deep[Fa[x][j]]>=deep[y])x=Fa[x][j];
    if(x==y)return x;
    for(int j=20;j>=0;j--)
        if(Fa[x][j]!=Fa[y][j])x=Fa[x][j],y=Fa[y][j];
    return Fa[x][0];
}
int main(){
    seed=84123123;Rand();Rand();Rand();
    cin>>n>>m;
    for(i=1;i<=n;i++)Hash[i]=Rand();
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    dfs(1,0);
    init();
    for(i=1;i<=m;i++){
        int x,y,l,r;
        scanf("%d%d%d%d",&x,&y,&l,&r);
        int z=lca(x,y);
        // cerr<<"x="<<x<<" y="<<y<<" z="<<z<<endl;
        int tmp=st::add(Root[y],1,n,a[z],Hash[a[z]]);
        int s=st::work(Root[x],tmp,1,n,l,r);
        if(s<0)puts("-1");
        else printf("%d\n",s);
    }
}