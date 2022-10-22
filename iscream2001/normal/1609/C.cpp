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

bool not_pri[N+10];
int cntp=0;
int pri[N];

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
	for(int i=2;i<=N;++i){
		if(!not_pri[i]){
			pri[++cntp]=i;
		}
		for(int j=1;j<=cntp&&i*pri[j]<=N;++j){
			not_pri[i*pri[j]]=1;
			if(i%pri[j]==0){
				break;
			}
		}
	}
	return;
}
set<int> S;
set<int>::iterator it;
int n,m;
LL a[N],b[N];
int R[N];
void MAIN(){
	int x,y,z;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	LL ans=0;
	for(int i=n;i>=1;--i){
		if(i+m<=n) {
			R[i]=R[i+m];
			b[i]=b[i+m]*a[i];
		}
		else {
			R[i]=i;
			b[i]=a[i];
		}
		while(b[i]>1000000){
			b[i]/=a[R[i]];
			R[i]-=m;
		}
		while(R[i]>i&&not_pri[b[i]]){
			b[i]/=a[R[i]];
			R[i]-=m;
		}
		if(not_pri[b[i]]==0){
			ans+=(R[i]-i)/m;
		}
	}
	for(int i=n;i>=1;--i){
		if(i+m<=n) {
			R[i]=R[i+m];
			b[i]=b[i+m]*a[i];
		}
		else {
			R[i]=i;
			b[i]=a[i];
		}
		while(b[i]>1000000){
			b[i]/=a[R[i]];
			R[i]-=m;
		}
		while(R[i]>i&&b[i]!=1){
			b[i]/=a[R[i]];
			R[i]-=m;
		}
		if(b[i]==1){
			ans-=(R[i]-i)/m;
		}
	}
	printf("%lld\n",ans);
	return;
}
int main(){
	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--){
		MAIN();
	}
    return 0;
}