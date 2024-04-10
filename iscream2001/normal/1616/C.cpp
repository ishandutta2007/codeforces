
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
const LL INF=2e18;
void init(){
}

int n,K;
//LL fac[N],finv[N];
//LL C(LL x,LL y){
//	if(x<y) return 0;
//	return fac[x]*finv[y]%P*finv[x-y]%P; 
//}
LL a[N];

void MAIN(){
//	fac[0]=fac[1]=finv[0]=finv[1]=1;
//	for(LL i=2;i<=100000;++i) fac[i]=fac[i-1]*i%P;
//	finv[100000]=qpow(fac[100000],P-2,P);
//	for(LL i=100000;i>1;--i) finv[i-1]=finv[i]*i%P;
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	if(n==1){
		puts("0");
		return;
	}
	LL u,d,v,ans=0,num;
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			u=a[j]-a[i];
			d=j-i;
			num=0;
			for(int k=1;k<=n;++k){
				v=k-i;
				if((a[k]-a[i])*d==u*v){
					++num;
				}
			}
			ans=max(ans,num);
		}
	}
	printf("%lld\n",(LL)n-ans);
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