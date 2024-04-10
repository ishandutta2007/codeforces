#include <cstdio>
#include <cmath>

int t,n;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		if(n&1){
			puts("NO");
			continue;
		}
		while(n%2==0)n/=2;
		int x=(int)sqrt(n);
		if(x*x==n){
			puts("YES");
		}
		else puts("NO");
	}
}