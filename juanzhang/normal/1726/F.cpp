#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}

#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define mem(x) memset((x),0,sizeof(x))

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef unsigned u32;
typedef unsigned uint;
typedef unsigned long long u64;

namespace orzjk{
  const int SZ=1e6;
  char buf[SZ],*p1=buf,*p2=buf;
  char nc(){
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,SZ,stdin),p1==p2)?EOF:*p1++;
  }
  char fub[SZ],*p3=fub,*p4=fub+SZ;
  void pc(char c){
    p3==p4&&(fwrite(fub,1,SZ,stdout),p3=fub);
    *p3++=c;
  }
  void flush(){
    fwrite(fub,1,p3-fub,stdout),p3=fub;
  }
}
using orzjk::nc;
using orzjk::pc;

//#define nc getchar
//#define pc putchar

int read(){
  int x=0,f=1;char c=nc();
  while(c<48)c=='-'&&(f=-1),c=nc();
  while(c>47)x=x*10+(c^48),c=nc();
  return x*f;
}
void write(int x){
  static char st[21];
  if(!x)return pc(48),void();
  char*p=st;
  if(x<0)x=-x,pc('-');
  for(;x;x/=10)*p++=x%10|48;
  do{
    pc(*--p);
  }while(p!=st);
}

//const int P=1e9+7;
const int P=998244353;
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=2e5+10;
int n,t,g[maxn],c[maxn],d[maxn];

#define mid ((l+r)>>1)

const int N=maxn*50;
int rt=1,tot=1;
int ls[N],rs[N];ll tag[N],val[N];

ll ask(int k,int l,int r,int pos){
  if(!k)return 0;
  if(l==r)return val[k];
  if(tag[k]!=-1){
    return tag[k]+(r-pos);
  }
  if(pos<=mid)return ask(ls[k],l,mid,pos);
  return ask(rs[k],mid+1,r,pos);
}
void push(int&k,ll x){
  if(!k){
    k=++tot,tag[k]=x,val[k]=x;
  }else{
    tag[k]=val[k]=x;
  }
}
void upd(int&k,int l,int r,int ql,int qr,ll x){
  if(!k){
    k=++tot,tag[k]=-1,val[k]=0;
  }
//  printf("#%d : (%d %d) (%d %d) %lld\n",k,l,r,ql,qr,x);
  if(ql<=l&&r<=qr){
    tag[k]=x,val[k]=x;return;
  }
  if(tag[k]!=-1){
    push(ls[k],tag[k]+r-mid);
    push(rs[k],tag[k]);
    tag[k]=-1;
  }
  if(qr<=mid)upd(ls[k],l,mid,ql,qr,x);
  else if(ql>mid)upd(rs[k],mid+1,r,ql,qr,x);
  else{
    if(ql<=mid)upd(ls[k],l,mid,ql,qr,x+min(qr,r)-mid);
    if(qr>mid)upd(rs[k],mid+1,r,ql,qr,x);
  }
  val[k]=min(val[ls[k]],val[rs[k]]);
}
void upd(int l,int r,ll x){
//  printf("[%d %d, %lld]\n",l,r,x);
  upd(rt,0,t-1,l,r,x);
//  if(l<r){
//    upd(rt,0,t-1,l,r-1,1e16);
//  }
//  upd(rt,0,t-1,r,r,x);
}
void print(){
//  rep(i,0,t-1)printf("%lld%c",ask(1,0,t-1,i),"\n "[i<iend]);
}

#undef mid

void solve(){
  n=read(),t=read();
  rep(i,1,n){
    g[i]=read(),c[i]=read();
  }
  rep(i,1,n-1)d[i]=read();
  ll dt=0;
  rep(i,2,n){
    dt+=d[i-1];
    c[i]=(c[i]+dt)%t;
  }
  tag[rt]=-1,val[rt]=0;
//  int shift=0;
  per(i,n,1){
    ll tp=ask(rt,0,t-1,(t-c[i])%t);
    if(g[i]-c[i]>=0){
      upd(g[i]-c[i],t-c[i]-1,tp+1);
    }else{
      upd(0,t-c[i]-1,tp+1);
      upd(t-c[i]+g[i],t-1,tp+t-c[i]+1);
    }
    print();
//    return;
  }
  cout<<val[rt]+dt<<endl;
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}