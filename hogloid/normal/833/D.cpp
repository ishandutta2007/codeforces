#define DEB
#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

const int INF=5e8;
struct BIT{
  static const int MAXN=100005;
  int val[MAXN*8+2];
  int n;
  int off,tot;
  void init(int n_){
    off=n_*2;
    n_*=4;
    tot=0;
    n=1;
    while(n<n_) n<<=1;
    REP(i,n+1) val[i]=0;
  }
  void add(int k,int a){
    k+=off;
    ++k;
    tot+=a;
    while(k<=n){
      val[k]+=a;
      k+=k&-k;
    }
  }
  int query(int k){ //[-inf,k)
    k+=off;
    int res=0;
    while(k>0){
      res+=val[k];
      k-=k&-k;
    }
    return res;
  }
};

template<lint mod>
struct Int_{
  unsigned x;
  unsigned mpow(Int_ a,unsigned k){
    Int_ res=1;
    while(k){
      if(k&1) res=res*a;
      a=a*a;
      k>>=1;
    }
    return res.x;
  }
  unsigned inverse(Int_ a){
    return mpow(a,mod-2);
  }
  Int_(): x(0) { }
  Int_(long long sig) {
    int sigt=sig%mod;
    if(sigt<0) sigt+=mod;
    x=sigt;
  }
  unsigned get() const { return (unsigned)x; }

  Int_ &operator+=(Int_ that) { if((x += that.x) >= mod) x -= mod; return *this; }
  Int_ &operator-=(Int_ that) { if((x += mod - that.x) >= mod) x -= mod; return *this; }
  Int_ &operator*=(Int_ that) { x = (unsigned long long)x * that.x % mod; return *this; }
  Int_ &operator=(Int_ that) { x=that.x; return *this;}
  Int_ &operator/=(Int_ that) { x=(unsigned long long) x * inverse(that.x)%mod; return *this;}
  bool operator==(Int_ that) const { return x==that.x; }
  bool operator!=(Int_ that) const { return x!=that.x; }

  Int_ operator-() const { return Int_(0)-Int_(*this);}
  Int_ operator+(Int_ that) const { return Int_(*this) += that; }
  Int_ operator-(Int_ that) const { return Int_(*this) -= that; }
  Int_ operator*(Int_ that) const { return Int_(*this) *= that; }
  Int_ operator/(Int_ that) const { return Int_(*this) /= that; }
  Int_ inv(){
    return Int_(mpow(x,mod-2));
  }
};

namespace std{
  template<lint mod>
  ostream &operator <<(ostream& out,const Int_<mod>& a){
    out<<a.get();
    return out;
  }
  template<lint mod>
  istream &operator >>(istream& in,Int_<mod>& a){
    in>>a.x;
    return in;
  }
};

typedef Int_<1000000007> Int;

Int mpow(Int a,lint k){
  Int res=1;
  while(k){
    if(k&1) res=res*a;
    a=a*a;
    k>>=1;
  }
  return res;
}
static const int MAX_N=100005;

vector<pair<int,pi> > g[MAX_N];
int n;
int cut[MAX_N],sizee[MAX_N],whole;
int root,rcost;
int getsizee(int v,int p){
  sizee[v]=1;
  REP(i,g[v].size()){
    int to=g[v][i].fr;
    if(to!=p && cut[to]==0) sizee[v]+=getsizee(to,v);
  }
  return sizee[v];
}
void getbestroot(int v,int p){
  int maxi=0;
  REP(i,g[v].size()){
    int to=g[v][i].fr;
    if(to!=p && cut[to]==0){
      getbestroot(to,v);
      maxi=max(maxi,sizee[to]);
    }
  }
  int rest=whole-sizee[v];
  maxi=max(maxi,rest);
  if(maxi<rcost){
    rcost=maxi;
    root=v;
  }
}
BIT bit1,bit2;

Int ans;

void dfs2(int v,int p,int a,int b,Int sum){
  int na=bit1.query(-(2*a-b))+bit2.query(-(2*b-a));
  int appl=bit1.tot-na;
  ans*=mpow(sum,appl);

  for(auto e:g[v]){
    if(e.fr==p || cut[e.fr]) continue;
    dfs2(e.fr,v,a+(e.sc.sc==0?1:0),b+(e.sc.sc==1?1:0),sum*e.sc.fr);
  }
}
void dfs3(int v,int p,int a,int b){
  bit1.add(2*a-b,1);
  bit2.add(2*b-a,1);
  for(auto e:g[v]){
    if(e.fr==p || cut[e.fr]) continue;
    dfs3(e.fr,v,a+(e.sc.sc==0?1:0),b+(e.sc.sc==1?1:0));
  }
}
void dfs(int v){
  getsizee(v,-1);
  if(sizee[v]==1) return;
  whole=sizee[v];
  rcost=INF;
  getbestroot(v,-1);
  v=root;

  REP(t,2) {
    bit1.init(rcost);
    bit2.init(rcost);

    if(t==0){
      bit1.add(0,1);
      bit2.add(0,1);
    }

    for (auto e:g[v]) {
      int to = e.fr;
      if (!cut[to]) {
        dfs2(to, v, (e.sc.sc ? 0 : 1), (e.sc.sc ? 1 : 0), e.sc.fr);//compute
        dfs3(to, v, (e.sc.sc ? 0 : 1), (e.sc.sc ? 1 : 0));//add
      }
    }
    reverse(ALL(g[v]));
  }

  cut[v]=1;
  REP(i,g[v].size()){
    int to=g[v][i].fr;
    if(cut[to]==0) dfs(to);
  }
  cut[v]=0;
}


int main(){
#ifdef LOCAL_REDIR
  freopen("/home/hog/Dropbox/pg/working/in.txt","r",stdin);
#endif
  cin>>n;
  REP(i,n-1){
    int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);--a;--b;
    g[a].pb({b,{c,d}});
    g[b].pb({a,{c,d}});
  }
  ans=1;
  dfs(0);

  cout<<ans<<endl;
  return 0;
}