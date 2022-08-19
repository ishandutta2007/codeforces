#include <cstdio>

long long n;
int T;
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;++fd){
		scanf("%lld",&n);
		if(n%2050){
			puts("-1");
			continue;
		}
		n/=2050;
		int x=0;
		while(n){
			x+=n%10;
			n/=10;
		}
		printf("%d\n",x);
	}
}