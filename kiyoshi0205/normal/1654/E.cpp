#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
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
unsigned int N,a[100001],ch[100001],ans=2;
void solve(){
  for(unsigned int i=0;i<N;++i){
    unsigned int j=i>=334?i-334:0,cnt=0;
    while(j<i){
      if(a[j]>=a[i]&&(a[j]-a[i])%(i-j)==0)ch[cnt++]=(a[j]-a[i])/(i-j);
      ++j;
    }
    const unsigned int K=cnt;
    sort(ch,ch+K);
    cnt=2;
    for(unsigned int j=1;j<K;++j){
      if(ch[j]==ch[j-1]){
        if(++cnt>ans)ans=cnt;
      }else cnt=2;
    }
  }
  for(unsigned int d=0;d<=300;++d){
    for(unsigned int i=0;i<N;++i)ch[i]=a[i]+d*i;
    sort(ch,ch+N);
    unsigned int cnt=1;
    for(unsigned int j=1;j<N;++j){
      if(ch[j]==ch[j-1]){
        if(++cnt>ans)ans=cnt;
      }else cnt=1;
    }
  }
}
int main(){
  startupcpp();
  cin>>N;
  if(N<=2){
    cout<<0<<'\n';
    return 0;
  }
  for(unsigned int i=0;i<N;++i)cin>>a[i];
  solve();
  reverse(a,a+N);
  solve();
  cout<<N-ans<<'\n';
}