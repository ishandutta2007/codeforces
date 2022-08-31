#include <cstdio>

int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;(i<<1)<=n;i++){
		int l=1,r=m;
		for(int j=1;j<=(m<<1);j++){
			if(j%2)printf("%d %d\n",i,l),++l;
			else printf("%d %d\n",(n-i+1),r),--r;
		}
	}
	if(n&1){
		int l=1,r=m;
		for(int i=1;i<=m;i++){
			if(i%2)printf("%d %d\n",(n+1)>>1,l),++l;
			else printf("%d %d\n",(n+1)>>1,r),--r;
		}
	}
}