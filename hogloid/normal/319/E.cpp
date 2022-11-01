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
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
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

const int INF=1e9+5;
struct uf{
  static const int MAXN=100005;
  int par[MAXN];
  int size[MAXN];
  void init(){
    memset(par,-1,sizeof(par));
    REP(i,MAXN) size[i]=1;
  }
  int root(int a){
    if(par[a]==-1) return a;
    return par[a]=root(par[a]);
  }
  void unite(int a,int b){
    a=root(a);b=root(b);
    if(a==b) return;
    par[b]=a;
    size[a]+=size[b];
  }
  bool same(int a,int b){
    return root(a)==root(b);
  }
};

uf u;


int n;
pair<int,pi> eve[100005];
int zip[200005],zn;


pi range[100005];

struct segtree{
  int n;
  vector<int> cover[550000];
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
  }
  void merge(int i,int l,int r,int p,int id){
    if(!(l<=p && p<r)) return;
    for(auto e:cover[i]){
      int p=u.root(e);
      chmin(range[id].fr,range[p].fr);
      chmax(range[id].sc,range[p].sc);
      u.unite(id,e);
    }
    cover[i].clear();
    if(r-l==1) return;
    int md=(l+r)>>1;
    merge(i*2+1,l,md,p,id);
    merge(i*2+2,md,r,p,id);
  }
  void insert(int a,int b,int i,int l,int r,int id){
    if(a<=l && r<=b){
      cover[i].pb(id);
      return;
    }
    if(b<=l || r<=a) return;
    int md=(l+r)>>1;
    insert(a,b,i*2+1,l,md,id);
    insert(a,b,i*2+2,md,r,id);
  }
};
segtree seg;

int main(){
  u.init();

  cin>>n;
  REP(i,n){
    int t,x,y;scanf("%d%d%d",&t,&x,&y);
    eve[i]=mp(t,mp(x,y));
    zip[zn++]=x;
    zip[zn++]=y;
  }
  zip[zn++]=-INF;
  zip[zn++]=INF;
  sort(zip,zip+zn);
  zn=unique(zip,zip+zn)-zip;
  seg.init(zn);

  int id=0;
  REP(i,n){
    int t=eve[i].fr,x=eve[i].sc.fr,y=eve[i].sc.sc;
    if(t==1){
      x=lower_bound(zip,zip+zn,x)-zip;
      y=lower_bound(zip,zip+zn,y)-zip;
      range[id]=mp(x,y);
      seg.merge(0,0,seg.n,x,id);
      seg.merge(0,0,seg.n,y,id);
      x=range[id].fr,y=range[id].sc;
      seg.insert(x+1,y,0,0,seg.n,id);

      ++id;
    }else{
      --x;--y;
      x=u.root(x);y=u.root(y);
      bool ok=false;
      if(x==y || (range[y].fr<range[x].fr && range[x].fr<range[y].sc) ||
        (range[y].fr<range[x].sc && range[x].sc<range[y].sc)) ok=true;
      puts(ok?"YES":"NO");
    }
  }
  return 0;
}