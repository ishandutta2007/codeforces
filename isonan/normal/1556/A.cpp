#include <cstdio>

int t;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		int c,d;
		scanf("%d%d",&c,&d);
		if((c+d)&1){
			puts("-1");
			continue;
		}
		if(!c&&!d)puts("0");
		else if(c==d)puts("1");
		else puts("2");
	}
}