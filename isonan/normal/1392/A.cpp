#include <cstdio>

int t,n,a[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		bool cando=1;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=1;i<n;i++)if(a[i]!=a[i+1])cando=0;
		if(!cando)puts("1");
		else printf("%d\n",n);
	}
}