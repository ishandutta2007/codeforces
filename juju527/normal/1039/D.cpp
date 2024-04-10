#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
struct Edge{
    int to,nxt;
}e[2*maxn];
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
int dfsnum;
int dfn[maxn],rnk[maxn];
void dfs1(int x,int fa){
    dfn[x]=++dfsnum;
    rnk[dfsnum]=x;
    for(int i=head[x];i!=-1;i=e[i].nxt){
        int tmp=e[i].to;
        if(tmp==fa)continue;
        dfs1(tmp,x);
    }
    return ;
}
int k,s;
int mx[maxn];
void calc(){
    for(int i=n;i>=1;i--){
        int x=rnk[i];
        int mx1=0,mx2=0;
        for(int j=head[x];j!=-1;j=e[j].nxt){
            int tmp=e[j].to;
            if(dfn[tmp]<i)continue;
            if(mx1<mx[tmp])mx2=mx1,mx1=mx[tmp];
            else mx2=max(mx2,mx[tmp]);
        }
        if(mx1+mx2+1>=k)s++,mx[x]=0;
        else mx[x]=mx1+1;
    }
    return ;
}
int main(){
    n=read();
    memset(head,-1,sizeof(head));
    for(int i=1;i<n;i++){
        int u,v;
        u=read();v=read();
        add(u,v);
        add(v,u);
    }
    dfs1(1,0);
    int B=min(sqrt(n*17),1.0*n),lst=n;
    for(int i=1;i<=B;i++){
        k=i,s=0;
        calc();
        printf("%d\n",s);
        lst=s;
    }
    int pre=B;
    int l=B,r=n+1,mid;
    for(int i=lst;i>=1;i--){
        while(l+1<r){
            mid=l+((r-l)>>1);
            k=mid,s=0;
            calc();
            if(s<i)r=mid;
            else l=mid;
        }
        for(int j=pre+1;j<=l;j++)printf("%d\n",i);
        pre=l;r=n+1;
    }
    for(int i=pre+1;i<=n;i++)puts("0");
    return 0;
}