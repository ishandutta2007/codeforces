#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

namespace GTR {
	const int bufl = 1 << 15;
	char buf[bufl], *s = buf, *t = buf;
	inline int fetch() {
		if (s == t) { t = (s = buf) + fread(buf, 1, bufl, stdin); if (s == t) return EOF; }
		return *s++;
	}
	inline int read() {
		int a = 0, b = 1, c = fetch();
		while (c < 48 || c > 57) b ^= c == '-', c = fetch();
		while (c >= 48 && c <= 57) a = a * 10 + (c ^ 48), c = fetch();
		return b ? a : -a;
	}
} using GTR::read;

const int maxn=1e6+10,P=1e9+7;
int n,A[maxn],pw2[maxn],cnt[maxn];bool orz[maxn];

int fac[maxn],ifac[maxn],inv[maxn],pre[maxn],val1[maxn],val2[maxn],val[maxn];

int qp(int a,int k){
  int res=1;
  for(;k;k>>=1,a=1ll*a*a%P)if(k&1)res=1ll*res*a%P;
  return res;
}
int binom(int n,int m){
  return n<m?0:1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}

int main(){
  fac[0]=ifac[0]=inv[1]=fac[1]=ifac[1]=1;
  rep(i,2,maxn-1)fac[i]=1ll*fac[i-1]*i%P,inv[i]=1ll*(P-P/i)*inv[P%i]%P,ifac[i]=1ll*inv[i]*ifac[i-1]%P;
  n=read();
  rep(i,0,n)pre[i]=((i?pre[i-1]:0)+binom(n+1,i))%P;
  rep(i,1,n)val1[i]=(pre[i]-2ll*binom(n-1,i-1)%P+P-binom(n,i)+P)*qp(4,P-2)%P;
  rep(i,1,n)val2[i]=(pre[i]-2ll*binom(n-1,n-i)%P+P-binom(n,n-i)+P)*qp(4,P-2)%P;
  reverse(val2+1,val2+n+1);
  rep(i,1,n)(val1[i]+=val1[i-1])%=P,(val2[i]+=val2[i-1])%=P,val[i]=(val1[i]-val2[i]+P)%P;
  pw2[0]=1;rep(i,1,maxn-1)pw2[i]=2*pw2[i-1]%P;
  rep(i,1,n)A[i]=read(),cnt[A[i]]++;
  int ans=0;
  rep(i,2,1000000)if(!orz[i]){
    int buk[30];
    memset(buk,0,sizeof buk);
    for(int j=i;j<=1000000;j+=i){
      orz[j]=1;
      int x=cnt[j];
      if(x){
        int t=j,ct=0;
        while(t%i==0)t/=i,ct++;
        buk[ct]+=x;
      }
    }
    buk[0]=n;
    rep(i,1,20)buk[0]-=buk[i];
    if(buk[0]==n)continue;
    int cur=0;
    rep(i,0,20){
      ans=(ans+1ll*(val[cur+buk[i]]-val[cur]+P)*i)%P,cur+=buk[i];
    }
  }
  cout<<ans<<endl;
  return 0;
}