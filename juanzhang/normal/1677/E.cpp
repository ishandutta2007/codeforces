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
void write(ll x){
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
int n,A[maxn],B[maxn],lef[maxn],rig[maxn],st[maxn];

vi fac[maxn];

int q;ll ans[maxn*5];
struct node{
  int l,r,x;
}Q[maxn*5];
vector<node>upds;

struct BIT{
  ll c[maxn];
  void add(int pos,ll x){
    for(;pos<=n;pos+=pos&-pos)c[pos]+=x;
  }
  ll query(int pos){
    ll res=0;for(;pos;pos&=pos-1)res+=c[pos];return res;
  }
}tr[4];

void ins(int l,int r,int v){
  if(l<1||r>n)return;
  upds.push_back({l,r,v});
}

int buk[105][105];

void add(node e){
  int l=e.l,r=e.r,x=e.x;
//  rep(i,1,l)rep(j,r,n)buk[i][j]+=x;
  tr[0].add(r,x);
  tr[1].add(r,x*r);
  tr[2].add(r,x*l);
  tr[3].add(r,1ll*x*l*r);
}
ll query(int l,int r){
  ll res=0;
//  rep(i,l,n)rep(j,1,r)res+=buk[i][j];
  res-=tr[0].query(r)*(l-1)*(r+1);
  res+=tr[1].query(r)*(l-1);
  res+=tr[2].query(r)*(r+1);
  res-=tr[3].query(r);
  return res;
}

void solve(){
  n=read(),q=read();
  rep(i,1,n)A[i]=read(),B[A[i]]=i;
  rep(i,1,q){
    Q[i].l=read(),Q[i].r=read(),Q[i].x=i;
  }
  sort(Q+1,Q+q+1,[](node P,node Q){
    return P.l>Q.l;
  });
  rep(i,1,n){
    rig[i]=n+1;
    for(int j=i;j<=n;j+=i)fac[j].push_back(i);
  }
  int top=0;
  rep(i,1,n){
    while(top&&A[st[top]]<A[i])rig[st[top--]]=i;
    lef[i]=st[top],st[++top]=i;
  }
  rep(pos,1,n){
    vector<pii>seg;
    for(int d:fac[A[pos]]){
      int p=B[d],q=B[A[pos]/d];
      if(p==q)continue;
      if(p<=lef[pos]||p>=rig[pos])continue;
      if(q<=lef[pos]||q>=rig[pos])continue;
      seg.push_back({min(pos,min(p,q)),max(pos,max(p,q))});
    }
    sort(ALL(seg),[](pii P,pii Q){
      return P.first<Q.first||(P.first==Q.first&&P.second>Q.second);
    });
    vector<pii>ano;
    for(pii p:seg){
      while(!ano.empty()&&ano.back().second>=p.second)ano.pop_back();
      ano.push_back(p);
    }
    ano.swap(seg);
//    if(pos<=3)continue;
//    printf("%d : ",pos);for(pii p:seg)printf("(%d %d) ",p.first,p.second);puts("");
    if(seg.empty())continue;
    ins(seg.back().first,seg[0].second,1);
    ins(seg.back().first,rig[pos],-1);
    ins(lef[pos],seg[0].second,-1);
    ins(lef[pos],rig[pos],1);
    rep(i,1,seg.size()-1){
      ins(seg[i].first,seg[0].second,-1);
      ins(seg[i].first,seg[i].second,1);
      ins(seg[i-1].first,seg[0].second,1);
      ins(seg[i-1].first,seg[i].second,-1);
    }
  }
  sort(ALL(upds),[](node P,node Q){
    return P.l>Q.l;
  });
  for(int i=1,j=0;i<=q;i++){
    for(;j<(int)upds.size()&&upds[j].l>=Q[i].l;j++){
      add(upds[j]);
    }
    ans[Q[i].x]=query(Q[i].l,Q[i].r);
  }
  rep(i,1,q)write(ans[i]),pc(10);
}

signed main(){
//  freopen(".in","r",stdin);
//  freopen(".out","w",stdout);
//  int T;cin>>T;while(T--)solve();
  solve();
  orzjk::flush();
  return 0;
}