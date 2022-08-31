#include <cstdio>
#include <algorithm>
#include <vector>

int n,top,num[10001];
std::pair<int,int>swap[100001];
int main(){
	scanf("%d",&n);
	if(n%4==2||n%4==3){
		puts("NO");
		return 0;
	}
	puts("YES");
	if(n==1)return 0;
	for(;;){
		if(n==4){
			printf("1 2\n1 3\n2 4\n1 4\n2 3\n3 4\n");
			return 0;
		}
		if(n==5){
			printf("1 2\n1 3\n1 4\n2 3\n2 5\n3 5\n1 5\n3 4\n2 4\n4 5\n");
			return 0;
		}
		for(int i=n-4;i;i--)printf("%d %d\n",i,n);
		printf("%d %d\n",n-1,n);
		for(int i=1;i<=n-4;i++)printf("%d %d\n",i,n-1);
		printf("%d %d\n",n-2,n);
		printf("%d %d\n",n-3,n-1);
		printf("%d %d\n",n-2,n-1);
		printf("%d %d\n",n-3,n);
		for(int i=n-4;i;i--)printf("%d %d\n",i,n-2);
		printf("%d %d\n",n-3,n-2);
		for(int i=1;i<=n-4;i++)printf("%d %d\n",i,n-3);
		n-=4;
	}
}