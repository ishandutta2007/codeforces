#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
LL qpow(LL x,LL y,LL P){
	LL re=1;
	x=x%P;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}

const int N=1e6+10;
const double eps=1e-6;
const LL sed=1e9+7;
const LL P=998244353;
const LL INF=2e18;

LL fac[N+10],inv[N+10];
LL bin[70];
void init(){
	bin[0]=1;
	for(int i=1;i<=60;++i){
		bin[i]=bin[i-1]<<1;
	}
	fac[0]=fac[1]=inv[0]=inv[1]=1;
	for(LL i=2;i<=N;++i){
		fac[i]=fac[i-1]*i%P;
	}
	inv[N]=qpow(fac[N],P-2,P);
	for(LL i=N;i>1;--i){
		inv[i-1]=inv[i]*i%P;
	}
	return;
}
set<int> S;
set<int>::iterator it;
int n,m;
LL a[20];

void MAIN(){
	scanf("%d",&n);
	LL res=1;
	for(int i=1;i<=n;++i) {
		scanf("%lld",&a[i]);
		while(a[i]%2==0){
			res<<=1;
			a[i]/=2;
		}
	}
	sort(a+1,a+1+n);
	a[n]*=res;
	LL ans=0;
	for(int i=1;i<=n;++i){
		ans+=a[i];
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	int ttt=1;scanf("%d",&ttt);
	while(ttt--){
		MAIN();
	}
    return 0;
}