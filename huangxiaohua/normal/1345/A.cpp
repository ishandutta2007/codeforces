#include<stdio.h>
int i,n,a,b;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&a,&b);
		if(a==1|b==1|(a==2&b==2)){
			printf("YES\n");
		}
		else{printf("NO\n");
		}
	}
}