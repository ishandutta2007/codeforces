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

void solve() {
  int a,b,c;
  cin>>a>>b>>c;
  int A[3];
  A[0]=a,A[1]=b,A[2]=c;
  sort(A,A+3);
  if(A[0]!=A[1]&&A[1]!=A[2])return puts("NO"),void();
  if(A[0]==A[1]&&A[1]!=A[2])return puts("NO"),void();
  puts("YES");
  cout<<min(a,b)<<' '<<min(a,c)<<' '<<min(b,c)<<endl;
}

signed main() {
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}