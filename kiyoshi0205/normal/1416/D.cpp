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
template<class T,class E> ostream& operator<<(ostream& os,pair<T,E>& p){return os<<"{"<<p.first<<","<<p.second<<"}";}
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}
struct unionfind{
  private:
  int maxN;
  vector<int> par,treesize;
  public:unionfind(int N) :maxN(N),par(N),treesize(N,1){
    for(int i=0;i<maxN;++i)par[i]=i;
  }
  int root(int x){
    while(par[x]!=x){
      x=par[x]=par[par[x]];
    }
    return x;
  }
  bool unite(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return false;
    // if(treesize[x]>treesize[y])swap(x,y);
    par[x]=y;
    treesize[y]+=treesize[x];
    return true;
  }
  bool parcheck(int x,int y){
    return root(x)==root(y);
  }
  int size(int x){
    return treesize[root(x)];
  }
  void clear(){
    treesize.assign(maxN,1);
    for(int i=0;i<maxN;++i)par[i]=i;
  }
  vector<vector<int>> groups(){
    vector<vector<int>> res(maxN);
    for(int i=0;i<maxN;++i)res[root(i)].eb(i);
    return res;
    vector<vector<int>> res2;
    for(vector<int> x:res){
      if(x.size())res2.eb(x);
    }
    return res2;
  }
};
template<typename T> struct segtree{
private:
  int N=1;
  T E;
  using func=function<T(T,T)>;
  func f,g;
  vector<T> tree;
public:
  segtree(vector<T>& v,T e,func Merge,func Act):E(e),f(Merge),g(Act){
    int i,K=v.size();
    while(N<K)N<<=1;
    tree.resize(N<<1);
    For(i,N,N+K)tree[i]=v[i-N];
    For(i,N+K,N<<1)tree[i]=E;
    brep1(i,N)tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
  }
  segtree(vector<T>& v,T e,func Merge){*this=segtree(v,e,Merge,Merge);};
  segtree(int N,T e,func F){
    vector<T> res(N,e);
    *this=segtree(res,e,F);
  }
  void action(int i,T a){
    if((i<0)|(i>=N))return;
    i+=N;
    tree[i]=g(tree[i],a);
    while(i>1){
      i>>=1;
      tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
    }
  }
  void input(int i,T a){
    if((i<0)|(i>=N))return;
    tree[i+=N]=a;
    while(i>1){
      i>>=1;
      tree[i]=f(tree[i<<1],tree[(i<<1)|1]);
    }
  }
  T queli(int a,int b){
    if((a>=b)|(a<0)|(b<=0)|(a>=N)|(b>N))return E;
    T l(E),r(E);
    for(a+=N,b+=N;a<b;a>>=1,b>>=1){
      if(a&1)l=f(l,tree[a++]);
      if(b&1)r=f(tree[--b],r);
    }
    return f(l,r);
  }
};
mat tree;
vec p;
pvec range,seg;
void dfs(ll now){
  if(range[now].first>=0)return;
  range[now].first=seg.size();
  seg.eb(p[now],range[now].first);
  for(auto x:tree[now])dfs(x);
  range[now].second=seg.size();
}
int main(){
  startupcpp();
  // int codeforces;cin>>codeforces;while(codeforces--){
  ll i,j,a,b,N,M,Q;
  cin>>N>>M>>Q;
  p.resize(N*2-1,0);
  tree.resize(N*2-1);
  range.resize(N*2-1,datas(-1,0));
  rep(i,N)cin>>p[i];
  pvec edge(M),queri(Q);
  set<ll> se;
  rep(i,M){
    cin>>a>>b;
    --a;--b;
    edge[i]=datas(a,b);
    se.insert(i);
  }
  rep(i,Q){
    cin>>a>>b;
    --b;
    queri[i]=datas(a,b);
    if(a==2)se.erase(b);
  }
  unionfind uni(N*2-1);
  j=N;
  // output(se);
  // output(edge);
  for(auto x:se){
    a=uni.root(edge[x].first);
    b=uni.root(edge[x].second);
    if(a!=b){
      tree[j].eb(a);
      tree[j].eb(b);
      uni.unite(edge[x].first,j);
      uni.unite(edge[x].second,j);
      ++j;
    }
  }
  brep(i,Q){
    if(queri[i].first==1)queri[i].second=uni.root(queri[i].second);
    else{
      a=uni.root(edge[queri[i].second].first);
      b=uni.root(edge[queri[i].second].second);
      if(a!=b){
        tree[j].eb(a);
        tree[j].eb(b);
        uni.unite(edge[queri[i].second].first,j);
        uni.unite(edge[queri[i].second].second,j);
        ++j;
      }
    }
  }
  rep(i,N){
    if(uni.parcheck(i,0))continue;
    a=uni.root(i);
    b=uni.root(0);
    tree[j].eb(a);
    tree[j].eb(b);
    uni.unite(a,j);
    uni.unite(b,j);
    ++j;
  }
  // matoutput(tree);
  dfs(--j);
  segtree<datas> rmq(seg,datas(0,0),[](datas a,datas b){return max(a,b);});
  for(auto x:queri){
    if(x.first==2)continue;
    auto ans=rmq.queli(range[x.second].first,range[x.second].second);
    print(ans.first);
    rmq.input(ans.second,datas(0,ans.second));
  }
  // }
}