#include <cstdio>

int n,p;
int main(){
	scanf("%d%d",&n,&p);
	n+=p;
	for(int i=0;i<=32;i++){
		n-=p;
		if(n>=0&&n>=i&&__builtin_popcount(n)<=i){
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
}