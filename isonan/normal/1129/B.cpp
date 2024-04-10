#include <cstdio>

int n,k;
int main(){
	scanf("%d",&k);
	printf("%d\n",2000);
	printf("-1 ");
	int tot=k+2000;
	for(int i=2;i<=2000;i++){
		if(tot>=1000000)printf("1000000 "),tot-=1000000;
		else printf("%d ",tot),tot=0;
	}
}