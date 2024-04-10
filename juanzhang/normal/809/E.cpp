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

const int P=1e9+7;
//const int P=998244353;
int fix(int x){
  return x+(x>>31&P);
}
void Add(int&x,int y){
  x+=y-P,x+=x>>31&P;
}
int qp(int a,int k){
  int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;
}

const int maxn=2e5+10;

int n,tid[maxn];ll ans;

vi fac[maxn];
int ptt,pri[maxn],phi[maxn],mu[maxn],F[maxn];
void sieve(){
//  int n=1000;
  phi[1]=mu[1]=1;
  rep(i,2,n){
    if(!pri[i])pri[++ptt]=i,phi[i]=i-1,mu[i]=-1;
    rep(j,1,ptt){
      int x=i*pri[j];
      if(x>n)break;
      pri[x]=1;
      if(i%pri[j]==0){
        mu[x]=0;
        phi[x]=phi[i]*pri[j];
        break;
      }
      mu[x]=-mu[i];
      phi[x]=phi[i]*(pri[j]-1);
    }
  }
//  rep(i,1,n)printf("%d : %d\n",i,mu[i]);
  rep(i,1,n){
    int x=1ll*i*qp(phi[i],P-2)%P;
//    printf("!%d : %d\n",i,phi[i]);
    for(int j=i;j<=n;j+=i)F[j]=fix((F[j]+x*mu[j/i])%P),fac[j].push_back(i);
  }
//  rep(i,1,n)printf("$%d : %d\n",i,F[i]);
}

vi E[maxn];

bool vis[maxn];
int sumsz,sck,sz[maxn];
void dfs1(int u,int f){
  sumsz++;
  for(int v:E[u])if(v!=f&&!vis[v])dfs1(v,u);
}
void dfs2(int u,int f){
  sz[u]=1;int tp=0;
  for(int v:E[u])if(v!=f&&!vis[v]){
    dfs2(v,u),sz[u]+=sz[v],chkmax(tp,sz[v]);
  }
  chkmax(tp,sumsz-sz[u]);
  if(tp*2<=sumsz)sck=u;
}

vi vec[maxn];
int bl[maxn],dis[maxn];
void dfs3(int u,int f){
  dis[u]=dis[f]+1,vec[bl[u]].push_back(u);
  for(int v:E[u])if(v!=f&&!vis[v]){
    bl[v]=f?bl[u]:v,dfs3(v,u);
  }
}

struct cmp{
  bool operator()(int x,int y)const{
    return sz[x]>sz[y];
  }
};

void merge(int x,int y){
//  putchar('(');for(int i:vec[x])printf("%d ",i);putchar(')');putchar(' ');
//  putchar('(');for(int i:vec[y])printf("%d ",i);putchar(')');putchar('\n');
//  for(int i:vec[x])for(int j:vec[y])ans+=phi[i*j]*(dis[i]+dis[j]),printf("(%d %d) %d\n",i,j,phi[i*j]*(dis[i]+dis[j]));
//  rep(d,1,n){
//    int res=0;
//    for(int i:vec[x])if(i%d==0){
//      for(int j:vec[y])if(j%d==0){
//        res+=1ll*phi[i]*phi[j]%P*(dis[i]+dis[j])%P;
//      }
//    }
//    ans=(ans+1ll*F[d]*res)%P;
//  }
  static int clo,tim[maxn],S0[maxn],S1[maxn],T0[maxn],T1[maxn];
  for(int i:vec[x]){
    int v0=phi[i],v1=1ll*v0*dis[i]%P;
    for(int j:fac[i])Add(S0[j],v0),Add(S1[j],v1);
  }
  for(int i:vec[y]){
    int v0=phi[i],v1=1ll*v0*dis[i]%P;
    for(int j:fac[i])Add(T0[j],v0),Add(T1[j],v1);
  }
  clo++;
  auto upd=[&](int d){
    if(tim[d]!=clo)tim[d]=clo,ans=(ans+(1ll*S0[d]*T1[d]+1ll*S1[d]*T0[d])%P*F[d])%P,S0[d]=S1[d]=T0[d]=T1[d]=0;
  };
  for(int i:vec[x])for(int j:fac[i])upd(j);
  for(int i:vec[y])for(int j:fac[i])upd(j);
  for(int i:vec[y])vec[x].pb(i);
  vi ano;
  ano.swap(vec[y]),sz[x]+=sz[y];
}

void divide(int rt){
  sumsz=0,dfs1(rt,0),dfs2(rt,0);
  rt=sck;
//  fprintf(stderr,"%d : %d\n",rt,sumsz);
//  printf("#%d\n",rt);
  dis[0]=-1,bl[rt]=rt,dfs3(rt,0);
  priority_queue<int,vi,cmp>Q;
  auto dlc=[&](int u){
    sz[u]=vec[u].size(),Q.push(u);
  };
  dlc(rt);for(int v:E[rt])if(!vis[v])dlc(v);
  while(Q.size()>1u){
    int y=Q.top();Q.pop();
    int x=Q.top();Q.pop();
    merge(x,y);
    Q.push(x);
  }
  vec[Q.top()].clear();
  vis[rt]=1;
  for(int v:E[rt])if(!vis[v])divide(v);
}

void solve(){
  n=read();
  sieve();
  rep(i,1,n)tid[i]=read();
  rep(i,2,n){
    int u=tid[read()],v=tid[read()];
    E[u].pb(v),E[v].pb(u);
  }
//  cerr<<"GG"<<endl;
  divide(1);
//  printf("#%lld\n",ans);
  ans=2*ans%P*qp(1ll*n*(n-1)%P,P-2)%P;
  cout<<ans<<endl;
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}
/*
3
1 2 3
1 2
2 3

5
5 4 3 1 2
3 5
1 2
4 3
2 5
*/