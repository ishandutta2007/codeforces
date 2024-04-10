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
const lint INF=1e18;
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
struct range_add_range_max_handler{
  typedef lint node;
  typedef lint oper;
  range_add_range_max_handler(){}
  static node def_node() { return -INF;}
  static node merge(const node& a,const node& b){
    return max(a,b);
  }
  static node apply(const node& a,const oper& b){
    return a+b;
  }
  static oper def_oper(){ return 0;}
  static oper push(const oper& a,const oper& b){
    return a+b;
  }
};

typedef range_add_range_max_handler handler;
template<class Handler>
struct segtree_lz{
  typedef typename Handler::node node;
  typedef typename Handler::oper oper;
  static const int MAX_N=550000;
  node val[MAX_N];
  oper lazy[MAX_N];
  int n;
  Handler hdl;
  void init(int n_,node *a=NULL){
    n=1;
    while(n<n_) n<<=1;
    REP(i,n*2) val[i]=hdl.def_node(),lazy[i]=hdl.def_oper();
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

  int find(int a,int b,int i,int l,int r,int v){
    if(val[i]<v || b<=l || r<=a) return -1;
    if(r-l==1) return l;
    push(i);
    int md=(l+r)>>1;
    int R=find(a,b,i*2+2,md,r,v);
    if(~R) return R;
    return find(a,b,i*2+1,l,md,v);
  }
};
//const int INF=5e8;

segtree_lz<handler> seg;


map<int,int> nxtp;
int N;
void doit(stack<int>& a,int sign,const int* ar){
  int p=a.top();a.pop();
  int nxt=a.top();
  seg.update(nxt,N,(ar[nxt]-ar[p])*sign);
  a.push(p);
}

pi solve(int n,const int* ar,int K){
  N=n;
  seg.init(n);
  nxtp.clear();
  REP(i,N) seg.set(i,i);
  stack<int> upper,lower;
  upper.push(n);
  lower.push(n);

  int fin=n;
  int len=-1;
  pi res=mp(N,0);
  for(int i=n-1;i>=0;--i){
    if(nxtp.count(ar[i])) chmin(fin,nxtp[ar[i]]);
    nxtp[ar[i]]=i;

    while(upper.size()>1 && ar[upper.top()]<=ar[i]){
      doit(upper,1,ar);
      upper.pop();
    }
    upper.push(i);
    doit(upper,-1,ar);
    while(lower.size()>1 && ar[lower.top()]>=ar[i]){
      doit(lower,-1,ar);
      lower.pop();
    }
    lower.push(i);
    doit(lower,1,ar);

    int R=seg.find(i,fin,0,0,seg.n,-K+i);

    if(~R && R-i+1>=len){
      len=R-i+1;
      res=mp(i,R);
    }
  }
  return res;
}
int n,k,d;
int ar[200005],tmp[200005];
int main(){
  cin>>n>>k>>d;
  REP(i,n) scanf("%d",&ar[i]);

  int mn=*min_element(ar,ar+n);
  REP(i,n) ar[i]-=mn;

  pi ans=mp(n,0);
  REP(i,n){
    int j=i;
    pi tmp;
    if(d==0){
      while(j<n && ar[j]==ar[i]) ++j;
      tmp=mp(i,j-1);
    }else{
      while(j<n && ar[j]%d==ar[i]%d) ++j;
      REPN(k,j,i) ar[k]=ar[k]/d;
      tmp=solve(j-i,ar+i,k);
      tmp.fr+=i;tmp.sc+=i;
    }
    if(ans.sc-ans.fr<tmp.sc-tmp.fr){
      ans=tmp;
    }
    i=j-1;
  }
  printf("%d %d\n",ans.fr+1,ans.sc+1);
  return 0;
}