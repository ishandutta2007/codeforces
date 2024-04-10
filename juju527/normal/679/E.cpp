#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int n,Q;
ll pw[15];
ll a[maxn],b[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll mn[maxn<<2],laz[maxn<<2],tag[maxn<<2][2],mnx[maxn<<2];
void build(int k,int l,int r){
    tag[k][0]=-1;
    if(l==r){
        mn[k]=pw[b[l]]-a[l];
        mnx[k]=a[l];
        return ;
    }
    int mid=l+((r-l)>>1);
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    mn[k]=min(mn[k<<1],mn[k<<1|1]);
    mnx[k]=min(mnx[k<<1],mnx[k<<1|1]);
    return ;
}
void add_laz(int k,ll v){
    laz[k]+=v;
    mn[k]-=v;
    mnx[k]+=v;
    return ;
}
void add_tag(int k,ll v,int w){
    tag[k][0]=v;tag[k][1]=w;mn[k]=pw[w]-v;mnx[k]=v;
    laz[k]=0;
    return ;
}
void pushdown(int k){
    if(tag[k][0]==-1&&laz[k]==0)return ;
    if(tag[k][0]!=-1){
        add_tag(k<<1,tag[k][0],tag[k][1]);
        add_tag(k<<1|1,tag[k][0],tag[k][1]);
        tag[k][0]=-1;
    }
    if(laz[k]){
        add_laz(k<<1,laz[k]);
        add_laz(k<<1|1,laz[k]);
        laz[k]=0;
    }
    return ;
}
void modify(int k,int l,int r,int x,int y,int v,int w){
    if(l>y||r<x)return ;
    if(l>=x&&r<=y){
        add_tag(k,v,w);
        return ;
    }
    int mid=l+((r-l)>>1);
    pushdown(k);
    modify(k<<1,l,mid,x,y,v,w);
    modify(k<<1|1,mid+1,r,x,y,v,w);
    mn[k]=min(mn[k<<1],mn[k<<1|1]);
    mnx[k]=min(mnx[k<<1],mnx[k<<1|1]);
    return ;
}
ll query(int k,int l,int r,int x){
    if(l==r)return mnx[k];
    int mid=l+((r-l)>>1);
    pushdown(k);
    if(x<=mid)return query(k<<1,l,mid,x);
    return query(k<<1|1,mid+1,r,x);
}
bool flag=0;
void dfs(int k,int l,int r,int x,int y,int v){
    if(l>y||r<x)return ;
    if(l>=x&&r<=y){
        if(mn[k]>v){add_laz(k,v);return ;}
        else if(tag[k][0]!=-1){            
            int w=0;
            ll val=tag[k][0]+v+laz[k];
            while(pw[w]<val)w++;
            add_tag(k,val,w);
            if(mn[k]==0)flag=1;
            return ;
        }
    }
    if(l==r){
        int w=0;
        mnx[k]+=v;
        while(pw[w]<mnx[k])w++;
        mn[k]=pw[w]-mnx[k];
        if(!mn[k])flag=1;
        return ;
    }
    int mid=l+((r-l)>>1);
    pushdown(k);
    dfs(k<<1,l,mid,x,y,v);
    dfs(k<<1|1,mid+1,r,x,y,v);
    mn[k]=min(mn[k<<1],mn[k<<1|1]);
    mnx[k]=min(mnx[k<<1],mnx[k<<1|1]);
    return ;
}
int main(){
    pw[0]=1;
    for(int i=1;i<=11;i++)pw[i]=pw[i-1]*42ll;
    n=read();Q=read();
    for(int i=1;i<=n;i++){
        int x,w=0;
        x=read();
        while(pw[w]<x)w++;
        b[i]=w;a[i]=x;
    }
    build(1,1,n);
    while(Q--){
        int opt,l,r,x;
        opt=read();l=read();
        if(opt==1)printf("%lld\n",query(1,1,n,l));
        else if(opt==2){
            r=read();x=read();
            int w=0;
            while(pw[w]<x)w++;
            modify(1,1,n,l,r,x,w);
        }
        else{
            r=read();x=read();
            flag=0;
            dfs(1,1,n,l,r,x);
            while(flag){
                flag=0;
                dfs(1,1,n,l,r,x);
            }
        }
    }
    return 0;
}