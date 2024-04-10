#include <cstdio>

int t;
int n,a[1001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",a+i);
		}
		printf("%d\n",(n>>1)*6);
		for(int i=1;i<=(n>>1);++i){
			printf("2 %d %d\n",i,n-i+1);
			printf("1 %d %d\n",i,n-i+1);
			printf("2 %d %d\n",i,n-i+1);
			printf("2 %d %d\n",i,n-i+1);
			printf("1 %d %d\n",i,n-i+1);
			printf("2 %d %d\n",i,n-i+1);
		}
	}
}