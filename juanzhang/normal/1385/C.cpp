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
const int maxn=2e5+10;
int n,A[maxn];

void solve() {
  cin>>n;
  rep(i,1,n)A[i]=read();
  int pos=n;
  while(pos>1&&A[pos-1]>=A[pos])pos--;
  int pp=pos;
  while(pp>1&&A[pp-1]<=A[pp])pp--;
  printf("%d\n",pp-1);
}

signed main() {
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}