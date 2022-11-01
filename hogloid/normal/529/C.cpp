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

const int INF=5e8;
int h,w,k,q;
pi ps[200005];
pair<pi,pi> rect[200005];
bool ok[200005];

bool tmpok[200005];
struct segtree{
  int val[800005];
  int n;
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    CLR(val);
  }
  void set(int k,int a){
    k+=n-1;
    val[k]=a;
    while(k>0){
      k=(k-1)/2;
      val[k]=max(val[k*2+1],val[k*2+2]);
    }
  }
  int query(int a,int b,int i,int l,int r){
    if(a<=l && r<=b) return val[i];
    if(b<=l || r<=a) return -INF;
    int md=(l+r)>>1;
    return max(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
  }
};
segtree seg;

struct ev{
  int y,id,type,ub,l,r,x;
};
ev event[400005];

bool cmp(const ev& a, const ev& b){
  if(a.y==b.y) return a.type<b.type;
  return a.y<b.y;
}
bool cmp2(const pi&a ,const pi&b){
  return mp(a.sc,a.fr)<mp(b.sc,b.fr);
}
vector<int> cols[200005];

void solve(){
  seg.init(w+2);
  REP(i,w+2) cols[i].clear();
  REP(i,k) cols[ps[i].sc].pb(ps[i].fr);
  REP(i,w+2){
    sort(ALL(cols[i])),cols[i].pb(INF);
    seg.set(i,cols[i][0]);
  }
  int m=0;
  REP(i,q){
    tmpok[i]=true;
    event[m++]=(ev){rect[i].fr.fr,i,0,rect[i].sc.fr+1,rect[i].fr.sc,rect[i].sc.sc+1,-1};
  }
  REP(i,k){
    event[m++]=(ev){ps[i].fr,-1,1,-1,-1,-1,ps[i].sc};
  }
  sort(event,event+m,cmp);

  REP(i,m){
    ev e=event[i];
    if(e.type==0){
      if(seg.query(e.l,e.r,0,0,seg.n)>=e.ub) tmpok[e.id]=0;
    }else{
      int nxt=*(upper_bound(ALL(cols[e.x]),e.y));
      seg.set(e.x,nxt);
    }
  }
  REP(i,q) if(tmpok[i]) ok[i]=1;
}
int main(){
  cin>>h>>w>>k>>q;
  REP(i,k) scanf("%d%d",&ps[i].fr,&ps[i].sc);
  REP(i,q) scanf("%d%d%d%d",&rect[i].fr.fr,&rect[i].fr.sc,&rect[i].sc.fr,&rect[i].sc.sc);

  solve();
  swap(h,w);
  REP(i,k) swap(ps[i].fr,ps[i].sc);
  REP(i,q) swap(rect[i].fr.fr,rect[i].fr.sc),swap(rect[i].sc.fr,rect[i].sc.sc);
  solve();

  REP(i,q){
    if(ok[i]) puts("YES");
    else puts("NO");
  }
  return 0;
}