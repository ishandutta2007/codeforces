#include <cstdio>

int n,t;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		if(n==1)puts("-1");
		else{
			for(int i=1;i<=n-2;i++){
				putchar('7');
			}
			putchar('2');
			putchar('7');
			putchar('\n');
		}
	}
}