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

typedef Int_<1000000007> Int_h;
static const int MAX_N=101005;
struct Hash{
  static Int_h M1,M2;
  static Int_h rev1,rev2;

  static Int_h mul1[MAX_N],mul2[MAX_N],
         div1[MAX_N],div2[MAX_N];

  typedef pair<Int_h,Int_h>key;
  static Hash pows[MAX_N];

  key a;
  static void init(){
    M1=2,M2=100000037;
    rev1=Int_h(1)/M1;
    rev2=Int_h(1)/M2;

    Int_h* ar[4]={mul1,mul2,div1,div2};
    Int_h mult[4]={M1,M2,rev1,rev2};
    REP(j,4){
      ar[j][0]=1;
      REP(i,MAX_N-1){
        ar[j][i+1]=ar[j][i]*mult[j];
      }
    }
    REP(i,MAX_N) pows[i].a=mp(mul1[i],mul2[i]);
  }
  Hash(lint val=0){
    a=mp(val,val);
  }
  Hash &operator+=(const Hash& b) { 
    a.fr+=b.a.fr;
    a.sc+=b.a.sc;

    return *this;
  }
  Hash &operator-=(const Hash& b) {
    a.fr-=b.a.fr;
    a.sc-=b.a.sc;

    return *this;
  }
  Hash &operator <<=(int k){
    a.fr*=mul1[k];
    a.sc*=mul2[k];
    return *this;
  }
  Hash &operator >>=(int k){
    a.fr*=div1[k];
    a.sc*=div2[k];
    return *this;
  }
  Hash &operator *=(int k){
    a.fr*=k;
    a.sc*=k;
    return *this;
  }
  Hash &operator =(Hash b){
    a=b.a;
    return *this;
  }
  Hash &operator =(lint val){
    a.fr=val;
    a.sc=val;
    return *this;
  }
  Hash operator -()const{
    return Hash(0)-=Hash(*this);
  }

  Hash operator +(const Hash& b) const{
    return Hash(*this)+=b;
  }
  Hash operator -(const Hash& b) const{
    return Hash(*this)-=b;
  }

  Hash operator *(int k) const{
    return Hash(*this)*=k;
  }

  Hash operator <<(int k) const{
    return Hash(*this)<<=k;
  }
  Hash operator >>(int k) const{
    return Hash(*this)>>=k;
  }

  bool operator==(const Hash& b) const { return (a==b.a); }
  bool operator!=(const Hash& b) const { return (a!=b.a); }
};

Int_h Hash::M1,Hash::M2;
Int_h Hash::rev1,Hash::rev2;
Int_h Hash::mul1[MAX_N],Hash::mul2[MAX_N],
         Hash::div1[MAX_N],Hash::div2[MAX_N];

Hash setall[MAX_N];
Hash Hash::pows[MAX_N];

typedef Int_<1000000007> Int;
const int INF=5e8;
int cnt;
struct node{
  node *lch,*rch;
  long long set:8;
  long long len:24;
  Hash val;
  node(){
    set=-1;
    val=0;
  }
  node *copy();
  void chk();
  void fill(int,int,int,int,int);
  int query(int,int,int);
};

node* cost[100005];
bool cmp2(const node* a,const node* b){
  if(a->val==b->val) return false;
  if(a->len==1) return a->val.a.fr.x>b->val.a.fr.x;

  if(a->set==1 || b->set==0) return true;
  if(a->set==0 || b->set==1) return false;

  if(a->rch==NULL) return false;
  if(b->rch==NULL) return true;
  if(a->rch->val!=b->rch->val) return cmp2(a->rch,b->rch);

  if(a->lch==NULL) return false;
  if(b->lch==NULL) return true;
  return cmp2(a->lch,b->lch);
}

typedef pair<int,node*> stat;
struct Compare : public binary_function<stat,stat,bool> {
  bool operator()(const stat &a, const stat&b) {
    return cmp2(a.sc,b.sc);
  }
};

node pool[32000005];


node* node::copy(){
  pool[cnt]=*this;
  assert(cnt<=32000000);
  return &pool[cnt++];
}
void node::chk(){
  if(lch==NULL){
    assert(cnt<=32000000);
    lch=&pool[cnt++];
    rch=&pool[cnt++];
    lch->len=rch->len=len/2;
  }else{
    lch=lch->copy();
    rch=rch->copy();
  }
  if(~set){
    lch->set=rch->set=set;
    lch->val=rch->val=setall[len/2]*set;
    set=-1;
  }
}
void node::fill(int a,int b,int l,int r,int v){
  //fill all
  if(a<=l && r<=b){
    set=v;
    val=setall[r-l]*v;
    return;
  }
  if(b<=l || r<=a) return;
  int md=(l+r)>>1;
  chk();

  lch->fill(a,b,l,md,v);
  rch->fill(a,b,md,r,v);

  val=(rch->val<<((r-l)/2))+lch->val;
}
int node::query(int a,int l,int r){
  if(r<=a || val==setall[r-l] || set==1) return INF;
  if(r-l==1) return l;
  //find next 0
  int md=(l+r)>>1;
  if(set==0) return max(a,l);
  if(a<md){
    if(lch==NULL) return max(a,l);
    int L=lch->query(a,l,md);
    if(L!=INF) return L;
  }
  if(rch==NULL) return max(a,md);
  return rch->query(a,md,r);
}

int n,m;
vector<pi> g[100005];

bool reach[100005],vis[100005];

int rev[100005];
int main(){
  Hash::init();
  prl;

  setall[0]=0;
  REP(i,MAX_N-1) setall[i+1]=(setall[i]<<1)+1;

  cin>>n>>m;
  int len=0;
  REP(i,m){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);
    --a;--b;
    chmax(len,c);
    g[a].pb(mp(b,c));
    g[b].pb(mp(a,c));
  }
  prl;
  int S,T;cin>>S>>T;--S;--T;

  len+=20;


  priority_queue<stat,vector<stat>,Compare> pq;
  pool[0].len=len;
  ++cnt;

  cost[S]=&pool[0];
  reach[S]=1;
  pq.push(mp(S,cost[S]));

  prl;
  while(!pq.empty()){
    int cur=pq.top().fr;
    node* seg=pq.top().sc;

    pq.pop();
    if(vis[cur]) continue;
    vis[cur]=1;
    dump(cur);
    dump(seg->val.a.fr);
    for(auto e:g[cur]){
      int to=e.fr,c=e.sc;
      node* nxt=seg->copy();
      int nxt0=nxt->query(c,0,len);
      dump(to);
      dump(c);
      dump(nxt0);
      if(c<nxt0) nxt->fill(c,nxt0,0,len,0);
      nxt->fill(nxt0,nxt0+1,0,len,1);
      if(!reach[to] || cmp2(cost[to],nxt)){
        cost[to]=nxt;
        reach[to]=1;
        rev[to]=cur;
        pq.push(mp(to,cost[to]));
      }
    }
  }

  if(!reach[T]) return puts("-1"),0;

  int res=cost[T]->val.a.fr.x;
  cout<<res<<endl;
  vector<int> path;
  int cur=T;
  while(cur!=S){
    path.pb(cur);
    cur=rev[cur];
  }
  path.pb(S);
  reverse(ALL(path));
  cout<<path.size()<<endl;
  for(auto v:path) printf("%d ",v+1);
  puts("");
  return 0;
}