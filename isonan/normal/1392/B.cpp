#include <cstdio>

int t,n,a[200001];
long long k;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%lld",&n,&k);
		k%=2;
		k+=2;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=1;i<=k;i++){
			int d=-0x7f7f7f7f;
			for(int i=1;i<=n;i++)if(d<a[i])d=a[i];
			for(int i=1;i<=n;i++)a[i]=d-a[i];
		}
		for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
	}
}