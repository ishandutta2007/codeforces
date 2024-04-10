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
int mp[50][50];
void MAIN(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=100000;++i) fac[i]=fac[i-1]*i%P;
//	finv[100000]=qpow(fac[100000],P-2,P);
//	for(LL i=100000;i>1;--i) finv[i-1]=finv[i]*i%P;
	
	scanf("%d%d",&n,&K);
	if(K+K-1>n){
		puts("-1");
	} 
	else{
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=K;++i){
			mp[i+i-1][i+i-1]=1;
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				putchar(mp[i][j]?'R':'.');
			}
			puts("");
		}
	}
	//printf("%lld\n",ans);
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