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
const int maxn=1.5e5+10;
int n1,n2,n3,n4,A[maxn],B[maxn],C[maxn],D[maxn],dp[maxn];

#define mid ((l+r)>>1)
#define lson k<<1,l,mid
#define rson k<<1|1,mid+1,r

int val[maxn<<2];
void build(int k,int l,int r){
  if(l==r)return val[k]=dp[l],void();
  build(lson),build(rson),val[k]=min(val[k<<1],val[k<<1|1]);
}
int query(int k,int l,int r,int ql,int qr){
  if(ql>qr)return 1.1e9;
  if(ql<=l&&r<=qr)return val[k];
  if(qr<=mid)return query(lson,ql,qr);
  if(ql>mid)return query(rson,ql,qr);
  return min(query(lson,ql,qr),query(rson,ql,qr));
}

#undef mid
#undef lson
#undef rson

vi E[maxn];
void run(int n1,int n2){
  static int ano[maxn];
  memset(ano,0x3f,sizeof ano);
  int m=read();
  rep(i,1,n2)E[i].clear();
  rep(i,1,m){
    int u=read(),v=read();E[v].push_back(u);
  }
  build(1,1,n1);
  rep(i,1,n2){
    sort(E[i].begin(),E[i].end());
    int lst=0;E[i].push_back(n1+1);
    for(int x:E[i]){
      if(lst<x-1){
        chkmin(ano[i],query(1,1,n1,lst+1,x-1));
      }
      lst=x;
    }
  }
  memcpy(dp,ano,sizeof dp);
}

void solve(){
  cin>>n1>>n2>>n3>>n4;
  rep(i,1,n1)dp[i]=A[i]=read();rep(i,1,n2)B[i]=read();rep(i,1,n3)C[i]=read();rep(i,1,n4)D[i]=read();
  run(n1,n2);rep(i,1,n2)dp[i]+=B[i];
  run(n2,n3);rep(i,1,n3)dp[i]+=C[i];
  run(n3,n4);rep(i,1,n4)dp[i]+=D[i];
  int mn=1e9;
  rep(i,1,n4)chkmin(mn,dp[i]);
  printf("%d\n",mn>=(int)1e9?-1:mn);
}

signed main(){
//  int T=read();
//  while(T--)solve();
  solve();
  return 0;
}