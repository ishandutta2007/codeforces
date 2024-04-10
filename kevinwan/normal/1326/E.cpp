#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
const int mn=3e5+10;
const ll inf=0x3f3f3f3f3f3f3f3f;
int p[mn],rp[mn],q[mn];
int seg[mn*4],laz[mn*4];
inline void prop(int x){
    if(!laz[x])return;
    seg[x]+=laz[x];
    if(x*2+1<mn*4){
        laz[x*2]+=laz[x];
        laz[x*2+1]+=laz[x];
    }
    laz[x]=0;
}
inline void eval(int x){
    prop(x*2),prop(x*2+1);
    seg[x]=min(seg[x*2],seg[x*2+1]);
}
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int a,int b,int c){
    if(l==a&&r==b)laz[x]+=c;
    else{
        prop(x);
        if(b<=mid)upd(x*2,l,mid,a,b,c);
        else if(a>mid)upd(x*2+1,mid+1,r,a,b,c);
        else upd(x*2,l,mid,a,mid,c),upd(x*2+1,mid+1,r,mid+1,b,c);
        eval(x);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",p+i),rp[p[i]]=i;
    for(int i=1;i<=n;i++)scanf("%d",q+i);
    for(int i=0,j=n+1;i<n;i++){
        if(i)upd(1,1,n,1,q[i],1);
        prop(1);
        while(seg[1]>=0)--j,upd(1,1,n,1,rp[j],-1),prop(1);
        printf("%d ",j);
    }
}