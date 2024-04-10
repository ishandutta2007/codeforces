#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
typedef pair <int, int> pii;
const int maxn=1e5+10;
int n,k,A[maxn],tmp[maxn],ans[maxn];
char str[maxn];

void solve() {
  scanf("%s %d",str+1,&k);
  n=strlen(str+1);
  rep(i,1,n)ans[i]=1,tmp[i]=0;
  rep(i,1,n){
    A[i]=str[i]-'0';
    if(str[i]=='0'){
      if(i>k)ans[i-k]=0;
      if(i<=n-k)ans[i+k]=0;
    }
  }
  rep(i,k+1,n)if(ans[i])tmp[i-k]=1;
  rep(i,1,n-k)if(ans[i])tmp[i+k]=1;
  rep(i,1,n)if(tmp[i]!=A[i]){
    return puts("-1"),void();
  }
  rep(i,1,n)putchar(ans[i]|48);
  puts("");
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}