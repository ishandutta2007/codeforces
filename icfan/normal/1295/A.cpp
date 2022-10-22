#include <cstdio>
int main(){
	int t;
	scanf("%d",&t);
	int n;
	while(t--){
		scanf("%d",&n);
		if(n&1){
			putchar('7');
			n-=3;
		}
		while(n){
			if(n==3){
				putchar('7');
				n-=3;
			}
			else{
				putchar('1');
				n-=2;
			}
		}
		puts("");
	}
	return 0;
}