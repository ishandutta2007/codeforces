#include<bits/stdc++.h>
int n;
int main(){
	scanf("%d",&n);
	printf("%d\n",n/2);
	if(n&1){
		for(int i=1;i<=n/2-1;++i){
			printf("2 ");
		}
		puts("3");
	}else{
		for(int i=1;i<=n/2;++i){
			printf("2 ");
		}
	}
	return 0;
}