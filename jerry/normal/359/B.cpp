#include <cstdio>
int n, k;
int main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		if(i<k)
			printf("%d %d ",i*2+2,i*2+1);
		else
			printf("%d %d ",i*2+1,i*2+2);
	}
}