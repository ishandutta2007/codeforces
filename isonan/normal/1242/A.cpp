#include <cstdio>

long long n,ans;
long long gcd(long long a,long long b){
	return (!b)?a:gcd(b,a%b);
}
int main(){
	scanf("%I64d",&n);
	for(long long i=1;i*i<=n;i++){
		if(n%i==0){
			if(i>1)ans=gcd(ans,i);
			ans=gcd(ans,n/i);
		}
	}
	printf("%I64d",ans);
}