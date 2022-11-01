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

//const int INF=5e8;


int n,q;
typedef vector<int> vi;
int prof[100005];
struct node{
  int sum;
  int L,R;
  int len;
  node(){
    sum=L=R=len=0;
  }
  node merge(const node& a){
    if(a.len==0) return *this;
    if(len==0) return a;
    node res;
    res.sum=sum+a.sum;
    if(R>0 && a.L>0) res.sum+=prof[R+a.L]-prof[R]-prof[a.L];
    if(len!=L) res.L=L;
    else res.L=len+a.L;
    if(a.len!=a.R) res.R=a.R;
    else res.R=a.R+R;
    res.len=a.len+len;
    return res;
  }
  void set(){
    L=R=len=1;
    sum=prof[1];
  }
  node flip(){
    node res=*this;
    swap(res.L,res.R);
    return res;
  }
};
struct segtree{
  vector<node> val;
  int n;
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    val.resize(n*2);
    REP(i,n_) val[i+n-1].len=1;
    for(int i=n-2;i>=0;--i) val[i]=val[i*2+1].merge(val[i*2+2]);
  }
  node query(int a,int b,int i,int l,int r){
    if(a<=l && r<=b){
      return val[i];
    }
    if(b<=l || r<=a) return node();
    int md=(l+r)>>1;
    node L=query(a,b,i*2+1,l,md),R=query(a,b,i*2+2,md,r);
    L=L.merge(R);
    return L;
  }
  void set(int k){
    k+=n-1;
    val[k].set();
    while(k>0){
      k=(k-1)/2;
      val[k]=val[k*2+1].merge(val[k*2+2]);
    }
  }
};

vector<int> g[100005];
int size[100005];
pair<pi,pi> query[100005];//((wei,id),(u,v))
struct chain{
  vi vs;
  int join;
  unordered_map<int,int> pos;
  segtree seg;
  
  void init(const vi&,int join_);
  chain(){};
  void enable(int v){
    int p=pos[v];
    seg.set(p);
  }
  node query(int v){
    return seg.query(0,pos[v]+1,0,0,seg.n);
  }
  node query(int l,int r){
    return seg.query(pos[l]+1,pos[r]+1,0,0,seg.n);
  }
};
chain* belong[100005];
chain parts[100005];
void chain::init(const vi& a,int join_){
  debug(ALL(a));
  seg.init(a.size());
  vs=a;
  join=join_;
  for(auto v:vs) belong[v]=this;
  REP(i,a.size()) pos[a[i]]=i;
  debug(ALL(pos));
  dump(pos.size());
}

int cnt;
int dep[100005];
int prep(int v,int p){
  size[v]=1;
  for(auto e:g[v]){
    if(e==p) continue;
    dep[e]=dep[v]+1;
    size[v]+=prep(e,v);
  }
  return size[v];
}
void rec(int v,int p,vector<int>& prev,int join){
  prev.pb(v);
  pi maxi=mp(-1,-1);
  dump(v);
  for(auto e:g[v]){
    if(e!=p) chmax(maxi,mp(size[e],e));
  }
  if(maxi.fr==-1){
    parts[cnt++].init(prev,join);
    prev.clear();
  }else{
    rec(maxi.sc,v,prev,join);
  }
  for(auto e:g[v]){
    if(e!=p && e!=maxi.sc) rec(e,v,prev,v);
  }
}
pair<int,pi> es[100005];
int ans[100005];
int main(){
  cin>>n>>q;
  REP(i,n-1) scanf("%d",&prof[i+1]);
  REP(i,n-1){
    int u,v,w;scanf("%d%d%d",&u,&v,&w);--u;--v;
    dump(u);dump(v);

    g[u].pb(v);
    g[v].pb(u);
    es[i]=mp(w,mp(u,v));
  }
  sort(es,es+n-1);
  reverse(es,es+n-1);

  REP(i,q){
    int u,v,w;scanf("%d%d%d",&u,&v,&w);--u;--v;
    dump(u);dump(v);
    query[i]=mp(mp(w,i),mp(u,v));
  }

  prl;
  prep(0,-1);
  prl;
  dep[n]=-114514;
  vector<int> tmpp;
  rec(0,-1,tmpp,n);
  prl;

  sort(query,query+q);
  reverse(query,query+q);
  dump(cnt);

  REP(i,n) dump(belong[i]->join);

  int j=0;
  REP(i,q){
    pair<pi,pi> cur=query[i];
    int u=cur.sc.fr,v=cur.sc.sc;
    while(j<n-1 && es[j].fr>=cur.fr.fr){
      int u=es[j].sc.fr,v=es[j].sc.sc;
      if(dep[u]>dep[v]) swap(u,v);
      dump(v);
      belong[v]->enable(v);
      ++j;
    }
    prl;
    dump(u);dump(v);

    node up,down;
    while(belong[u]!=belong[v]){
      dump(u);dump(v);
      if(dep[belong[u]->join]>dep[belong[v]->join]){
        up=up.merge(belong[u]->query(u).flip());
        u=belong[u]->join;
      }else{
        down=belong[v]->query(v).merge(down);
        v=belong[v]->join;
      }
    }
    if(dep[u]<dep[v]){
      down=belong[v]->query(u,v).merge(down);
    }else if(dep[u]>dep[v]){
      up=up.merge(belong[u]->query(v,u).flip());
    }
    up=up.merge(down);
    dump(up.sum);dump(up.L);dump(up.R);
    ans[cur.fr.sc]=up.sum;
  }
  REP(i,q) printf("%d\n",ans[i]);
  return 0;
}