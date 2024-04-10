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
const int maxn=1e5+10;
int n,m,ct[3],buk[3][maxn];ll su[3][maxn];

int tot;
struct node{
  int w,c;
}A[maxn];
int pr[maxn*3];
ll get(int k,int m){
  return k<=ct[0]?su[0][min(ct[0],k+(m-k)%2)]+su[1][min(ct[1],(m-k)/2)]:0;
}
ll calc(int vsz){
  int x=pr[vsz];
  ll res=max(get(x,vsz),get(x+1,vsz));
  if(x>0)chkmax(res,get(x-1,vsz));
  if(vsz>=ct[0])chkmax(res,su[0][ct[0]]+su[1][min(ct[1],(vsz-ct[0])/2)]);
  if(vsz>=ct[1]*2)chkmax(res,su[1][ct[1]]+su[0][min(ct[0],vsz-2*ct[1])]);
  return res;
}

void solve() {
  cin>>n>>m;
  rep(i,1,n){
    int w=read(),c=read();buk[w-1][++ct[w-1]]=c;if(w<=2)A[++tot]={w,c};
  }
  sort(A+1,A+tot+1,[](node P,node Q){
    int x=P.c*Q.w,y=Q.c*P.w;
    return x>y||(x==y&&P.w<Q.w);
  });
  int cur=0;
  rep(i,1,tot)pr[cur+A[i].w]=A[i].w==1,cur+=A[i].w;
  rep(i,1,m)pr[i]+=pr[i-1];
  rep(i,0,2)sort(buk[i]+1,buk[i]+ct[i]+1,greater<int>());
  rep(i,0,2)rep(j,1,ct[i])su[i][j]=su[i][j-1]+buk[i][j];
  ll ans=0;
  rep(i,0,m/3)chkmax(ans,su[2][min(ct[2],i)]+calc(m-3*i));
  cout<<ans<<endl;
}

signed main() {
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}