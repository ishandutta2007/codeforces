#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using ddatas=pair<long double,long double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
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
constexpr ll mod=998244353;
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

template<class S,S(*op)(S,S)> 
struct disjoint_sparse_table{
  vector<vector<S>> treedata;
  disjoint_sparse_table(const vector<S>& v){
    treedata.emplace_back(v);
    size_t sz=v.size();
    for(size_t i=2;i<sz;i<<=1){
      vector<S> tmp;
      tmp.reserve(sz);
      for(size_t j=i;j<sz;j+=i<<1){
        tmp.emplace_back(v[j-1]);
        for(size_t k=2;k<=i;++k)tmp.emplace_back(op(v[j-k],tmp.back()));
        tmp.emplace_back(v[j]);
        const size_t m=min(i,sz-j);
        for(size_t k=1;k<m;++k)tmp.emplace_back(op(tmp.back(),v[j+k]));
      }
      treedata.emplace_back(tmp);
    }
  }
  //[L,R)
  S prod(size_t L,size_t R){
    --R;
    //assert(L<=R&&R<treedata[0].size());
    if(L==R)return treedata[0][L];
    int t=31-__builtin_clz(L^R);
    return op(treedata[t][L^((1<<t)-1)],treedata[t][R]);
  }
};

struct S{
  int l,r,cnt,fl,fr,fm;
};

S op(S L,S R){
  const int l=L.l,r=R.r,fm=L.fm&R.fm;
  int fl=L.fl,fr=R.fr;
  if(L.fm^R.fm){
    if(L.fm){
      fl^=(R.l==7||(R.l==5&&!R.fl));
    }else{
      fr^=(L.r==7||(L.r==5&&!L.fr));
    }
  }
  int cnt=L.cnt+R.cnt;
  int ch=L.r&R.l;
  if(ch!=0)--cnt;
  if(ch==5&&(L.fr|R.fl))--cnt;
  return {l,r,cnt,fl,fr,fm};
}

void solve(){
  int i,N;
  cin>>N;
  string s[3];
  cin>>s[0]>>s[1]>>s[2];
  vector<S> v(N);
  rep(i,N){
    int x=(s[0][i]&1)|(s[1][i]&1)<<1|(s[2][i]&1)<<2;
    v[i].fl=v[i].fr=v[i].fm=0;
    v[i].l=v[i].r=x;
    if(x==0)v[i].cnt=0;
    else if(x==5){
      v[i].cnt=2;
      v[i].fl=v[i].fr=v[i].fm=1;
    }else v[i].cnt=1;
  }
  disjoint_sparse_table<S,op> table(v);
  int Q;
  cin>>Q;
  while(Q--){
    int L,R;
    cin>>L>>R;
    print(table.prod(--L,R).cnt);
  }
}
int main(){
  startupcpp();
  solve();
}