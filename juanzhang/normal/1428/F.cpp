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
const int maxn=5e5+10;
int n,pos[maxn];ll val[maxn];char str[maxn];

void solve() {
  scanf("%d %s",&n,str+1);
  ll ans=0;int len=0;
  rep(i,1,n){
    val[i]=val[i-1];
    if(str[i]=='0'){
      len=0;
      per(j,i-1,1){
        if(str[j]=='0')break;
        pos[i-j]=j;
      }
    }else{
      val[i]+=i-pos[++len];
    }
    ans+=val[i];
  }
  cout<<ans<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}