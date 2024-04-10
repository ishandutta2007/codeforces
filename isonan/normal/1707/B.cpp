#include <cstdio>
#include <algorithm>

int t,n,a[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;++fd){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		int cnt=0;
		for(;n>1;){
			int top=0;
			int Old=a[1];
			for(int i=1;i<n;++i){
				a[++top]=a[i+1]-a[i];
			}
			if(cnt)a[++top]=Old,--cnt;
			std::sort(a+1,a+top+1);
			int p=0;
			for(int i=1;i<=top;++i)if(!a[i])p=i;
			top-=p;cnt+=p;
			for(int i=1;i<=top;++i)a[i]=a[i+p];
			n=top;
			// for(int i=1;i<=n;++i)printf("%d ",a[i]);putchar('\n');
		}
		if(!n)puts("0");
		else printf("%d\n",a[1]);
	}
}