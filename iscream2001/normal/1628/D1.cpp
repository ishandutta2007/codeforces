#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;x%=P;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=3e5+10;
const LL INF=1e18;

LL fac[1000005],finv[1000005];

LL C(LL x,LL y){
	if(x<y) return 0;
	return fac[x]*finv[y]%P*finv[x-y]%P;
}

void init(){
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(LL i=2;i<=1000000;++i) fac[i]=fac[i-1]*i%P;
	finv[1000000]=qpow(fac[1000000],P-2,P);
	for(LL i=1000000;i>1;--i) finv[i-1]=finv[i]*i%P;
}
LL n,m,K;
void MAIN(){
	scanf("%lld%lld%lld",&n,&m,&K);
	n-=m;
	if(n==0) {
		printf("%lld\n",m*K%P);
		return;
	}
	if(m==0){
		printf("%lld\n",(LL)0);
		return;
	}
	LL ans=0,now=1;
	for(LL i=1;i<=m;++i){
		now=(now+now)%P;
		ans+=now*i%P*C(n+m-i-1,m-i)%P;
	}
	ans=ans%P*K%P*qpow(qpow((LL)2,P-2,P),n+m,P)%P;
	printf("%lld\n",ans);
	return;
}
/*
*/
int main(){
	//cout<<qpow((LL)16,P-2,P)*(LL)150%P<<endl;
    init();
    int ttt=1;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}