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
int n,A[10100],ans[101];

void solve(){
  int k;
  cin>>n>>k;
  int su=0;
  rep(i,1,n)A[i]=read(),su+=A[i],ans[i]=A[i];
  if(su==k){
    return puts("NO"),void();
  }
  srand(time(0));
  rep(T,1,100){
    random_shuffle(ans+1,ans+n+1);
    int t=0;bool flg=1;
    rep(i,1,n){
      if((t+=ans[i])==k){
        flg=0;break;
      }
    }
    if(flg){
      puts("YES");
      rep(i,1,n)printf("%d%c",ans[i],"\n "[i<n]);
      return ;
    }
  }
  puts("NO");
}

signed main(){
  int T=read();
  while(T--)solve();
//  solve();
  return 0;
}