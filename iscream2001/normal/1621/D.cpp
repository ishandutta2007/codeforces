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
void init(){
}

int n,K,m;
LL a[505][505];
void MAIN(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=100000;++i) fac[i]=fac[i-1]*i%P;
//	finv[100000]=qpow(fac[100000],P-2,P);
//	for(LL i=100000;i>1;--i) finv[i-1]=finv[i]*i%P;
	
	scanf("%d",&n);
	for(int i=1;i<=n+n;++i){
		for(int j=1;j<=n+n;++j){
			scanf("%lld",&a[i][j]);
		}
	}
	LL now=0,ans=INF,hhh;
	for(int i=n+1;i<=n+n;++i){
		for(int j=n+1;j<=n+n;++j){
			now+=a[i][j];
		}
	}
	ans=min(ans,min(now+a[n][n+1],now+a[n+1][n]));
	ans=min(ans,min(now+a[1][n+1],now+a[n+1][1]));
	ans=min(ans,min(now+a[n][n+n],now+a[n+n][n]));
	ans=min(ans,min(now+a[1][n+n],now+a[n+n][1]));
	printf("%lld\n",ans);
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}