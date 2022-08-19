#include <cstdio>
#include <algorithm>
 
int n,a[111];
int main(){
	int tem=0,tot=0;
	scanf("%d",&n);
	tot=tem;
	int x=0;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		tot+=a[i];
		if(a[i]<=(a[1]>>1))x+=a[i];
	}
	x+=a[1];
	if(x>(tot>>1)){
		int cnt=1;
		for(int i=2;i<=n;i++)if(a[i]<=(a[1]>>1))++cnt;
		printf("%d\n",cnt);
		for(int i=1;i<=n;i++)if(a[i]<=(a[1]>>1)||i==1)printf("%d ",i);
		return 0;
	}
	else printf("0");
}