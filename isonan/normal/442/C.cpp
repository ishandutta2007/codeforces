#include <cstdio>
#include <algorithm>

using std::min;

int stk[500001],top,n;
long long ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1,tem;i<=n;i++){
		scanf("%d",&tem);
		while(top>1&&stk[top]<=min(stk[top-1],tem))
			ans+=min(stk[top-1],tem),--top;
		stk[++top]=tem;
	}
	for(int i=2;i<top;i++)ans+=min(stk[i-1],stk[i+1]);
	printf("%I64d\n",ans);
}