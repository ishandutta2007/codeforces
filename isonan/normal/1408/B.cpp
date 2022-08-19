#include <cstdio>

int T,n,k,a[101];
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d%d",&n,&k);
		int cnt=0;
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		for(int i=2;i<=n;i++)cnt+=(a[i]!=a[i-1]);
//		if(!a[1])--k;
		if(!cnt)puts("1");
		else if(k==1){
			puts("-1");
		}
		else printf("%d\n",(cnt-1)/(k-1)+1);
	}
}