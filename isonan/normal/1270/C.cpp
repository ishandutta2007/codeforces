#include <cstdio>

long long n,a[100001],t;
int main(){
	scanf("%lld",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%lld",&n);
		long long sum=0;
		long long sum2=0;
		long long a=(1ll<<59ll),b;
		for(int i=1;i<=n;i++)scanf("%lld",::a+i),sum^=::a[i],sum2+=::a[i];
		if(sum2%2==1)a++;
		sum^=a;
		sum2+=a;
		b=((sum<<1ll)-sum2)>>1ll;
		printf("3\n%lld %lld %lld\n",a,b,b);
	}
}