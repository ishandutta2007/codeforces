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
#define double long double
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
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
constexpr double eps=1e-9;
const double PI=acos(-1);
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
template<class T,class E> ostream& operator<<(ostream& os,const map<T,E>& v){
  os<<"{";bool f=false;
  for(auto& x:v){if(f)os<<",";os<<x;f=true;}
  os<<"}";
  return os;
}
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}
#ifdef DEBUG
void debugg(){cout<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cout<<" "<<x;debugg(args...);}
#define debug(...) cout<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif
 
void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
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
ll min(ll a,ll b){return (a>b)?b:a;}
ll lle(){return inf;}
ll mapping(ll a,ll b){return a+b;}
ll composition(ll a,ll b){return a+b;}
ll Fid(){return 0;}
using rmq=lazy_segtree<ll,min,lle,ll,mapping,composition,Fid>;
 
ll solveval;
bool solve(ll x){
  return solveval<x;
}
ll Q,N;
vector<tuple<ll,ll,ll,ll>> queries;
int main(){
  startupcpp();
  ll i;
  cin>>Q;
  queries.reserve(Q);
  vector<ll> idtoval;
  map<ll,ll> idlis;
  rmq tree;
  {
    map<ll,ll> mp;
    mp[inf]=0;
    ll maxval=0;
    rep(i,Q){
      ll a,b,c=0,d=0;
      cin>>a;
      if(a==1){
        cin>>b>>c;
        idtoval.emplace_back(b);
        chmax(maxval,b);
        mp[b]=c;
      }else if(a==2){
        cin>>b;
        mp.erase(b);
      }else{
        cin>>b>>c>>d;
        chmax(maxval,c);
        if(d>0)b=mp.lower_bound(b)->first;
      }
      queries.emplace_back(a,b,c,d);
    }
    idtoval.emplace_back(0);
    idtoval.emplace_back(maxval+1);
    uniq(idtoval);
    N=idtoval.size();
    idlis[N-1]=idlis[0]=0;
    tree=rmq(vec(N,0));
  }
  for(auto [a,b,c,d]:queries){
    if(a==1){
      ll nowid=lower_bound(all(idtoval),b)-idtoval.begin();
      auto nowitr=idlis.emplace(nowid,c).first;
      auto bfitr=prev(nowitr);
      auto nextitr=next(nowitr);
      ll bfval=tree.get(bfitr->first);
      ll nowval=bfval+(b-idtoval[bfitr->first])*bfitr->second;
      ll nextval=nowval+(idtoval[nextitr->first]-b)*c;
      tree.apply(nowid,nextitr->first,nowval-tree.get(nowid));
      tree.apply(nextitr->first,N,nextval-tree.get(nextitr->first));
    }else if(a==2){
      ll nowid=lower_bound(all(idtoval),b)-idtoval.begin();
      auto nowitr=idlis.lower_bound(nowid);
      auto bfitr=prev(nowitr);
      auto nextitr=next(nowitr);
      ll bfval=tree.get(bfitr->first);
      ll nowval=bfval;
      ll nextval=bfval+(idtoval[nextitr->first]-idtoval[bfitr->first])*bfitr->second;
      tree.apply(nowid,nextitr->first,nowval-tree.get(nowid));
      tree.apply(nextitr->first,N,nextval-tree.get(nextitr->first));
      idlis.erase(nowitr);
    }else{
      //a==3
      if(d<=0){
        print(b);
        continue;
      }
      if(b>=c){
        print(-1);
        continue;
      }
      ll nowid=lower_bound(all(idtoval),b)-idtoval.begin();
      solveval=tree.get(nowid)-d;
      auto ritr=idlis.lower_bound(tree.max_right(nowid,solve));
      if(ritr==idlis.end()){
        print(-1);
        continue;
      }
      auto litr=prev(ritr);
      ll lval=tree.get(litr->first)-solveval;
      if((lval-litr->second-1)/(-litr->second)<=c-idtoval[litr->first]){
        print((double)lval/(-litr->second)+idtoval[litr->first]);
      }else{
        print(-1);
      }
    }
  }
}