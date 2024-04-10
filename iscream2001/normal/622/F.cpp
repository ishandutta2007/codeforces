#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=1e6+10;

void init(){
}

LL n,K;

bool not_pri[N+10];
int pri[N];
int cntp;
LL mi[N+10];

void init_pri(){
	int www;
	cntp=0;mi[1]=1;
	for(int i=2;i<N;++i){
		if(!not_pri[i]){
			pri[++cntp]=i;
			mi[i]=qpow((LL)i,K,P);
		}
		for(int j=1;(www=i*pri[j])<=N;++j){
			not_pri[www]=1;
			mi[www]=mi[i]*mi[pri[j]]%P;
			if(i%pri[j]==0){
				break;
			}
			else{
			}
		}
	}
}

LL fac[N+10],finv[N+10];

void MAIN(){
	fac[0]=fac[1]=finv[0]=finv[1]=1;
	for(LL i=1;i<=N;++i) fac[i]=fac[i-1]*i%P;
	finv[N]=qpow(fac[N],P-2,P);
	for(LL i=N;i>1;--i) finv[i-1]=finv[i]*i%P;
	scanf("%lld%lld",&n,&K);
	init_pri();
	mi[0]=0;
	for(int i=1;i<=K+1;++i){
		mi[i]+=mi[i-1];
		if(mi[i]>=P) mi[i]-=P;
	}
	if(n<=K+1) {
		printf("%lld\n",mi[n]);
		return;
	}
	LL re,hhh=1,ans=0;
	for(LL i=0;i<=K+1;++i){
	//	cout<<mi[i]<<" ";
		hhh=hhh*(n-i)%P;
	//	cout<<mi[i]<<endl;
	}//cout<<endl;
//	cout<<hhh<<endl;
	for(LL i=0;i<=K+1;++i){
		re=mi[i]*hhh%P*qpow(n-i,P-2,P)%P;
//		cout<<mi[i]*hhh%P*qpow(n-i,P-2,P)%P<<endl;
		if((K+1-i)&1){re=-re;}
		re=re*finv[i]%P*finv[K+1-i]%P;
//		cout<<mi[i]<<" "<<re<<endl;
		ans+=re;
	}
	ans=(ans%P+P)%P;
	printf("%lld\n",ans);
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;//scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}