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
typedef vector<int>vi;
typedef pair<int,int>pii;
const int maxn=1e5+10;
int su[maxn][26];char str[maxn];

void solve(){
  int n,q;
  scanf("%d%d%s",&n,&q,str+1);
  rep(i,1,n){
    rep(c,0,25){
      su[i][c]=su[i-1][c]+(str[i]=='a'+c);
    }
  }
  while(q--){
    int l=read(),r=read();
    int ans=0;
    rep(i,0,25){
      int x=su[r][i]-su[l-1][i];
      ans+=x*i+x;
    }
    printf("%d\n",ans);
  }
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}