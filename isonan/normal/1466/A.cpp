#include <cstdio>
#include <cstring>
#include <algorithm>

int t,n,x[101],stk[100001];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d",&n);
		int top=0;
		for(int i=1;i<=n;i++)scanf("%d",x+i);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				stk[++top]=x[j]-x[i];
		std::sort(stk+1,stk+top+1);
		top=std::unique(stk+1,stk+top+1)-stk-1;
		printf("%d\n",top);
	}
}