#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e6+10;
ll a[mn],dp[mn],sum[mn];
int ls[mn],ln[mn];
struct nd{
    nd*l=NULL,*r=NULL;
    ll v=0;
};
nd* seg[mn];
#define mid (l+r>>1)
ll qu(nd*n,int l,int r,int a,int b){
    if(!n)return 0;
    else if(l==a&&r==b)return n->v;
    else{
        if(b<=mid)return qu(n->l,l,mid,a,b);
        else if(a>mid)return qu(n->r,mid+1,r,a,b);
        else return (qu(n->l,l,mid,a,mid)+qu(n->r,mid+1,r,mid+1,b))%mod;
    }
}
nd* pupd(nd*n,int l,int r,int a,ll b){
    nd*m=new nd();
    *m=*n;
    if(l==r)m->v=(m->v+b)%mod;
    else{
        if(!(m->l))m->l=new nd();
        if(!(m->r))m->r=new nd();
        if(a<=mid)m->l=pupd(m->l,l,mid,a,b);
        else m->r=pupd(m->r,mid+1,r,a,b);
        m->v=(m->l->v+m->r->v)%mod;
    }
    return m;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lld",a+i);
        ln[i]=ls[a[i]];
        ls[a[i]]=i;
    }
    seg[0]=new nd();
    dp[0]=1;
    seg[1]=pupd(seg[0],1,mn,1,1);
    for(i=1;i<=n;i++){
        dp[i]=(qu(seg[i],1,mn,1,a[i])-qu(seg[ln[i]],1,mn,1,a[i]))*a[i]%mod;
        seg[i+1]=pupd(seg[i],1,mn,a[i],dp[i]);
    }
    ll ans=seg[n+1]->v-1;
    if(ans<0)ans+=mod;
    printf("%lld",ans);
}