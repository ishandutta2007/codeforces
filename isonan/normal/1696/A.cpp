#include <cstdio>

int n,T,z,a[2001];
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;++fd){
		scanf("%d",&n);
		scanf("%d",&z);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		int ans=0;
		for(int i=1;i<=n;++i){
			if(ans<(a[i]|z))ans=a[i]|z;
		}
		printf("%d\n",ans);
	}
}