#include <cstdio>

int t,n,a[300001],stk[300001],top;
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",a+i);
		top=0;
		for(int i=1;i<=n;i++){
			while(top>1&&stk[top-1]<a[i])--top;
			if(!top||stk[top]>a[i])stk[++top]=a[i];
		}
		if(top<=1)puts("YES");
		else puts("NO");
	}
}