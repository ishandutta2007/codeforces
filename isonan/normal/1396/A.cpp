#include <cstdio>
#define int long long

int n;
long long a[100001],x[100001],y[100001];
signed main(){
	scanf("%lld",&n);
	if(n==1){
		scanf("%lld",a+1);
		printf("1 1\n%lld\n",-a[1]);
		printf("1 1\n%lld\n",0ll);
		printf("1 1\n%lld\n",0ll);
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",a+i);
		x[i]=1ll*(a[i]%(n-1))*n;
		y[i]=(a[i]-x[i]);
	}
	printf("%lld %lld\n",1ll,n);
	for(int i=1;i<=n;i++)printf("%lld ",-x[i]);putchar('\n');
	printf("%lld %lld\n",1ll,n-1ll);
	for(int i=1;i<n;i++)printf("%lld ",-y[i]);putchar('\n');
	printf("%lld %lld\n",2ll,n);
	for(int i=1;i<n-1;i++)printf("0 ");printf("%lld ",-y[n]);putchar('\n');
	return 0;
}