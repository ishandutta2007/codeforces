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

const int INF=5e8;

struct range_add_range_min_handler{
  typedef int node;
  typedef int oper;
  range_add_range_min_handler(){}
  static node def_node() { return INF;}
  static node merge(const node& a,const node& b){
    return min(a,b);
  }
  static node apply(const node& a,const oper& b){
    return a+b;
  }
  static oper def_oper(){ return 0;}
  static oper push(const oper& a,const oper& b){
    return a+b;
  }
};

typedef range_add_range_min_handler handler;
template<class Handler>
struct segtree_lz{
  typedef typename Handler::node node;
  typedef typename Handler::oper oper;
  static const int MAX_N=400005;
  node val[MAX_N];
  oper lazy[MAX_N];
  int n;
  Handler hdl;
  void init(int n_,node *a=NULL){
    n=1;
    while(n<n_) n<<=1;
    REP(i,n*2) val[i]=0,lazy[i]=hdl.def_oper();
    if(a!=NULL){
      REP(i,n_) val[i+n-1]=a[i];
      for(int i=n-2;i>=0;--i) val[i]=hdl.merge(val[i*2+1],val[i*2+2]);
    }
  }
  void set(int k,node a){//ONLY WHEN AFFECT TO K = 0
    k+=n-1;
    val[k]=a;
    while(k>0){
      k=(k-1)/2;
      val[k]=hdl.merge(val[k*2+1],val[k*2+2]);
    }
  }
  void push(int i){
    lazy[i*2+1]=hdl.push(lazy[i*2+1],lazy[i]);
    lazy[i*2+2]=hdl.push(lazy[i*2+2],lazy[i]);
    val[i*2+1]=hdl.apply(val[i*2+1],lazy[i]);
    val[i*2+2]=hdl.apply(val[i*2+2],lazy[i]);
    lazy[i]=hdl.def_oper();
  }
  void update(int a,int b,int i,int l,int r,oper v){
    if(a<=l && r<=b){
      val[i]=hdl.apply(val[i],v);
      lazy[i]=hdl.push(lazy[i],v);
      return;
    }
    if(b<=l || r<=a) return;
    int md=(l+r)>>1;
    push(i);
    update(a,b,i*2+1,l,md,v);
    update(a,b,i*2+2,md,r,v);
    val[i]=hdl.merge(val[i*2+1],val[i*2+2]);
  }
  void update(int a,int b,oper v){
    update(a,b,0,0,n,v);
  }
  node query(int a,int b,int i,int l,int r){
    if(a<=l && r<=b) return val[i];
    if(b<=l || r<=a) return hdl.def_node();
    push(i);
    int md=(l+r)>>1;
    return hdl.merge(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
  }
  node query(int a,int b){
    return query(a,b,0,0,n);
  }
};

segtree_lz<handler> seg;


int n;
pi eve[100005];
int ar[100005];
int tot;
int solve(){
  int lb=-1,ub=n;
  while(ub-lb>1){
    int md=(lb+ub)>>1;
    if(seg.query(md,n)>=tot) ub=md;
    else lb=md;
  }
  if(lb==-1 && tot<=0) return -1;
  return ar[lb+1];
}
int main(){
  cin>>n;
  REP(i,n){
    int p,t,x;
    scanf("%d%d",&p,&t);--p;
    if(t==1) scanf("%d",&x);
    else x=-1;
    eve[i]={p,x};
  }
  seg.init(n+1);

  REP(i,n){
    int p=eve[i].fr,x=eve[i].sc;
    if(x==-1){
      seg.update(p,n,-1);
      --tot;
    }else{
      seg.update(p,n,1);
      ar[p]=x;
      ++tot;
    }
    printf("%d\n",solve());
  }




  return 0;
}