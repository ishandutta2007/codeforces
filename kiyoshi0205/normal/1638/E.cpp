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
#define uniq(v) vsort(v),(v).erase(unique(all(v)),(v).end())
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
template <typename T=ll>
struct BinaryIndexedTree{
  int size,bitn=0;
  T I;
  using func=function<T(T,T)>;
  func F;
  vector<T> tree;
  BinaryIndexedTree(int N,T e,func f):size(N+1),I(e),F(f),tree(size,e){}
  BinaryIndexedTree(int N):size(N+1),I(0),F([](T a,T b){return a+b;}),tree(size,0){}
  void act(int i,T x){
    for(++i;i<size;i+=-i&i){
      tree[i]=F(tree[i],x);
    }
  }
  //return F([0,i]);
  T query(int i){
    T res=I;
    for(++i;i>0;i-=-i&i){
      res=F(tree[i],res);
    }
    return res;
  }
  //sum([l,r));
  T sum(int l,int r){
    // if(--l>--r)return 0;
    assert(--l<=--r);
    if(l<0)return query(r);
    else return query(r)-query(l);
  }
  //only(N,+)
  int lower_bound(int x){
    int i=0;
    if(!bitn){
      i=size;bitn=1;
      while(i){
        i>>=1;bitn<<=1;
      }
      i=0;
    }
    for(int k=bitn;k;k>>=1){
      if(i+k<size&&tree[i+k]<x){
        i+=k;
        x-=tree[i];
      }
    }
    return i;
  }
};


int N,Q;
//(t,t)
vector<pair<int,ll>> valchange[1000000];
//index
vector<int> printev[1000000];
//(,)
vector<pair<int,ll>> ans;
//indexorevent(t,c):tindexc
vector<pair<int,int>> insertev[1000000];
vector<int>eraseev[1000000];
int main(){
  startupcpp();
  cin>>N>>Q;
  for(int c=0;c<N;++c)valchange[c].emplace_back(0,0);

  for(int t=1;t<=Q;++t){
    string s;
    cin>>s;
    if(s=="Color"){
      int l,r,c;
      cin>>l>>r>>c;
      --c;
      insertev[--l].emplace_back(t,c);
      eraseev[--r].emplace_back(t);
    }
    if(s=="Add"){
      int c,x;
      cin>>c>>x;
      auto& v=valchange[--c];
      v.emplace_back(t,v.back().second+x);
    }
    if(s=="Query"){
      int i;
      cin>>i;
      printev[--i].emplace_back(t);
    }
  }

  //
  map<int,int> mp;
  mp[0]=0;

  BinaryIndexedTree BIT(Q+1);
  vec BITval(Q+1,0);
  BITval[0]=valchange[0].back().second;
  BIT.act(0,BITval[0]);

  for(int i=0;i<N;++i){
    for(auto[t,c]:insertev[i]){
      auto itr=mp.emplace(t,c).first;
      assert(itr!=mp.begin());
      auto preitr=prev(itr);
      {
        //[preitr->first,t)preitr->secondx
        auto& v=valchange[preitr->second];
        ll x=prev(upper_bound(all(v),pair<int,ll>(t-1,inf)))->second;
        if(preitr->first)x-=prev(upper_bound(all(v),pair<int,ll>(preitr->first-1,inf)))->second;
        BIT.act(preitr->first,x-BITval[preitr->first]);
        BITval[preitr->first]=x;
      }
      int nxtt=Q+1;
      if(++itr!=mp.end())nxtt=itr->first;
      {
        //[t,nxtt)cx
        auto& v=valchange[c];
        ll x=prev(upper_bound(all(v),pair<int,ll>(nxtt-1,inf)))->second;
        x-=prev(upper_bound(all(v),pair<int,ll>(t-1,inf)))->second;
        BIT.act(t,x-BITval[t]);
        BITval[t]=x;
      }
    }
    for(auto t:printev[i]){
      auto itr=prev(mp.upper_bound(t));
      auto [bft,c]=*itr;
      ll res=BIT.query(bft-1);
      auto& v=valchange[c];
      res+=prev(upper_bound(all(v),pair<int,ll>(t,inf)))->second;
      if(bft)res-=prev(upper_bound(all(v),pair<int,ll>(bft-1,inf)))->second;
      ans.emplace_back(t,res);
    }
    for(auto t:eraseev[i]){
      auto itr=mp.find(t);
      assert(itr!=mp.end());
      BIT.act(t,-BITval[t]);
      BITval[t]=0;
      itr=mp.erase(itr);
      auto preitr=prev(itr);
      int nxtt=itr==mp.end()?Q+1:itr->first;
      {
        //[preitr->first,nxtt)preitr->secondx
        auto& v=valchange[preitr->second];
        ll x=prev(upper_bound(all(v),pair<int,ll>(nxtt-1,inf)))->second;
        if(preitr->first)x-=prev(upper_bound(all(v),pair<int,ll>(preitr->first-1,inf)))->second;
        BIT.act(preitr->first,x-BITval[preitr->first]);
        BITval[preitr->first]=x;
      }
    }
  }

  vsort(ans);
  for(auto x:ans)print(x.second);
}