#include <cstdio>

int t,n,a[101];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		if(n==1){
			puts("T");
			continue;
		}
		else{
			int mx=0,sum=0;
			for(int i=1;i<=n;i++){
				sum+=a[i];
				if(a[mx]<a[i])mx=i;
			}
			if((a[mx]<<1)>sum)puts("T");
			else{
				if(sum%2)puts("T");
				else puts("HL");
			}
		}
	}
}