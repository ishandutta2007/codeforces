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


#ifndef ONLINE_JUDGE
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

lint readL(){
  lint res;
#ifdef ONLINE_JUDGE
  scanf("%I64d",&res);
#else
  scanf("%lld",&res);
#endif
  return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
  printf("%I64d",res);
#else
  printf("%lld",res);
#endif
}


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

typedef Int_<1000000007> Int1;
typedef Int_<1000000009> Int2;
typedef Int_<1000000021> Int3;
typedef Int_<1000000033> Int4;

struct H{
  Int1 a;
  Int2 b;
  Int3 c;
  Int4 d;
  bool operator <(const H& X) const{
    if(a.x!=X.a.x) return a.x<X.a.x;
    if(b.x!=X.b.x) return b.x<X.b.x;
    if(c.x!=X.c.x) return c.x<X.c.x;
    return d.x<X.d.x;
  }
  H operator +(const H& X) const{
    return (H){a+X.a,b+X.b,c+X.c,d+X.d};
  }
  H operator *(const H& X) const{
    return (H){a*X.a,b*X.b,c*X.c,d*X.d};
  }
};

//const int INF=5e8;
int n;
vector<int> g[100005];
const lint mod=1000000007;

H var[100005],hashh[100005],phashh[100005];
int dep[100005],pdep[100005];
map<H,int> memo;
int app;
void add(H a){
  memo[a]++;
  if(memo[a]==1) ++app;
}
void del(H a){
  memo[a]--;
  if(memo[a]==0) --app;
  assert(memo[a]>=0);
}

H unit=(H){1,1,1,1};
void dfs(int v,int p){
  dep[v]=0;
  for(auto to:g[v]){
    if(to==p) continue;
    dfs(to,v);
    chmax(dep[v],dep[to]+1);
  }
  hashh[v]=unit;
  for(auto to:g[v]){
    if(to==p) continue;
    hashh[v]=hashh[v]*(var[dep[v]]+hashh[to]);
  }
  if(v) add(hashh[v]);
  dump(v);
  dump(hashh[v].a);
  dump(hashh[v].b);
  dump(hashh[v].c);
  dump(hashh[v].d);
}

H inv(H x){
  return (H){x.a.inv(),x.b.inv(),x.c.inv(),x.d.inv()};
}

int val[100005];
void dfs2(int v,int p){
  val[v]=app;
  pi mxi={-1,-1},sec={-1,-1};
  if(~p){
    mxi={pdep[v],p};
  }
  
  for(auto to:g[v]){
    if(to==p) continue;
    if(mxi.fr<dep[to]){
      sec=mxi;
      mxi={dep[to],to};
    }else if(sec.fr<dep[to]){
      sec={dep[to],to};
    }
  }
  H X=var[mxi.fr+1],Y=var[sec.fr+1];

  H allX=unit,allY=unit;
  if(~p){
    allX=phashh[v]+X;
    allY=phashh[v]+Y;
  }
  for(auto to:g[v]) if(to!=p){
    allX=allX*(hashh[to]+X);
    allY=allY*(hashh[to]+Y);
  }
  for(auto to:g[v]){
    if(to==p) continue;
    if(mxi.sc==to){
      H tmp=allY*inv(hashh[to]+Y);
      phashh[to]=tmp;
      pdep[to]=sec.fr+1;
    }else{
      H tmp=allX*inv(hashh[to]+X);
      phashh[to]=tmp;
      pdep[to]=mxi.fr+1;
    }
    dump(to);
    dump(phashh[to].a);
    dump(phashh[to].b);
    dump(phashh[to].c);
    dump(phashh[to].d);
    del(hashh[to]);
    dump(app);
    add(phashh[to]);
    dfs2(to,v);
    del(phashh[to]);
    add(hashh[to]);
  }
}

int main(){
  cin>>n;
  REP(i,n) var[i]=(H){rand(),rand(),rand(),rand()};
  var[0]=unit;
  REP(i,n-1){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0,-1);
  prl;
  dfs2(0,-1);



  debug(val,val+n);
  int res=max_element(val,val+n)-val;
  cout<<res+1<<endl;
  return 0;
}