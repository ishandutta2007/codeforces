#include<bits/stdc++.h>
using namespace std;
const int maxn=150005;
int b[maxn],f[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int mn[maxn<<2],laz[maxn<<2];
void add_laz(int k,int v){
    mn[k]+=v;laz[k]+=v;
    return ;
}
void pushdown(int k){
    if(!laz[k])return ;
    add_laz(k<<1,laz[k]);
    add_laz(k<<1|1,laz[k]);
    laz[k]=0;
    return ;
}
void modify(int k,int l,int r,int x,int y,int v){
    if(l>y||r<x)return ;
    if(l>=x&&r<=y){
        add_laz(k,v);
        return ;
    }
    int mid=l+((r-l)>>1);
    pushdown(k);
    modify(k<<1,l,mid,x,y,v);
    modify(k<<1|1,mid+1,r,x,y,v);
    mn[k]=min(mn[k<<1],mn[k<<1|1]);
    return ;
}
int main(){
    int n,len,h;
    n=read();len=read();h=read();
    for(int i=1;i<=len;i++)b[i]=read();
    sort(b+1,b+len+1);
    for(int i=1;i<=n;i++)modify(1,1,len,i,i,-i);
    int ans=0;
    for(int i=1;i<=n;i++){
        int v;
        v=read();
        f[i]=lower_bound(b+1,b+len+1,h-v)-b;
        modify(1,1,len,f[i],len,1);
        if(i>=len){
            if(mn[1]>=0)ans++;
            modify(1,1,len,f[i-len+1],len,-1);
        }
    }
    printf("%d\n",ans);
    return 0;
}