#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+10;
const LL P=1e9+7;
LL gcd(LL a,LL b) {
    return b?gcd(b,a%b):a;
}
LL qpow(LL x,LL y){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
int n;
LL bin[70];
LL a[N];
LL b[70],bn[70],bb[70];
int main(){
	bin[0]=1;for(int i=1;i<=60;++i) bin[i]=bin[i-1]<<1;
	int T,u,v;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		for(int j=0;j<=60;++j) b[j]=0;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=60;++j){
				if(a[i]&bin[j]){
					++b[j];
				}
			}
		}
		for(int j=0;j<=60;++j) {
			bn[j]=bin[j]%P*(LL)n%P;
			bb[j]=bin[j]%P*(LL)b[j]%P;
		}
		
		LL ans=0,res,A,L,R;
		for(int i=1;i<=n;++i){
			L=0;
			for(int j=0;j<=60;++j){
				if(a[i]&bin[j]){
					L+=bb[j];
				}
			}
			L=L%P;
			R=0;
			for(int j=0;j<=60;++j){
				if(a[i]&bin[j]){
					R+=bn[j];
				}
				else{
					R+=bb[j];
				}
			}
			R=R%P;
			ans+=L*R%P;
		}
		ans=(ans%P+P)%P; 
		printf("%lld\n",ans);
	}
	
	return 0;
}