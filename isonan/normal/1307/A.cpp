#include <cstdio>

int t,n,d,a[1001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d",&n,&d);
		int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
			while(a[i]&&d){
				if(d>=i-1){
					d-=i-1,--a[i],++ans;
				}
				else break;
			}
		}
		printf("%d\n",ans);
	}
}