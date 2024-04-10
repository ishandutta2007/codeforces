#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=10010,P=1e9+7;
int n,A[maxn],ans[maxn],F[maxn],G[maxn],pre[maxn],val[maxn];

int main(){
  cin>>n,pre[1]=1;
  rep(i,2,n)cin>>A[i],pre[i]=1ll*A[i]*pre[i-1]%P;
  F[0]=1,G[0]=1;
  per(i,n-1,1){
//    memset(G,0,sizeof G);
    memset(val,0,sizeof val);
//    rep(k,0,(n-i)*2){
//      rep(j,0,k){
//        G[k]=(G[k]+1ll*F[j]*F[k-j])%P;
//      }
//    }
    per(j,n,1)F[j]=1ll*F[j-1]*A[i+1]%P;
//    rep(j,0,(n-i)*2)printf("%d%c",G[j],"\n "[j<jend]);
    rep(k,1,n-i)val[k]=(val[k]+F[k])%P;
    rep(k,2,(n-i)*2){
      val[k]=(val[k]+1ll*A[i+1]*(A[i+1]-1)/2%P*G[k-2])%P;
    }
    rep(j,1,(n-i)*2)ans[j]=(ans[j]+1ll*pre[i]*val[j])%P;
    per(j,(n-i)*2,2)G[j]=1ll*A[i+1]*A[i+1]%P*G[j-2]%P;
    rep(j,2,(n-i)*2)G[j]=(G[j]+2ll*F[j])%P;
    G[1]=2*A[i+1]%P;
  }
  rep(i,1,n*2-2)printf("%d ",ans[i]);
  return 0;
}