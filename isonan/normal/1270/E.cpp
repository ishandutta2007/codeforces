#include <cstdio>
#include <map>

int n;
long long x[1001],y[1001];
long long gcd(long long a,long long b){
	return (!b)?a:gcd(b,a%b);
}
long long abs(long long x){
	return x<0?-x:x;
}
int main(){
	scanf("%d",&n);
	int _gcd=0;
	for(int i=1;i<=n;i++)scanf("%lld%lld",x+i,y+i),_gcd=gcd(_gcd,gcd(abs(x[i]),abs(y[i])));
	for(int i=1;i<=n;i++)x[i]/=_gcd,y[i]/=_gcd;
	for(int mod=2;;){
		int cnt=0;
		for(int i=1;i<=n;i++)if((x[i]+y[i])%mod)++cnt;
		if(cnt==0||cnt==n){
			for(int i=1;i<=n;i++){
				long long tem=(x[i]+y[i])>>1;
				y[i]=(x[i]-y[i])>>1;
				x[i]=tem;
			}
		}
		else{
			printf("%d\n",cnt);
			for(int i=1;i<=n;i++)if((x[i]+y[i])%2)printf("%d ",i);
			putchar('\n');
			return 0;
		}
	}
}