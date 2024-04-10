#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
// #include<boost/multiprecision/cpp_int.hpp>
// namespace multiprecisioninteger = boost::multiprecision;
// using cint=multiprecisioninteger::cpp_int;
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using ddatas=pair<long double,long double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
// using llset=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define For(i,a,b) for(i=a;i<(ll)b;++i)
#define bFor(i,b,a) for(i=b,--i;i>=(ll)a;--i)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N,0)
#define brep1(i,N) bFor(i,N,1)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define uniq(v) vsort(v);(v).erase(unique(all(v)),(v).end())
#define endl "\n"
#define popcount __builtin_popcountll
#define eb emplace_back
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
constexpr ll mod=1000000007;
// constexpr ll mod=998244353;
constexpr ll inf=1LL<<60;
constexpr long double eps=1e-9;
const long double PI=acosl(-1);
template<class T,class E> ostream& operator<<(ostream& os,const pair<T,E>& p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& os,const vector<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> ostream& operator<<(ostream& os,const set<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> ostream& operator<<(ostream& os,const multiset<T>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T,class E> ostream& operator<<(ostream& os,const map<T,E>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> inline bool chmax(T& a,const T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,const T b){bool x=a>b;if(x)a=b;return x;}
#ifdef DEBUG
void debugg(){cout<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cout<<" "<<x;debugg(args...);}
#define debug(...) cout<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

inline void startupcpp(void) noexcept{
  cin.tie(0);
  ios::sync_with_stdio(false);
}
template<class Ver>
vector<Ver> diameter(const vector<vector<Ver>>& g){
  int N=g.size();
  Ver *dist,LIM=1<<30;
  dist=new Ver[N];
  fill(dist,dist+N,LIM);
  queue<Ver> que;
  que.emplace(dist[0]=0);
  while(!que.empty()){
    auto now=que.front();
    for(auto x:g[now]){
      if(dist[x]==LIM){
        dist[x]=dist[now]+1;
        que.emplace(x);
      }
    }
    que.pop();
  }
  Ver f=max_element(dist,dist+N)-dist;
  fill(dist,dist+N,LIM);
  dist[f]=0;
  que.emplace(f);
  Ver *par=new Ver[N];
  while(!que.empty()){
    auto now=que.front();
    for(auto x:g[now]){
      if(dist[x]==LIM){
        par[x]=now;
        dist[x]=dist[now]+1;
        que.emplace(x);
      }
    }
    que.pop();
  }
  Ver s=max_element(dist,dist+N)-dist;
  vector<Ver> res(dist[s]+1);
  res[0]=s;
  for(int i=0;i<dist[s];++i)res[i+1]=par[res[i]];
  delete[] par;
  delete[] dist;
  return res;
}

template<class S,S(*op)(S,S),S(*e)(),
        class F,S(*mapping)(S,F),F(*composition)(F,F),F(*id)()>
struct lazy_segtree{
public:
  lazy_segtree():lazy_segtree(0){}
  lazy_segtree(int n):lazy_segtree(vector<S>(n,e())){}
  lazy_segtree(const vector<S>& v):_n(int(v.size())){
    log=0;
    while((1U<<log)<(unsigned int)(_n))++log;
    size=1<<log;
    d=vector<S>(size<<1,e());
    lz=vector<F>(size,id());
    for(int i=0;i<_n;++i)d[size+i]=v[i];
    for(int i=size-1;i>=1;--i){
      update(i);
    }
  }

  void set(int p,S x){
    assert(0<=p&&p<_n);
    p+=size;
    for(int i=log;i>=1;--i)push(p>>i);
    d[p]=x;
    for(int i=1;i<=log;++i)update(p>>i);
  }

  S get(int p){
    assert(0<=p&&p<_n);
    p+=size;
    for(int i=log;i>=1;--i)push(p>>i);
    return d[p];
  }

  S prod(int l,int r){
    assert(0<=l&&l<=r&&r<=_n);
    if(l==r)return e();

    l+=size;
    r+=size;

    for(int i=log;i>=1;--i){
      if(((l>>i)<<i)!=l)push(l>>i);
      if(((r>>i)<<i)!=r)push(r>>i);
    }

    S sml=e(),smr=e();
    while(l<r){
      if(l&1)sml=op(sml,d[l++]);
      if(r&1)smr=op(d[--r],smr);
      l>>=1;
      r>>=1;
    }

    return op(sml,smr);
  }

  S all_prod(){return d[1];}

  void apply(int p,F f){
    assert(0<=p&&p<_n);
    p+=size;
    for(int i=log;i>=1;--i)push(p>>i);
    d[p]=mapping(d[p],f);
    for(int i=1;i<=log;++i)update(p>>i);
  }
  void apply(int l,int r,F f){
    assert(0<=l&&l<=r&&r<=_n);
    if(l==r)return;

    l+=size;
    r+=size;

    for(int i=log;i>=1;--i){
      if(((l>>i)<<i)!=l)push(l>>i);
      if(((r>>i)<<i)!=r)push((r-1)>>i);
    }

    {
      int l2=l,r2=r;
      while(l<r){
        if(l&1)all_apply(l++,f);
        if(r&1)all_apply(--r,f);
        l>>=1;
        r>>=1;
      }
      l=l2;
      r=r2;
    }

    for(int i=1;i<=log;++i){
      if(((l>>i)<<i)!=l)update(l>>i);
      if(((r>>i)<<i)!=r)update((r-1)>>i);
    }
  }

  template<bool(*g)(S)>int max_right(int l){
    return max_right(l,[](S x){return g(x);});
  }
  template<class G>int max_right(int l,G g){
    assert(0<=l&&l<=_n);
    assert(g(e()));
    if(l==_n)return _n;
    l+=size;
    for(int i=log;i>=1;--i)push(l>>i);
    S sm=e();
    do{
      while(~l&1)l>>=1;
      if(!g(op(sm,d[l]))){
        while(l<size){
          push(l);
          l<<=1;
          if(g(op(sm,d[l]))){
            sm=op(sm,d[l++]);
          }
        }
        return l-size;
      }
      sm=op(sm,d[l++]);
    }while((l&-l)!=l);
    return _n;
  }

  template<bool(*g)(S)>int min_left(int r){
    return min_left(r,[](S x){return g(x);});
  }
  template<class G>int min_left(int r,G g){
    assert(0<=r&&r<=_n);
    assert(g(e()));
    if(r==0)return 0;
    r+=size;
    for(int i=log;i>=1;--i)push((r-1)>>i);
    S sm=e();
    do{
      --r;
      while(r>>1&&(r&1))r>>=1;
      if(!g(op(d[r],sm))){
        while(r<size){
          push(r);
          r=r<<1|1;
          if(g(op(d[r],sm))){
            sm=op(d[r--],sm);
          }
        }
        return r+1-size;
      }
      sm=op(d[r],sm);
    }while((r&-r)!=r);
    return 0;
  }
  int _n;
private:
  int size,log;
  vector<S> d;
  vector<F> lz;

  void update(int k){d[k]=op(d[k<<1],d[k<<1|1]);}
  void all_apply(int k,F f){
    d[k]=mapping(d[k],f);
    if(k<size)lz[k]=composition(lz[k],f);
  }
  void push(int k){
    all_apply(k<<1,lz[k]);
    all_apply(k<<1|1,lz[k]);
    lz[k]=id();
  }
  friend ostream &operator<<(ostream &os,const lazy_segtree<S,op,e,F,mapping,composition,id> &p){
    lazy_segtree<S,op,e,F,mapping,composition,id> printout(p);
    for(int i=0;i<printout._n;++i){os<<"{,"[i>0]<<printout.prod(i,i+1);}
    os<<"}";
    return os;
  }
};
constexpr datas op(datas l,datas r){return datas(max(l.first,r.first),max(l.second,r.second));}
constexpr datas e(){return datas(0,0);}
constexpr datas mapping(datas x,ll f){
  if(f)swap(x.first,x.second);
  return x;
}
constexpr ll composition(ll f,ll g){return f^g;}
constexpr ll id(){return 0;}
using segtree=lazy_segtree<datas,op,e,ll,mapping,composition,id>;

ll N,Q;
vec chid,in,out;
pvec firstv;
struct edge{
  ll to,type,id;
  edge(){}
  edge(ll to,ll type,ll id):to(to),type(type),id(id){}
};
vector<vector<edge>> g;
void dfs(ll now,ll par=-1,ll dep=0,ll v=0){
  in[now]=firstv.size();
  if(v)firstv.emplace_back(dep,0);
  else firstv.emplace_back(0,dep);
  for(auto x:g[now]){
    if(x.to==par)continue;
    chid[x.id]=x.to;
    dfs(x.to,now,dep+1,v^x.type);
  }
  out[now]=firstv.size();
}
int main(){
  startupcpp();
  ll i,A,B;
  cin>>N;
  g.resize(N);
  chid.resize(N);
  in.resize(N);
  out.resize(N);
  {
    mat fg(N);
    rep1(i,N){
      ll C;
      cin>>A>>B>>C;
      --A;--B;
      fg[A].emplace_back(B);
      fg[B].emplace_back(A);
      g[A].emplace_back(B,C,i);
      g[B].emplace_back(A,C,i);
    }
    auto v=move(diameter(fg));
    A=v[0];B=v.back();
  }
  cin>>Q;
  vec query(Q),ans(Q,0);
  for(auto& x:query)cin>>x;
  dfs(A);
  segtree fsol(firstv);
  debug(in);
  debug(firstv);
  debug(chid);
  rep(i,Q){
    auto x=chid[query[i]];
    fsol.apply(in[x],out[x],1);
    ans[i]=fsol.all_prod().second;
  }
  firstv.clear();
  dfs(B);
  segtree ssol(firstv);
  debug(in);
  debug(firstv);
  debug(chid);
  rep(i,Q){
    auto x=chid[query[i]];
    ssol.apply(in[x],out[x],1);
    print(max(ans[i],ssol.all_prod().second));
  }
}