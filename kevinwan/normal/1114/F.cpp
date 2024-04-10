#include<bits/stdc++.h>
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1<<20;
ll seg[mn],laz[mn],in[301];
bitset<301> seg2[mn],laz2[mn];
bitset<301> pr,prf[301];
int n;
const ll mod=1e9+7;
ll po(ll x,ll b){
    ll ans=1;
    for(ll i=b;i;i>>=1,x=x*x%mod)if(i&1)ans=ans*x%mod;
    return ans;
}
ll inv(ll x){
    return po(x,mod-2);
}
void prop(int x,int l,int r){
    if(laz[x]==1)return;
    seg[x]=seg[x]*po(laz[x],r-l+1)%mod;
    seg2[x]|=laz2[x];
    if(x<mn>>1){
        laz[x*2]=laz[x*2]*laz[x]%mod;
        laz[x*2+1]=laz[x*2+1]*laz[x]%mod;
        laz2[x*2]|=laz2[x];
        laz2[x*2+1]|=laz2[x];
    }
    laz[x]=1;
    laz2[x].reset();
}
void calc(int x,int l,int r){
    prop(x*2,l,mid);
    prop(x*2+1,mid+1,r);
    seg[x]=seg[x*2]*seg[x*2+1]%mod;
    seg2[x]=seg2[x*2]|seg2[x*2+1];
}
void update(int x,int l,int r,int a,int b,ll c){
    prop(x,l,r);
    if(a==l&&b==r){
        laz[x]=laz[x]*c%mod;
        laz2[x]|=prf[c];
    }
    else{
        if(b<=mid)update(x*2,l,mid,a,b,c);
        else if(a>mid)update(x*2+1,mid+1,r,a,b,c);
        else update(x*2,l,mid,a,mid,c),update(x*2+1,mid+1,r,mid+1,b,c);
        calc(x,l,r);
    }
}
pair<ll,bitset<301>> query(int x,int l,int r,int a,int b){
    prop(x,l,r);
    if(a==l&&b==r){
        return {seg[x],seg2[x]};
    }
    else{
        if(b<=mid)return query(x*2,l,mid,a,b);
        else if(a>mid)return query(x*2+1,mid+1,r,a,b);
        auto aa=query(x*2,l,mid,a,mid),bb=query(x*2+1,mid+1,r,mid+1,b);
        return {aa.first*bb.first%mod,aa.second|bb.second};
    }
}
bitset<301> fact(int x){
    bitset<301> b;
    for(int j=2;j<=300;j++)if(x%j==0&&pr[j])b[j]=1;
    return b;
}
int main(){
    int q,i,j,x;
    scanf("%d%d",&n,&q);
    for(i=0;i<mn;i++)seg[i]=1,laz[i]=1;
    pr.set();

    for(i=2;i*i<=300;i++)if(pr[i])for(j=i*i;j<=300;j+=i)pr[j]=0;
    pr[0]=pr[1]=0;
    for(i=1;i<=300;i++)prf[i]=fact(i);
    for(i=1;i<=300;i++)in[i]=inv(i);
    for(i=1;i<=n;i++)scanf("%d",&x),update(1,1,n,i,i,x);
    char s[256];
    while(q--){
        int a,b,c;
        scanf(" %s",s);
        if(s[0]=='T'){
            scanf("%d%d",&a,&b);
            auto aa=query(1,1,n,a,b);
            for(i=2;i<=300;i++)if(aa.second[i])aa.first=aa.first*(i-1)%mod*in[i]%mod;
            printf("%lld\n",aa.first);
        }
        else{
            scanf("%d%d%d",&a,&b,&c);
            update(1,1,n,a,b,c);
        }
    }
}