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
#define print(v) cout<<v<<endl
#define printyes cout<<"Yes"<<endl
#define printno cout<<"No"<<endl
#define printYES cout<<"YES"<<endl
#define printNO cout<<"NO"<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
#define matoutput(v) do{for(auto outimat:v)output(outimat);}while(0)
const ll mod=1000000007;
// const ll mod=998244353;
const ll inf=1LL<<60;
const double PI = acos(-1);
const double eps = 1e-9;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}
template <typename T>
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
  T queli(int i){
    T res=I;
    for(++i;i>0;i-=-i&i){
      res=F(tree[i],res);
    }
    return res;
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

 
int main(){
  startupcpp();
  int x,N,Q;
  cin>>N>>Q;
  BinaryIndexedTree<int> tree(1000010);
  while(N--){
    cin>>x;
    tree.act(x,1);
  }
  while(Q--){
    cin>>x;
    if(x>0)tree.act(x,1);
    else{
      tree.act(tree.lower_bound(-x),-1);
    }
  }
  if(tree.queli(1000001)){
    print(tree.lower_bound(1));
  }else{
    print(0);
  }
}