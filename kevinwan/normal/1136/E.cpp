#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int mn=1e5+10;
ll inf=0x3f3f3f3f3f3f3f3f;
ll a[mn],k[mn];
ll seg[mn*4],ma[mn*4],laz[mn*4],pk[mn];
void prop(int x,int l,int r){
    if(laz[x]==inf)return;
    seg[x]=laz[x]*(r-l+1);
    ma[x]=laz[x];
    if(l!=r){
        laz[x*2]=laz[x*2+1]=laz[x];
    }
    laz[x]=inf;
}
#define mid ((l+r)>>1)
void eval(int x,int l,int r){
    prop(x*2,l,mid),prop(x*2+1,mid+1,r);
    seg[x]=seg[x*2]+seg[x*2+1];
    ma[x]=max(ma[x*2],ma[x*2+1]);
}
void init(int x,int l,int r){
    if(l==r)seg[x]=ma[x]=a[l];
    else{
        init(x*2,l,mid),init(x*2+1,mid+1,r);
        eval(x,l,r);
    }
}
void upd(int x,int l,int r,int a,int b,ll c){
    if(l==a&&r==b)laz[x]=c;
    else{
        prop(x,l,r);
        if(b<=mid)upd(x*2,l,mid,a,b,c);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
        else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
        eval(x,l,r);
    }
}
int bs(int x,int l,int r,ll v){
    prop(x,l,r);
    if(l==r)return ma[x]>v?l-1:l;
    else{
        prop(x*2,l,mid);
        if(v>=ma[x*2])return bs(x*2+1,mid+1,r,v);
        else return bs(x*2,l,mid,v);
    }
}
ll qu(int x,int l,int r,int a,int b){
    prop(x,l,r);
    if(l==a&&r==b)return seg[x];
    else if(b<=mid)return qu(x*2,l,mid,a,b);
    else if(a>mid)return qu(x*2+1,mid+1,r,a,b);
    else return qu(x*2,l,mid,a,mid)+qu(x*2+1,mid+1,r,mid+1,b);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",a+i);
    for(int i=2;i<=n;i++)scanf("%lld",k+i),k[i]+=k[i-1],a[i]-=k[i],pk[i]=pk[i-1]+k[i];
    memset(laz,inf,sizeof(laz));
    init(1,1,n);
    int q;
    scanf("%d",&q);
    while(q--){
        char s[2];
        int a,b;
        scanf("%s%d%d",s,&a,&b);
        if(s[0]=='+'){
            ll v=qu(1,1,n,a,a);
            int r=bs(1,1,n,v+b);
            upd(1,1,n,a,r,v+b);
        }
        else{
            printf("%lld\n",qu(1,1,n,a,b)+pk[b]-pk[a-1]);
        }
    }
}