#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int h[maxn],b[maxn],pos[maxn];
ll f[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
stack<int>s;
ll mx[maxn<<2],mxf[maxn<<2],laz[maxn<<2];
void pushup(int k){
    mx[k]=max(mx[k<<1],mx[k<<1|1]);
    mxf[k]=max(mxf[k<<1],mxf[k<<1|1]);
    return ;
}
void add_laz(int k,int val){
    laz[k]=val;
    mx[k]=mxf[k]+val;
    return ;
}
void pushdown(int k){
    if(laz[k]==inf)return ;
    add_laz(k<<1,laz[k]);
    add_laz(k<<1|1,laz[k]);
    laz[k]=inf;
    return ;
}
void build(int k,int l,int r){
    mx[k]=mxf[k]=-inf,laz[k]=inf;
    if(l==r)return ;
    int mid=l+((r-l)>>1);
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    return ;
}
void modify1(int k,int l,int r,int x,ll val){
    if(l==r){
        mx[k]=mxf[k]=val;
        return ;
    }
    int mid=l+((r-l)>>1);
    pushdown(k);
    if(x<=mid)modify1(k<<1,l,mid,x,val);
    else modify1(k<<1|1,mid+1,r,x,val);
    pushup(k);
    return ;
}
void modify2(int k,int l,int r,int x,int y,int val){
    if(l>y||r<x)return ;
    if(l>=x&&r<=y){
        add_laz(k,val);
        return ;
    }
    int mid=l+((r-l)>>1);
    pushdown(k);
    modify2(k<<1,l,mid,x,y,val);
    modify2(k<<1|1,mid+1,r,x,y,val);
    pushup(k);
    return ;
}
ll query(int k,int l,int r,int x,int y){
    if(l>y||r<x)return -inf;
    if(l>=x&&r<=y)return mx[k];
    int mid=l+((r-l)>>1);
    pushdown(k);
    return max(query(k<<1,l,mid,x,y),query(k<<1|1,mid+1,r,x,y));
}
int main(){
    int n;
    n=read();
    for(int i=1;i<=n;i++){
        h[i]=read();
        while(!s.empty()&&h[i]<h[s.top()])s.pop();
        if(!s.empty())pos[i]=s.top()+1;
        else pos[i]=1;
        s.push(i);
    }
    for(int i=1;i<=n;i++)b[i]=read();
    build(1,0,n);
    modify1(1,0,n,0,f[0]);
    for(int i=1;i<=n;i++){
        modify2(1,0,n,pos[i]-1,i-1,b[i]);
        f[i]=query(1,0,n,0,i-1);
        modify1(1,0,n,i,f[i]);
    }
    printf("%lld\n",f[n]);
    return 0;
}