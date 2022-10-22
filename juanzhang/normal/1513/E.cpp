#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=2e5+10,P=1e9+7;
int n,A[maxn];map<int,int>cnt;

int qp(int a,int k){int res=1;for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;return res;}
int inv[maxn],fac[maxn],ifac[maxn];
int binom(int n,int m){return n<m?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;}
void init(){
  fac[0]=ifac[0]=inv[1]=fac[1]=ifac[1]=1;
  rep(i,2,maxn-1)inv[i]=1ll*(P-P/i)*inv[P%i]%P,fac[i]=1ll*i*fac[i-1]%P,ifac[i]=1ll*inv[i]*ifac[i-1]%P;
}

int main(){
  init();
  long long su=0;
  cin>>n;rep(i,1,n)scanf("%d",A+i),su+=A[i];
  if(su%n!=0)return puts("0"),0;
  int ct0=0,ct1=0,ct2=0,re=1;
  rep(i,1,n){
    A[i]-=su/n;
    re=1ll*re*(++cnt[A[i]])%P;
    ct0+=A[i]==0,ct1+=A[i]>0,ct2+=A[i]<0;
  }
  re=qp(re,P-2);
  int tp=1ll*binom(n,ct0)*fac[ct0]%P;
  n-=ct0;
  if(ct2<ct1)swap(ct1,ct2);
  if(ct1<=1){
    cout<<1ll*tp*binom(n,ct1)%P*fac[ct2]%P*re%P<<endl;return 0;
  }
  cout<<2ll*tp%P*re%P*fac[ct1]%P*fac[ct2]%P<<endl;
  return 0;
}