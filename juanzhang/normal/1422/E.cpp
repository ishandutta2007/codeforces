#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)
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
const int maxn=1e5+10;
int n,top,chk[maxn],st[maxn];char str[maxn],lst[maxn];

void solve() {
  scanf("%s",str+1),n=strlen(str+1);
  per(i,n,1){
    if(top&&st[top]==i+1&&str[st[top]]==str[i]&&lst[top]<=str[i]){
      chk[i]=st[top--];
    }else{
      lst[top+1]=str[st[top]]!=str[i]?str[st[top]]:lst[top];
      st[++top]=i;
    }
  }
  rep(i,1,n){
    printf("%d ",top);
    if(top<=10){
      per(j,top,1)putchar(str[st[j]]);puts("");
    }else{
      per(j,top,top-4)putchar(str[st[j]]);
      printf("...");putchar(str[st[2]]);putchar(str[st[1]]);puts("");
    }
    if(chk[i])st[++top]=chk[i];
    else top--;
  }
}

signed main() {
//  int T=read();
//  while(T--)solve();
  return solve(),0;
}