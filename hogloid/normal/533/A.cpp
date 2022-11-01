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
struct range_add_range_max_handler{
  typedef int node;
  typedef int oper;
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
	static const int MAX_N=1100000;
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
  void set(int k,node a){//ONLY AFTER INITIALIZING
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
int h[500005];
vector<int> g[500005];
int m;
int ar[500005];
int par[500005];
bool used[500005];

int seek;
void prep(int v,int p){
  par[v]=p;
  for(auto to:g[v]){
    if(to!=p) prep(to,v);
  }
}

void dfs(int v,int from,int sign=1){
  int p=lower_bound(ar+from,ar+n,h[v],greater<int>())-ar;
  if(!used[v]){
    seg.update(p,n,-1*sign);
  }
  for(auto to:g[v]){
    if(to==par[v]) continue;
    dfs(to,p,sign);
  }
}
int main(){
  cin>>n;
  REP(i,n) scanf("%d",&h[i]);
  REP(i,n-1){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  prep(0,-1);
  cin>>m;
  REP(i,m) scanf("%d",&ar[i]);
  sort(ar,ar+m,greater<int>());

  priority_queue<pi> pq;
  pq.push(mp(h[0],0));

  while(!pq.empty()){
    pi cur=pq.top();
    if(cur.fr<ar[seek]){
      break;
    }else{
      ++seek;
      pq.pop();
      used[cur.sc]=1;
      for(auto to:g[cur.sc]){
        if(to!=par[cur.sc]) pq.push(mp(h[to],to));
      }
    }
    if(seek==m){
      puts("0");
      return 0;
    }
  }
  seg.init(m);
  REP(i,m) seg.set(i,0);
  for(int i=seek;i<m;++i) seg.update(i,m,1);
  dfs(0,0,1);

  while(!pq.empty()){
    pi cur=pq.top();pq.pop();
    int v=cur.sc;
    dfs(v,0,-1);
    h[v]=ar[seek];
    dfs(v,0,1);
    if(seg.query(0,m)<=0){
      printf("%d\n",ar[seek]-cur.fr);
      return 0;
    }
    dfs(v,0,-1);
    h[v]=cur.fr;
    dfs(v,0,1);
  }
  puts("-1");

  return 0;
}