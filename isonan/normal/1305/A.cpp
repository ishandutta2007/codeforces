#include <cstdio>
#include <algorithm>

int n,a[1001],t,b[1001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=1;i<=n;i++)scanf("%d",b+i);
		std::sort(a+1,a+n+1);
		std::sort(b+1,b+n+1);
		for(int i=1;i<=n;i++)printf("%d ",a[i]);putchar('\n');
		for(int i=1;i<=n;i++)printf("%d ",b[i]);putchar('\n');
	}
}