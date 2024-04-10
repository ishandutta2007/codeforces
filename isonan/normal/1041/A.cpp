#include <cstdio>

int n,tem,mx,mn=2000000000;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&tem);
		if(tem>mx)mx=tem;
		if(tem<mn)mn=tem;
	}
	printf("%d\n",mx-mn+1-n);
}