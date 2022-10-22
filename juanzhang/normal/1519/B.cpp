#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
template<typename T>void chkmax(T&x,T y){if(x<y)x=y;}
template<typename T>void chkmin(T&x,T y){if(x>y)x=y;}
inline int read(){
  #define nc getchar()
  int x=0;char c=nc;bool f=0;
  while(c<48)f|=c=='-',c=nc;
  while(c>47)x=x*10+(c^48),c=nc;
  return f?-x:x;
  #undef nc
}

typedef double db;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pii;

typedef bitset<10010>B;

int L[101][101],R[101][101];

void solve(){
  int n,m,k;
  cin>>n>>m>>k;
  memset(L,0x3f,sizeof L);
  memset(R,-0x3f,sizeof R);
  L[1][1]=R[1][1]=0;
  rep(i,1,n)rep(j,1,m){
    if(i<n)chkmin(L[i+1][j],L[i][j]+j),chkmax(R[i+1][j],R[i][j]+j);
    if(j<m)chkmin(L[i][j+1],L[i][j]+i),chkmax(R[i][j+1],R[i][j]+i);
  }
  puts(L[n][m]<=k&&k<=R[n][m]?"YES":"NO");
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}