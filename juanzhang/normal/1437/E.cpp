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
int n,k,A[maxn],B[maxn];

bool af;
int ans,tot,dat[maxn],vis[maxn];

void run(){
  int L=dat[1],R=dat[tot];
  if(L>R)return af=1,void();
  rep(i,1,tot)vis[i]=0;
  rep(i,2,tot-1)if(dat[i]<L||dat[i]>R){
    vis[i]=1,ans++;
  }
  static int len,arr[maxn];
  len=0;
  int cnt=0;
  rep(i,0,tot)arr[i]=0;
  rep(i,1,tot)if(!vis[i]){
    int pos=upper_bound(arr+1,arr+len+1,dat[i])-arr;
    if(pos>len)++len;
    arr[pos]=dat[i];
    cnt++;
  }
  ans+=cnt-len;
}

void solve() {
  cin>>n>>k;
  rep(i,1,n)A[i]=read()-i+n;
  rep(i,1,k)B[i]=read();
  B[k+1]=n+1,A[n+1]=1e9+n+1;
  rep(i,1,k+1){
    tot=0;
    rep(j,B[i-1],B[i])dat[++tot]=A[j];
    run();
  }
  cout<<(af?-1:ans)<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}