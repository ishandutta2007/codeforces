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
char str[1010];int A[1010];

void solve(){
  scanf("%s",str+1);
  int n=strlen(str+1);
  bool flg=1;
  rep(i,1,n)A[i]=str[i]-'A';
  rep(i,3,n){
    flg&=A[i]==(A[i-1]+A[i-2])%26;
  }
  puts(flg?"YES":"NO");
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}