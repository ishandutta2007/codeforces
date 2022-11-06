#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
    int ans=0;
    char ch=gc();
    while(!isdigit(ch))ch=gc();
    while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
    return ans;
}
inline ll readl(){
    ll ans=0;
    char ch=gc();
    while(!isdigit(ch))ch=gc();
    while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
    return ans;
}
inline int Read(char*s){
    int top=0;
    char ch=gc();
    while(!isalpha(ch))ch=gc();
    while(isalpha(ch))s[++top]=ch;
    return top;
}
namespace modular{
    int mod;
    inline int add(int a,int b){return (a+=b)<mod?a:a-mod;}
    inline int dec(int a,int b){return (a-=b)<0?a+mod:a;}
    inline int mul(int a,int b){return (ll)a*b%mod;}
    inline void Add(int&a,int b){a=add(a,b);}
    inline void Dec(int&a,int b){a=dec(a,b);}
    inline void Mul(int&a,int b){a=(ll)a*b%mod;}
    inline int ksm(int a,int p){int ret=1;for(;p;p>>=1,Mul(a,a))(p&1)&&(Mul(ret,a),1);return ret;}
}
using namespace modular;
const int N=6e5+5;
map<pii,int>vs;
int n,sum=0;
#define lc (p<<1)
#define rc (p<<1|1)
#define mid (l+r>>1)
vector<pii>upd[N<<2];
inline void update(int p,int l,int r,int ql,int qr,pii vl){
    if(ql<=l&&r<=qr){
        upd[p].pb(vl);
        return;
    }
    if(qr<=mid)update(lc,l,mid,ql,qr,vl);
    else if(ql>mid)update(rc,mid+1,r,ql,qr,vl);
    else update(lc,l,mid,ql,qr,vl),update(rc,mid+1,r,ql,qr,vl);
}
int fa[N],siz[N],ctx[N],cty[N];
ll ss=0,s5[N];
pii s1[N],s2[N],s3[N],s4[N];
int tp;
inline int find(int x){return x^fa[x]?find(fa[x]):x;}
inline void merge(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    if(siz[x]<siz[y])swap(x,y);
    ++tp;
    s5[tp]=ss;
    ss-=(ll)ctx[x]*cty[x];
    ss-=(ll)ctx[y]*cty[y];
    s1[tp]=pii(y,fa[y]),fa[y]=x;
    s2[tp]=pii(x,siz[x]),siz[x]+=siz[y];
    s3[tp]=pii(x,ctx[x]),ctx[x]+=ctx[y];
    s4[tp]=pii(x,cty[x]),cty[x]+=cty[y];
    ss+=(ll)ctx[x]*cty[x];
}
inline void delet(){
    fa[s1[tp].fi]=s1[tp].se;
    siz[s2[tp].fi]=s2[tp].se;
    ctx[s3[tp].fi]=s3[tp].se;
    cty[s4[tp].fi]=s4[tp].se;
    ss=s5[tp];
    --tp;
}
inline void solve(int p,int l,int r){
    int cur=tp;
    for(ri i=upd[p].size()-1;~i;--i)merge(upd[p][i].fi,upd[p][i].se);
    if(l==r){
        cout<<ss<<' ';
        while(cur^tp)delet();
        return;
    }
    solve(lc,l,mid),solve(rc,mid+1,r);
    while(cur^tp)delet();
}
#undef lc
#undef rc
#undef mid
int main(){
    srand(time(0));
    #ifdef ldxcaicai
    freopen("lx.in","r",stdin);
    #endif
    n=read();
    for(ri i=1,x,y;i<=n;++i){
        x=read(),y=read()+300000;
        if(!vs.count(pii(x,y)))vs[pii(x,y)]=i;
        else{
            update(1,1,n,vs[pii(x,y)],i-1,pii(x,y));
            vs.erase(pii(x,y));
        }
    }
    for(map<pii,int>::iterator it=vs.begin();it!=vs.end();++it)update(1,1,n,it->se,n,it->fi);
    for(ri i=1;i<=300000;++i){
        fa[i]=i,siz[i]=1; 
        fa[i+300000]=i+300000,siz[i+300000]=1;
        ctx[i]=1,cty[i+300000]=1;
    }
    solve(1,1,n);
    return 0;
}