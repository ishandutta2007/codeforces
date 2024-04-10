#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read() {
  #define nc getchar()
  int x=0;char c=nc;
  while(c<48)c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int maxn=1010;
int n,A[maxn],ct[maxn];

void solve() {
  cin>>n;
  rep(i,0,n-1)A[i]=read();
  vi vec;
  rep(T,1,2*n){
    memset(ct,0,sizeof ct);
    int now=0;
    rep(i,0,n-1){
      ct[A[i]]++;
      while(ct[now])now++;
    }
    if(now==n){
      rep(i,0,n-1)if(A[i]!=i){
        A[i]=now,vec.push_back(i+1);break;
      }
    }else{
      A[now]=now,vec.push_back(now+1);
    }
  }
  printf("%d\n",(int)vec.size());for(int x:vec)printf("%d ",x);puts("");
}

signed main() {
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}