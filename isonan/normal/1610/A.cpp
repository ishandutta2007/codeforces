#include <cstdio>

int t;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		int n,m;
		scanf("%d%d",&n,&m);
		if(n==1&&m==1)puts("0");
		else if(n==1||m==1)puts("1");
		else puts("2");
	}
}