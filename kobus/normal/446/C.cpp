#include <bits/stdc++.h>
 
using namespace std;

#define int long long
#define MAXN 312345
#define MOD 1000000009

struct node{
    int sum;
    int lzyf;
    int lzys;
};

int v[MAXN];
node seg[4*MAXN];

node newnode(){
    node no;
    no.sum=0;
    no.lzyf=0;
    no.lzys=0;
    return no;
}

int fib[MAXN];

void initfib(){
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<MAXN;i++)
        fib[i]=(fib[i-1]+fib[i-2])%MOD;
}

int nth(int f,int s,int n){
    if(n==0)return f;
    if(n==1)return s;
    return (f*fib[n-2]+s*fib[n-1])%MOD;   
}

int sumn(int f,int s,int n){
    if(n==0)return f;
    return (nth(f,s,n+2)-nth(f,s,1)+MOD)%MOD;
}

void clean(int u){
    seg[u].sum%=MOD;
    seg[u].lzyf%=MOD;
    seg[u].lzys%=MOD;
}

void unlazy(int u,int l,int r){
    if(seg[u].lzyf==0 && seg[u].lzys==0)return;
    if(l==r)seg[u].sum+=seg[u].lzyf;
    else{
        seg[u].sum+=sumn(seg[u].lzyf,seg[u].lzys,r-l);
        seg[2*u].lzyf+=seg[u].lzyf;
        seg[2*u].lzys+=seg[u].lzys;
        seg[2*u+1].lzyf+=nth(seg[u].lzyf,seg[u].lzys,(r-l)/2+1);
        seg[2*u+1].lzys+=nth(seg[u].lzyf,seg[u].lzys,(r-l)/2+2);
        clean(2*u);
        clean(2*u+1);
    }
    seg[u].lzyf=0;
    seg[u].lzys=0;
    clean(u);

}

void init(int u, int l, int r){
    seg[u]=newnode();
    if(l==r){seg[u].sum=v[l];return;}
    init(2*u,l,(l+r)/2);
    init(2*u+1,(l+r)/2+1,r);
    seg[u].sum=seg[2*u].sum+seg[2*u+1].sum;
    clean(u);
}

int query(int u,int l, int r,int ql, int qr){
    unlazy(u,l,r);
    if(r<ql||l>qr)return 0;
    if(l>=ql&&r<=qr)return seg[u].sum;
    return (query(2*u,l,(l+r)/2,ql,qr)+query(2*u+1,(l+r)/2+1,r,ql,qr))%MOD;
}

void update(int u,int l, int r,int ul, int ur, int fi,int se){
    unlazy(u,l,r);
    if(r<ul||l>ur)return;
    if(l>=ul&&r<=ur){
        seg[u].lzyf+=nth(fi,se,l-ul);
        seg[u].lzys+=nth(fi,se,l-ul+1);
        clean(u);
        return;
    }
    update(2*u,l,(l+r)/2,ul,ur,fi,se);
    update(2*u+1,(l+r)/2+1,r,ul,ur,fi,se);
    unlazy(2*u,l,(l+r)/2); 
    unlazy(2*u+1,(l+r)/2+1,r);
    seg[u].sum=seg[2*u].sum+seg[2*u+1].sum;
    clean(u);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>v[i];
    initfib();
    init(1,0,n-1);
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        b--;c--;
        if(a==1)update(1,0,n-1,b,c,1,1);
        else cout<<query(1,0,n-1,b,c)<<endl;
        //for(int j=0;j<n;j++)cout<<query(1,0,n-1,j,j)<<" ";
        //cout<<endl;
    }

    return 0;
}