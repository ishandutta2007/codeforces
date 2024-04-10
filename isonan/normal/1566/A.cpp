#include <cstdio>

int t;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		int n,s;
		scanf("%d%d",&n,&s);
		printf("%d\n",s/(n-((n+1)>>1)+1));
	}
}