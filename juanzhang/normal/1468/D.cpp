#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  bool f=0;int x=0;char c=nc;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=2e5+10;
int N,m,S,T,A[maxn];

void solve(){
  cin>>N>>m>>S>>T;
  rep(i,1,m){
    A[i]=read();
  }
  sort(A+1,A+m+1);
  if(S>T){
    S=N-S+1;
    T=N-T+1;
  }
  int tim=T-S-1,res=0;
  per(i,m,1){
    if(!tim)break;
    if(tim+S-1>=A[i]){
      tim--,res++;
    }
  }
  printf("%d\n",res);
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}