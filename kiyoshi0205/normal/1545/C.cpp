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
// constexpr ll mod=1000000007;
constexpr int mod=998244353;
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


set<int> se[500][500];
int N,A,ans,g[1000][500];
bool vis[1000],ch[500][500];
int main(){
  startupcpp();
  int codeforces;cin>>codeforces;while(codeforces--){
  int i,j;
  cin>>N;
  rep(i,N*2){
    rep(j,N){
      cin>>g[i][j];
      se[j][--g[i][j]].emplace(i);
    }
  }
  ans=0;A=1;
  queue<int> que;
  rep(i,N){
    rep(j,N){
      if(se[i][j].size()==1){
        que.emplace(*se[i][j].begin());
      }
      ch[i][j]=false;
    }
  }
  while(ans<N){
    while(!que.empty()){
      auto x=que.front();que.pop();
      if(vis[x])continue;
      vis[x]=true;
      ++ans;
      rep(i,N){
        se[i][g[x][i]].erase(x);
        ch[i][g[x][i]]=true;
      }
      rep(i,N){
        for(auto& y:se[i][g[x][i]]){
          rep(j,N){
            if(i==j)continue;
            auto& s=se[j][g[y][j]];
            s.erase(y);
            if(s.size()==1&&!ch[j][g[y][j]])que.emplace(*s.begin());
          }
        }
        se[i][g[x][i]].clear();
      }
    }
    if(ans<N){
      A*=2;
      if(A>=mod)A-=mod;
      rep(i,N)if(se[0][i].size()){
        que.emplace(*se[0][i].begin());
        break;
      }
    }
  }
  print(A);
  rep(i,N*2){
    if(vis[i]){
      cout<<i+1<<"\n "[--ans>0];
      vis[i]=false;
    }
  }
}
}