
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

int n,K;
//LL fac[N],finv[N];
//LL C(LL x,LL y){
//	if(x<y) return 0;
//	return fac[x]*finv[y]%P*finv[x-y]%P; 
//}
LL a[N];
LL F[N][3];
void MAIN(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=100000;++i) fac[i]=fac[i-1]*i%P;
//	finv[100000]=qpow(fac[100000],P-2,P);
//	for(LL i=100000;i>1;--i) finv[i-1]=finv[i]*i%P;
	
	scanf("%d",&n);LL x,ans=0;
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&x);
	for(int i=0;i<=n;++i) F[i][0]=F[i][1]=F[i][2]=-INF;
	F[0][0]=0;
	for(int i=1;i<=n;++i){
		a[i]-=x;
		F[i][0]=max(F[i-1][0],max(F[i-1][1],F[i-1][2]));
		F[i][1]=1+F[i-1][0];
		if(i>1){
			if(a[i]+a[i-1]>=0){
				F[i][2]=max(F[i][2],F[i-1][1]+1);
			}
		}
		if(i>2){
			if(a[i]+a[i-1]>=0&&a[i]+a[i-1]+a[i-2]>=0){
				F[i][2]=max(F[i][2],F[i-1][2]+1);
			}
		}
		ans=max(ans,max(F[i][1],F[i][2]));
	}
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