#include <cstdio>

int t;
int n,a[16];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		int cnt=0;
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
			while(a[i]%2==0)a[i]/=2,++cnt;
		}
		long long p=0,sum=0;
		for(int i=1;i<=n;++i){
			sum+=a[i];
			if(p<a[i])p=a[i];
		}
		sum-=p;
		for(int i=1;i<=cnt;++i)p*=2;
		printf("%lld\n",sum+p);
	}
}