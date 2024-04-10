#include<stdio.h>
int r,c;
int main(){
	scanf("%d%d",&r,&c);
	if(r==1&&c==1){
		puts("0");
		return 0;
	}
	if(r==1||c==1){
		int tot=1;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				printf("%d%c",++tot,j==c? '\n':' ');
		return 0;
	}
	for(int i=1;i<=r;i++) 
		for(int j=1;j<=c;j++)
			printf("%d%c",(r+j)*i,j==c? '\n':' ');
	return 0;
}