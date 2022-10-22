#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)
//mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
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
const int maxn=5010,P=1e9+7;
void Add(int&x,int y){x+=y;if(x>=P)x-=P;}
int Inc(int x,int y){return x+y<P?x+y:x+y-P;}
int n,A[maxn],f[maxn][maxn],sufs[maxn][maxn],lcp[maxn][maxn];short g[maxn][maxn],sufm[maxn][maxn];char str[maxn];

void solve() {
  scanf("%s",str+1),n=strlen(str+1);rep(i,1,n)A[i]=str[i]-'0';
  per(i,n,1)per(j,n,1)lcp[i][j]=A[i]==A[j]?1+lcp[i+1][j+1]:0;
  memset(g,0x3f,sizeof g);
  rep(i,1,n){
    f[i][1]=g[i][1]=1;
    for(int j=i;j>=2;j--)if(A[j]){
      int k=j+j-i-1;
      if(k>=1&&k<=j-1){
        int p=k+lcp[k][j],q=j+lcp[k][j];
        if(q<=i&&A[p]>A[q])k++;
      }
      chkmax(k,1),chkmin(k,j-1);
      f[i][j]=sufs[j-1][k],g[i][j]=sufm[j-1][k]+1;
//      rep(k,max(1,j+j-i-1),j-1)if(A[k]&&g[j-1][k]<P){
//        if(j-1-k+1==i-j+1){
//          int p=k,q=j;bool flg=1;
//          while(q<=i){
//            if(A[p]!=A[q]){
//              flg=A[p]<A[q];break;
//            }
//            p++,q++;
//          }
//          if(!flg)continue;
//        }
//        Add(f[i][j],f[j-1][k]),chkmin(g[i][j],g[j-1][k]+1);
//      }
////      printf("(%d %d) %d %d\n",i,j,f[i][j],g[i][j]);
    }
    per(j,i,1)sufs[i][j]=Inc(sufs[i][j+1],f[i][j]),sufm[i][j]=min(j==i?(short)32001:sufm[i][j+1],g[i][j]);
  }
  int ans1=-1,ans2=0;
  rep(i,1,n)Add(ans2,f[n][i]);
  rep(i,max(1,n-12),n)if(g[n][i]<=n){
    int num=0;
    rep(j,i,n)num=num*2+A[j];
    num+=g[n][i];
    if(ans1==-1||ans1>num)ans1=num;
  }
  if(ans1==-1){
    per(i,n-13,1)if(g[n][i]<=n){
      int num=0;
      rep(j,i,n)num=(num*2+A[j])%P;
      ans1=(num+g[n][i])%P;
      break;
    }
  }
  printf("%d\n%d\n",ans2,ans1);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}