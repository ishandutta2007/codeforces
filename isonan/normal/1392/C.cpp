#include <cstdio>

int t,n,a[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		long long cnt=0;
		for(int i=n;i;i--){
			a[i]-=a[i-1];
			if(a[i]<0)cnt+=-a[i];
		}
		printf("%lld\n",cnt);
	}
}