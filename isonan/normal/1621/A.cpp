#include <cstdio>

int t,n,k;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d%d",&n,&k);
		if(n>=(k<<1)-1){
			for(int i=1;i<=n;++i,putchar('\n'))
				for(int j=1;j<=n;++j){
					bool bb=0;
					if(i==j){
						if(i&1){
							if(k)--k,bb=1;
						}
					}
					if(bb)putchar('R');
					else putchar('.');
				}
		}
		else puts("-1");
	}
}