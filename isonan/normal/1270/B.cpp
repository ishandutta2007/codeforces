#include <cstdio>

int t,n,a[200001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		int mx=0x7f7f7f7f,p=0;
		bool cando=0;
		for(int i=1;i<=n;i++){
			if(mx<=a[i]-i-1){
				printf("YES\n%d %d\n",p,i);
				cando=1;
				break;
			}
			if(mx>a[i]-i)mx=a[i]-i,p=i;
		}
		if(cando)continue;
		mx=0,p=0;
		for(int i=1;i<=n;i++){
			if(mx>=a[i]+i+1){
				printf("YES\n%d %d\n",p,i);
				cando=1;
				break;
			}
			if(mx<a[i]+i)mx=a[i]+i,p=i;
		}
		if(!cando)puts("NO");
	}
}