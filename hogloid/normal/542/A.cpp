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

const int INF=1.05e9;
int n,m;
pair<pi,int> range[200005];
pair<pi,pi> ad[200005];
pi Rmax[200005];
pair<lint,pi> ans;
void solve1(){
  sort(range,range+n);
  Rmax[0]=mp(-INF,-1);
  REP(i,n){
    Rmax[i+1]=max(Rmax[i],mp(range[i].fr.sc,range[i].sc));
  }
  REP(i,m){
    int a=ad[i].fr.fr,b=ad[i].fr.sc,c=ad[i].sc.fr,id=ad[i].sc.sc;
    int p=lower_bound(range,range+n,mp(mp(a+1,-INF),0))-range;
    chmax(ans,mp((min(b,Rmax[p].fr)-a)*(lint)c,mp(Rmax[p].sc,id)));
  }
}
pair<pi,pi> event[400005];//((l,r),(c,id))
bool cmp(const pair<pi,pi>& a,const pair<pi,pi>& b){
  return mp(a.fr.sc,a.sc.fr)<mp(b.fr.sc,b.sc.fr);
}
struct handler{
  struct node{
    pi val;
    node(pi val=mp(0,0)):val(val){}
  };
  handler(){}
  static node def_node() { return node(mp(-INF,-INF));}
  static node merge(const node& a,const node& b){
    return node(max(a.val,b.val));
  }
};

template<class Handler>
struct segtree{
  typedef typename Handler::node node;
  static const int MAX_N=1100000;
  node val[MAX_N];
  int n;
  Handler hdl;
  void init(int n_,node *a=NULL){
    n=1;
    while(n<n_) n<<=1;
    REP(i,n*2) val[i]=hdl.def_node();
    if(a!=NULL){
      REP(i,n_) val[i+n-1]=a[i];
      for(int i=n-2;i>=0;--i) val[i]=Handler::merge(val[i*2+1],val[i*2+2]);
    }
  }
  void set(int k,node a){
    k+=n-1;
    val[k]=a;
    while(k>0){
      k=(k-1)/2;
      val[k]=hdl.merge(val[k*2+1],val[k*2+2]);
    }
  }
  node query(int a,int b,int i,int l,int r){
    if(a<=l && r<=b) return val[i];
    if(b<=l || r<=a) return hdl.def_node();
    int md=(l+r)>>1;
    return hdl.merge(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
  }
  node query(int a,int b){
    return query(a,b,0,0,n);
  }
};
segtree<handler> seg;

int xzip[400005];
void solve2(){
  REP(i,n) event[i]=mp(range[i].fr,mp(-1,range[i].sc));
  REP(i,m) event[i+n]=ad[i];
  int cnt=n+m;
  sort(event,event+cnt,cmp);
  REP(i,cnt) xzip[i]=event[i].fr.fr;
  sort(xzip,xzip+cnt);
  int zn=unique(xzip,xzip+cnt)-xzip;
  seg.init(zn);

  REP(i,cnt){
    pair<pi,pi>& e=event[i];
    int p=lower_bound(xzip,xzip+zn,e.fr.fr)-xzip;
    if(e.sc.fr==-1){
      seg.set(p,mp(e.fr.sc-e.fr.fr,e.sc.sc));
    }else{
      int p2=lower_bound(xzip,xzip+zn,e.fr.sc)-xzip;
      pi tmp=seg.query(p,p2).val;
      lint val=tmp.fr;
      val*=e.sc.fr;
      chmax(ans,mp(val,mp(tmp.sc,e.sc.sc)));
    }
  }
}

int main(){
  cin>>n>>m;
  REP(i,n){
    scanf("%d%d",&range[i].fr.fr,&range[i].fr.sc);
    range[i].sc=i;
  }
  REP(i,m){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    ad[i]=mp(mp(a,b),mp(c,i));
  }
  solve2();
  dump(ans);
  solve1();
  REP(i,n){
    swap(range[i].fr.fr,range[i].fr.sc);
    range[i].fr.fr*=-1;
    range[i].fr.sc*=-1;
  }
  REP(i,m){
    swap(ad[i].fr.fr,ad[i].fr.sc);
    ad[i].fr.fr*=-1;
    ad[i].fr.sc*=-1;
  }
  dump(ans);
  solve1();

  cout<<ans.fr<<endl;
  if(ans.fr==0) return 0;
  cout<<ans.sc.fr+1<<' '<<ans.sc.sc+1<<endl;
  return 0;
}