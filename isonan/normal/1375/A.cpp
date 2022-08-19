#include <cstdio>

int n,T,a[101];
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i),a[i]=((a[i]<0)?a[i]:-a[i]);
		for(int i=1;i<=n;i++){
			printf("%d ",(i&1)?a[i]:-a[i]);
		}
		putchar('\n');
	}
}