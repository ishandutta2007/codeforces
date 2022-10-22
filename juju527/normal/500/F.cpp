#include<bits/stdc++.h>
using namespace std;
const int maxn=4e3+5,maxa=2e4+5;
int n,p,w,q,m;
int c[maxn],h[maxn],t[maxn];
int b[maxa];
struct node{
    int id,b;
};
vector<node>que[maxa];
int ans[maxa];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
vector<int>upd[maxa<<2];
void modify(int k,int l,int r,int x,int y,int id){
    if(l>y||r<x)return ;
    if(l>=x&&r<=y){
        upd[k].push_back(id);
        return ;
    }
    int mid=l+((r-l)>>1);
    modify(k<<1,l,mid,x,y,id);
    modify(k<<1|1,mid+1,r,x,y,id);
    return ;
}
int f[16][maxn];
void solve(int k,int l,int r,int dep){
    if(dep)for(int j=0;j<=m;j++)f[dep][j]=f[dep-1][j];
    for(int i=0;i<upd[k].size();i++){
        int id=upd[k][i];
        for(int j=m;j>=c[id];j--)
            f[dep][j]=max(f[dep][j],f[dep][j-c[id]]+h[id]);
    }
    if(l==r){
        for(int i=0;i<que[l].size();i++)ans[que[l][i].id]=f[dep][que[l][i].b];
        return ;
    }
    int mid=l+((r-l)>>1);
    solve(k<<1,l,mid,dep+1);
    solve(k<<1|1,mid+1,r,dep+1);
    return ;
}
int main(){
    n=read();p=read();
    for(int i=1;i<=n;i++){
        c[i]=read(),h[i]=read(),t[i]=read();
        w=max(w,t[i]);
    }
    w+=p-1;
    for(int i=1;i<=n;i++)modify(1,1,w,t[i],t[i]+p-1,i);
    q=read();
    for(int i=1;i<=q;i++){
        int a,b;
        a=read();b=read();
        m=max(m,b);
        que[a].push_back((node){i,b});
    }
    solve(1,1,w,0);
    for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
    return 0;
}