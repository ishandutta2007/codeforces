#include<stdio.h>
 
char a,b,arr[5][2];
 
int main(){
	scanf("%c%c\n", &a,&b);
	for(int i=0;i<5;i++){
		scanf("%c%c ", &arr[i][0],&arr[i][1]);
		if(arr[i][0]==a || arr[i][1]==b){
			printf("YES");
			return 0;
		}
	}
	printf("NO");
	return 0;
}