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

const int maxn=4e5+10;
int n,m,k;

vi E[maxn];
void addline(int u,int v){
  E[u].pb(v);
}

bool inq[maxn];
int scc,now,top,dfn[maxn],low[maxn],st[maxn],bl[maxn];
void tarjan(int u){
  dfn[u]=low[u]=++now,st[++top]=u,inq[u]=1;
  for(int v:E[u]){
    if(!dfn[v]){
      tarjan(v),chkmin(low[u],low[v]);
    }else if(inq[v]){
      chkmin(low[u],dfn[v]);
    }
  }
  if(low[u]==dfn[u]){
    int v=-1;scc++;
    while(v!=u){
      v=st[top--];
      inq[v]=0,bl[v]=scc;
    }
  }
}

void clear(){
  int tot=n*k*2;
  scc=now=top=0;
  rep(i,1,tot)E[i].clear(),dfn[i]=low[i]=st[i]=inq[i]=0;
}

#define f(i,x,chk) ((chk)*n*k+((i)-1)*k+(x))

void solve(){
  n=read(),m=read(),k=read();
  clear();
  rep(i,1,n){
    addline(f(i,1,0),f(i,1,1));
    rep(j,1,k-1){
      addline(f(i,j+1,1),f(i,j,1));
      addline(f(i,j,0),f(i,j+1,0));
    }
  }
  rep(i,1,n-1){
    rep(j,1,k){
      addline(f(i,j,1),f(i+1,j,1));
      addline(f(i+1,j,0),f(i,j,0));
    }
  }
  while(m--){
    int op=read(),u=read(),v,x;
    if(op==1){
      x=read();
      if(x==k){
        addline(f(u,x,1),f(u,x,0));
      }else{
        addline(f(u,x,1),f(u,x+1,1));
        addline(f(u,x+1,0),f(u,x,0));
      }
    }else{
      v=read(),x=read();
      if(op==2){
        rep(i,max(x-k+1,1),min(x,k)){
          addline(f(u,i,1),f(v,x-i+1,0));
          addline(f(v,i,1),f(u,x-i+1,0));
        }
        rep(i,x+1,k){
          addline(f(u,i,1),f(u,i,0));
          addline(f(v,i,1),f(v,i,0));
        }
      }else{
        rep(i,max(x-k+1,1),min(x,k)){
          addline(f(u,i,0),f(v,x-i+1,1));
          addline(f(v,i,0),f(u,x-i+1,1));
        }
        rep(i,1,x-k){
          addline(f(u,i,0),f(u,i,1));
          addline(f(v,i,0),f(v,i,1));
        }
      }
    }
  }
  rep(i,1,n*k*2){
    if(!dfn[i])tarjan(i);
  }
  rep(i,1,n*k)if(bl[i]==bl[n*k+i]){
    write(-1),pc(10);return;
  }
  rep(i,1,n){
    int v=-1;
    rep(j,1,k){
      if(bl[f(i,j,0)]>bl[f(i,j,1)])v=j;
    }
    write(v),pc(32);
  }
  pc(10);
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
  int T;cin>>T;while(T--)solve();
//  solve();
  orzjk::flush();
  return 0;
}