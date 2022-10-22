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
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define endl "\n"
#define eb emplace_back
#define print(x) cout<<x<<endl
#define printyes print("Yes")
#define printno print("No")
#define printYES print("YES")
#define printNO print("NO")
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
const ll mod=1000000007;
// const ll mod=998244353;
const ll inf=1LL<<60;
const double PI=acos(-1);
const double eps=1e-9;
template<class T,class E> ostream& operator<<(ostream& os,const pair<T,E>& p){return os<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& os,const vector<T>& v){
  os<<"{";ll i;
  rep(i,v.size()){
    if(i)os<<",";
    os<<v[i];
  }
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
template<class S,S(*op)(S,S),S(*e)()>struct segtree{
public:
  segtree():segtree(0){}
  segtree(int n):segtree(vector<S>(n,e())){}
  segtree(const vector<S>& v):_n(int(v.size())){
    log=0;
    while((1U<<log)<(unsigned int)(_n))++log;
    size=1<<log;
    d=vector<S>(size<<1,e());
    for(int i=0;i<_n;++i)d[size+i]=v[i];
    for(int i=size-1;i>=1;--i)update(i);
  }

  void set(int p,S x){
    assert(0<=p&&p<_n);
    p+=size;
    d[p]=x;
    for(int i=1;i<=log;++i)update(p>>i);
  }

  S get(int p){
    assert(0<=p&&p<_n);
    return d[p+size];
  }

  S prod(int l,int r){
    assert(0<=l&&l<=r&&r<=_n);
    S sml=e(),smr=e();
    l+=size;
    r+=size;

    while(l<r){
      if(l&1)sml=op(sml,d[l++]);
      if(r&1)smr=op(d[--r],smr);
      l>>=1;
      r>>=1;
    }
    return op(sml,smr);
  }

  S all_prod(){return d[1];}

  template<bool(*f)(S)>int max_right(int l){
    return max_right(l,[](S x){return f(x);});
  }
  template<class F>int max_right(int l,F f){
    assert(0<=l&&l<=_n);
    assert(f(e()));
    if(l==_n)return _n;
    l+=size;
    S sm=e();
    do{
      while(~l&1)l>>=1;
      if(!f(op(sm,d[l]))){
        while(l<size){
          l<<=1;
          if(f(op(sm,d[l]))){
            sm=op(sm,d[l++]);
          }
        }
        return l-size;
      }
      sm=op(sm,d[l++]);
    }while((l&-l)!=l);
    return _n;
  }

  template<bool(*f)(S)>int min_left(int r){
    return min_left(r,[](S x){return f(x);});
  }
  template<class F>int min_left(int r,F f){
    assert(0<=r&&r<=_n);
    assert(f(e()));
    if(r==0)return 0;
    r+=size;
    S sm=e();
    do{
      --r;
      while(r>1&&(r&1))r>>=1;
      if(!f(op(d[r],sm))){
        while(r<size){
          r=r<<1|1;
          if(f(op(d[r],sm))){
            sm=op(d[r--],sm);
          }
        }
        return r+1-size;
      }
      sm=op(d[r],sm);
    }while((r&-r)!=r);
    return 0;
  }

private:
  int _n,size,log;
  vector<S> d;

  void update(int k){d[k]=op(d[k<<1],d[k<<1|1]);}
};

ll segmin(ll a,ll b){return min(a,b);}ll segmine(){return inf;}

int main(){
  startupcpp();
  int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j,k,N;
  cin>>N;
  vec a(N);
  rep(i,N)cin>>a[i];
  j=*max_element(all(a));
  
  vec f;
  rep(i,N)if(a[i]==j)f.eb(i);
  if(f.size()>=3){
    printYES;
    print(f[1]<<" 1 "<<N-f[1]-1);
    continue;
  }

  segtree<ll,segmin,segmine> tree(a);
  vec l(f[0],a[0]),r(N-f.back()-1,a.back());
  rep1(i,l.size())chmax(l[i],max(l[i-1],a[i]));
  rep1(i,r.size())chmax(r[i],max(r[i-1],a[N-i-1]));
  debug(l,r);
  
  l.eb(inf);r.eb(inf);
  i=j=0;
  bool fffff=1;
  while(i<(ll)l.size()-1&&j<(ll)r.size()-1){
    if(l[i]<r[j]){
      ++i;
    }else if(l[i]>r[j]){
      ++j;
    }else{
      ll lx=1,rx=1;
      while(l[i]==l[i+lx])++lx;
      while(r[j]==r[j+rx])++rx;
      rep(k,lx)if(tree.prod(i+lx-k,N-j-rx)<l[i])break;
      if(k&&tree.prod(i+lx-k+1,N-j-rx)==l[i]){
        printYES;
        print(i+lx-k+1<<" "<<(N-j-rx)-(i+lx-k+1)<<" "<<j+rx);
        fffff=0;
        break;
      }
      rep(k,rx)if(tree.prod(i+lx,N-j-rx+k)<l[i])break;
      if(k&&tree.prod(i+lx,N-j-rx+k-1)==l[i]){
        printYES;
        print(i+lx<<" "<<(N-j-rx+k-1)-(i+lx)<<" "<<j+rx-k+1);
        fffff=0;
        break;
      }
      i+=lx;j+=rx;
    }
  }
  if(fffff)printNO;
}
}