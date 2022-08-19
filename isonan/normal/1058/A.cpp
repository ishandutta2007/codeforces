#include <cstdio>

int n,tem;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tem);
		if(tem==1){
			puts("HARD");
			return 0;
		}
	}
	puts("EASY");
	return 0;
}