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
const int maxn=2e5+10,P=1e9+7;
char L[maxn],R[maxn];
int N,A[maxn];
int pw2[maxn],pw10[maxn],nu4[maxn],nu7[maxn],su[maxn],val[maxn];

int calc(){
  int res=0,cur=0,lst=0;
  rep(i,1,N){
    if(A[i]==7){
      cur=(cur+4ll*pw10[N-i])%P;
      int t=(2ll*su[N-i]-(nu4[N-i]+nu7[N-i])%P+P)%P;
      res=(res+1ll*lst*(cur+nu4[N-i])%P+val[N-i]+1ll*cur*cur%P*(pw2[N-i]+P-1)%P+1ll*cur*t%P)%P;
      lst=(cur+nu7[N-i])%P;
      cur=(cur-4ll*pw10[N-i]%P+P)%P;
    }
    cur=(cur+1ll*A[i]*pw10[N-i])%P;
  }
  res=(res+1ll*lst*cur)%P;
  return res;
}

void solve() {
  scanf("%s %s",L+1,R+1),N=strlen(L+1);
  pw2[0]=pw10[0]=1;
  rep(i,1,maxn-1){
    pw2[i]=2ll*pw2[i-1]%P;
    pw10[i]=10ll*pw10[i-1]%P;
    nu4[i]=(10ll*nu4[i-1]+4)%P;
    nu7[i]=(10ll*nu7[i-1]+7)%P;
  }
  su[1]=11,val[1]=28;
  rep(i,2,100010){
    su[i]=(11ll*pw2[i-1]%P*pw10[i-1]%P+2ll*su[i-1])%P;
    int t=(2ll*su[i-1]-(nu4[i-1]+nu7[i-1])%P+P)%P;
    int v4=(16ll*pw10[i+i-2]%P*(pw2[i-1]+P-1)%P+4ll*pw10[i-1]%P*t%P)%P;
    int v7=(49ll*pw10[i+i-2]%P*(pw2[i-1]+P-1)%P+7ll*pw10[i-1]%P*t%P)%P;
    val[i]=(2ll*val[i-1]+v4+v7+1ll*(4ll*pw10[i-1]+nu7[i-1])%P*(7ll*pw10[i-1]+nu4[i-1])%P)%P;
  }
  rep(i,1,N)A[i]=L[i]-48;
  int lll=calc();
  rep(i,1,N)A[i]=R[i]-48;
  int rrr=calc();
  printf("%d\n",(rrr-lll+P)%P);
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}