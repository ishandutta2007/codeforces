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
const int N=405,M=250005;
int n,m,ps[N],s,t,C,r,f[N];
inline bool check(ll V){
    static int q[N],hd,tl;
    f[s]=0;
    q[hd=tl=1]=s;
    for(ri coe,i=s+1;i<=t;++i){
        while(hd<=tl&&(ll)(ps[i]-ps[q[hd]])*C>V)++hd;
        coe=hd>tl?1e9:f[q[hd]];
        if(i==t)return coe<=r;
        f[i]=coe+1;
        while(hd<=tl&&f[q[tl]]>=f[i])--tl;
        q[++tl]=i;
    }
}
struct Node{int a,b,c,d;}a[M];
int main(){
    srand(time(0));
    #ifdef ldxcaicai
    freopen("lx.in","r",stdin);
    #endif
    n=read(),m=read();
    for(ri i=1;i<=n;++i)ps[i]=read();
    for(ri i=1;i<=m;++i)a[i].a=read(),a[i].b=read(),a[i].c=read(),a[i].d=read();
    random_shuffle(a+1,a+m+1);
    ll res=0;
    for(ri i=1;i<=m;++i){
        s=a[i].a,t=a[i].b,C=a[i].c,r=a[i].d;
        if(check(res))continue;
        ll l=res+1,r=1e18,ress=1e18;
        while(l<=r){
            ll mid=l+r>>1;
            if(check(mid))ress=mid,r=mid-1;
            else l=mid+1;
        }
        res=ress;
    }
    cout<<res;
    return 0;
}