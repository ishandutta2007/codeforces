#include <cstdio>
#include <algorithm>

int n,T,z,a[100001];
int main(){
	scanf("%d",&T);
	for(int fd=1;fd<=T;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		int tot=0;
		for(int i=1;i<=n;++i){
			tot+=(a[i]!=0);
			if(i>1)tot-=((a[i]!=0)&&(a[i-1]!=0));
		}
		printf("%d\n",std::min(tot,2));
	}
}