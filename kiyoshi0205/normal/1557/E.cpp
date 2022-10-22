#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<N;++i)
#ifdef DEBUG
void debugg(){cout<<endl;}
template<class T,class... Args>void debugg(const T& x,const Args&... args){cout<<" "<<x;debugg(args...);}
#define debug(...) cout<<__LINE__<<" ["<<#__VA_ARGS__<<"]:",debugg(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif

int x,y,sa;
bool pr(int a,int b){
  x=a;y=b;
  cout<<a+1<<" "<<b+1<<'\n';
  string s;
  cin>>s;
  if(s=="Done")return true;
  if(s[0]=='U')--sa;
  if(s[0]=='D')++sa;
  return false;
}
constexpr bool in(int x){return x>=0&&x<8;}
void solve(){
  sa=x=y=0;
  if(pr(x,y))return;
  rep(firstx,8){
    if(y>0&&pr(x,0))return;
    if(!in(firstx+sa))continue;
    if(x!=firstx+sa&&pr(firstx+sa,0))return;
    rep(i,7){
      if(!in(firstx+sa))break;
      if(pr(firstx+sa,i+1))return;
    }
  }
  assert(false);
}
int main(){
  int t;
  cin>>t;
  while(t--)solve();
}